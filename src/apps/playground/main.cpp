#include <cstdio>

enum class Race { Dinan, Teklan, Ivyn, Moiran, Aidan };

struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};

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
      printf("You are very strong.");
      break;
    default:
      printf("You do nothing.");
      break;
  }

  return 0;
}
