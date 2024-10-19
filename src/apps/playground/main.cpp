#include <boost/smart_ptr/scoped_ptr.hpp>
#include <cstdio>
#include <cstring>
#include <stdexcept>

enum class Race { Dinan, Teklan, Ivyn, Moiran, Aidan };

struct ClockOfTheLongNow {
  explicit ClockOfTheLongNow(int year) { this->year = year; }

  ClockOfTheLongNow() { year = 2019; }

  ~ClockOfTheLongNow() { printf("Destructor of ClockOfTheLongNow\n"); }

  void add_year() { year++; }

  bool set_year(int year) {
    if (year < 2019)
      return false;
    this->year = year;
    return true;
  }

  [[nodiscard]] int get_year() const noexcept { return year; }

 private:
  int year;
};

struct Avout {
  Avout(const char* name, int year_of_apert)
      : name(name), apert{year_of_apert} {}

  void announce() const {
    printf("My name is %s and my apert is %d\n", name, apert.get_year());
  }

  const char* name;
  ClockOfTheLongNow apert;
};

struct College {
  char name[256];
};

void print_name(const College* college_ptr) {
  printf("%s\n", college_ptr->name);
}

void print_names(const College* colleges, size_t n_colleges) {
  for (size_t i = 0; i < n_colleges; i++) {
    printf("%s\n", colleges[i].name);
  }
}

struct SimpleString {
  SimpleString(size_t max_size) : max_size{max_size}, length{} {
    if (max_size == 0) {
      throw std::runtime_error{"Max size must be at least 1."};
    }

    this->buffer = new char[max_size];
    this->buffer[0] = 0;
  }

  ~SimpleString() { delete[] buffer; }

  SimpleString(const SimpleString& other) : max_size{other.max_size} {
    this->buffer = new char[max_size];
    std::strncpy(this->buffer, other.buffer, max_size);
    this->length = other.length;
  }

  SimpleString(SimpleString&& other) noexcept
      : max_size{other.max_size}, buffer{other.buffer}, length{other.length} {
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
  }

  SimpleString& operator=(const SimpleString& other) {
    if (this == &other)
      return *this;

    delete[] this->buffer;

    this->max_size = other.max_size;
    this->length = other.length;
    this->buffer = new char[this->max_size];

    std::strncpy(this->buffer, other.buffer, this->max_size);

    return *this;
  }

  SimpleString& operator=(SimpleString&& other) noexcept {
    if (this == &other)
      return *this;

    delete[] this->buffer;

    this->max_size = other.max_size;
    this->length = other.length;
    this->buffer = other.buffer;

    other.max_size = 0;
    other.length = 0;
    other.buffer = nullptr;

    return *this;
  }

  void print(const char* tag) const { printf("%s: %s", tag, buffer); }

  bool append_line(const char* input) {
    const size_t input_length = strlen(input);
    if (input_length + length + 2 > max_size) {
      return false;
    }
    std::strncpy(buffer + length, input, max_size - length);

    length += input_length;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

 private:
  size_t max_size;
  char* buffer;
  size_t length;
};

struct Logger {
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

struct BaseClass {
  virtual const char* final_message() const {
    return "We apologize for the incontinence.";
  }
};

struct DerivedClass : BaseClass {
  const char* final_message() const override {
    return "We apologize for the inconvenience.";
  }
};

void carbon_thaw(const int& encased_solo) {
  auto& solo = const_cast<int&>(encased_solo);
  solo++;
  printf("carbon_thaw: %d\n", solo);
}

template <typename T>
T mean(const T* values, size_t length) {
  T result{};
  for (size_t i = 0; i < length; i++) {
    result += values[i];
  }
  return result / length;
}

template <typename T>
constexpr T sum(T x) {
  return x;
}

template <typename T, typename... Args>
constexpr T sum(T x, Args... args) {
  return x + sum(args...);
}

template <typename... Args>
constexpr auto sum_fold(Args... args) {
  return (... + args);
}

template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
  static_assert(Index < Length, "Index out of bounds");
  return arr[Index];
}

using operation_func = float (*)(float, int);

struct CountIf {
  CountIf(char x) : x{x} {}

  size_t operator()(const char* str) {
    size_t count{};
    for (size_t i = 0; str[i] != 0; i++) {
      if (str[i] == x)
        count++;
    }
    return count;
  }

