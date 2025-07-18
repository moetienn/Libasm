# Libasm

Libasm is a custom library project that demonstrates low-level programming skills in both Assembly and C. The goal is to re-implement several standard C library functions using x86-64 Assembly language, providing insight into how these fundamental routines work at a lower level.

## Features

- Reimplementation of standard C library functions in Assembly, such as:
  - `strlen`
  - `strcmp`
  - `strcpy`
  - `write`
  - `read`
  - `strdup`
- Test cases in C to validate the Assembly functions.
- Cross-platform compatibility (Linux, macOS).

## Project Structure

- `src/`: Contains the Assembly source files (.s) for each function.
- `inc/`: Includes header files.
- `tests/`: C source files for testing the implemented functions.
- `Makefile`: Automates the build and test process.

## Getting Started

### Prerequisites

- GCC or Clang toolchain
- NASM assembler

### Build

To compile the library and tests, run:

```bash
make
```

### Usage

You can link the generated `libasm.a` static library with your C projects or run the provided test binaries:

```bash
make test
./tests/test_strlen
```
