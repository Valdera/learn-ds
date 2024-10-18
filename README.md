# Algorithms C++

![C++](https://img.shields.io/badge/C%2B%2B-20%2F23-blue)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Linux Build](https://github.com/Valdera/learn-ds/workflows/Ubuntu%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/Valdera/learn-ds/branch/main/graph/badge.svg)](https://codecov.io/gh/Valdera/learn-ds)

Clone this repository

```bash
git clone --recursive git@github.com:Valdera/Maker.git
```

Initialize `pre-commit`

```bash
pre-commit install
```

## Software Requirements

- CMake 3.16+
- GNU Makefile
- Doxygen
- Conan or VCPKG
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)
- Code Coverage (only on GNU|Clang): lcov, gcovr
- Recommended code editor: [CLion](https://www.jetbrains.com/clion/)

## Project Structure

Project is structured as follows:

``` text
├── CMakeLists.txt
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── src
│   ├── apps
│   │   ├── app1
│       │   ├── CMakesLists.txt
│   │   │   ├── app1.cpp
│   │   │   └── include
│   │   │       └── app1.h
│   │   ├── ...
│   └── libs
│       ├── lib1
│       │   ├── CMakesLists.txt
│       │   ├── lib1.cpp
│       │   └── include
│       │       └── lib1.h
│       ├── ...
└── tests
    ├── apps
    │   ├── app1
    │   │   ├── CMakesLists.txt
    │   │   ├── app1_test.cpp
    │   ├── ...
    └── libs
        ├── lib1
        │   ├── CMakesLists.txt
        │   ├── lib1_test.cpp
        ├── ...
```

Library code goes into [src/](src/), main program code in [app/](app) and tests go in [tests/](tests/).

## Getting Started

### Build Project

Initialize cmake project

```bash
cmake -S <SOURCE PATH> -B <BUILD PATH> -G <GENERATOR> -DCMAKE_BUILD_TYPE=<BUILD TYPE> ..
```

Build project

```bash
cmake --build ./build --target
```