 private:
  const char x;
};

template <typename Fn, typename T>
void transform(Fn fn, const T* in, T* out, size_t n) {
  for (size_t i = 0; i < n; i++) {
    out[i] = fn(in[i]);
  }
}

struct DeadMenOfDunharrow {

  explicit DeadMenOfDunharrow(const char* message = "") : message{message} {
    oaths_to_fullfill++;
  }

  ~DeadMenOfDunharrow() { oaths_to_fullfill--; }

  const char* message;
  static int oaths_to_fullfill;
};

int DeadMenOfDunharrow::oaths_to_fullfill{0};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

int main(int argc, char** argv) {

  unsigned long maximum = 0;
  unsigned long values[] = {10, 20, 50, 40, 60};

  for (size_t i = 0; i < 5; i++) {
    if (values[i] > maximum)
      maximum = values[i];
  }

  printf("The maximum value is %lu\n", maximum);

  short array[] = {10, 20, 50, 40, 60};
  size_t n_elements = sizeof(array) / sizeof(short);

  Race race = Race::Teklan;
  switch (race) {
    case Race::Dinan:
      printf("You work hard.");
      break;
    case Race::Teklan:
      printf("You are very strong.\n");
      break;
    default:
      printf("You do nothing.");
      break;
  }

  int* my_ptr;
  printf("The value of my_ptr is %p\n", my_ptr);

  int gettysburg{21};
  printf("gettysburg: %d\n", gettysburg);
  int* gettysburg_address = &gettysburg;
  printf("gettysburg_address: %p\n", gettysburg_address);
  printf("The value of gettysburg is %d\n", *gettysburg_address);

  ClockOfTheLongNow clock;
  ClockOfTheLongNow* clock_ptr = &clock;
  clock_ptr->set_year(2020);
  printf("The year is %d\n", clock_ptr->get_year());

  int key_to_the_universe[]{3, 4, 5};
  int* key_ptr = key_to_the_universe;
  printf("The first element is %d\n", *key_ptr);

  College best_colleges[] = {"Magdalen", {"Nuffield"}, {"Kellogg"}};
  print_name(best_colleges);
  print_name(best_colleges + 1);
  print_name(&best_colleges[1]);
  print_names(best_colleges, 3);

  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char* upper_ptr = &upper[0];

  *(lower + 3) = 'd';
  *(upper_ptr + 3) = 'D';

  char letter_d = *(lower + 3);  // lower decays into a pointer when we add
  char letter_D = *(upper_ptr + 3);

  printf("lower: %s\nupper: %s", lower, upper);

  try {
    auto year{2019};                // int
    auto& year_ref = year;          // int&
    const auto& year_cref = year;   // const int&
    auto* year_ptr = &year;         // int*
    const auto* year_cptr = &year;  // const int*
  } catch (...) {
    printf("An exception occurred\n");
  }

  int base[]{1, 2, 3}, a[3], b[3], c[3];

  transform([](int x) { return x * x; }, base, a, 3);
  transform([](int x) { return x + x; }, base, b, 3);
  transform([](int x) { return x / x; }, base, c, 3);

  for (size_t i = 0; i < 3; i++) {
    printf("a[%zu] = %d, b[%zu] = %d, c[%zu] = %d\n", i, a[i], i, b[i], i,
           c[i]);
  }

  char to_count{'s'};
  size_t tally;

  auto s_counter = [to_count, &tally](const char* str) {
    size_t index{}, result{};
    while (str[index]) {
      if (str[index] == to_count)
        result++;
      index++;
    }
    tally += result;
    return result;
  };

  printf("Tally: %zu\n", tally);
  auto sally = s_counter("Sally sells seashells by the seashore.");

  printf("Sally: %zu\n", sally);
  printf("Tally: %zu\n", tally);

  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zu\n", sailor);
  printf("Tally: %zu\n", tally);

  ScopedOathbreakers aragorn{new DeadMenOfDunharrow{"The way is shut."}};
  printf("Oaths to fullfill: %d\n", DeadMenOfDunharrow::oaths_to_fullfill);
  {
    ScopedOathbreakers legolas{
        new DeadMenOfDunharrow{"The dead do not suffer "
                               "the living to pass."}};
    printf("Oaths to fullfill: %d\n", DeadMenOfDunharrow::oaths_to_fullfill);
  }
  printf("Oaths to fullfill: %d\n", DeadMenOfDunharrow::oaths_to_fullfill);

  return 0;
}
