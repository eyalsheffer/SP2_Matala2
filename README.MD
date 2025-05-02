# SquareMat Class

This project implements a `SquareMat` class, which represents a square matrix and provides various matrix operations such as addition, subtraction, multiplication, and division.

## Features

- Support for matrix operations:
  - Addition (`+`)
  - Subtraction (`-`)
  - Negation (`-`)
  - Matrix multiplication (`*`)
  - Scalar multiplication (`*`)
  - Modulus (`%`)
  - Division by scalar (`/`)
  - Exponentiation (`^`)
  - Increment (`++`) and Decrement (`--`)
  - Transposition (`~`)
  
- Support for compound assignment operators:
  - `+=`, `-=`, `*=`, `/=`, `%=`

- Comparison operators:
  - `==`, `!=`, `<`, `<=`, `>`, `>=`

- Support for printing matrices with `<<`.

- Matrix can be manipulated with scalar values as well as other matrices.

## Files

- `SquareMat.hpp`: Header file containing the class definition.
- `SquareMat.cpp`: Implementation of the `SquareMat` class.
- `Main.cpp`: Example usage of the `SquareMat` class.
- `test.cpp`: Contains test cases using the [Doctest](https://github.com/onqtam/doctest) framework for unit testing.
- `Makefile`: Build script to compile and run the project.

## How to Build

 Run the following command to compile the project:
   ```bash
   make
   ```

This will build the main application as well as the test executable.
How to Run

To run the main program:

```bash 
./Main
```

To run the tests:
``` bash
make test
```

To check for memory leaks with Valgrind:
``` bash
make valgrind
```