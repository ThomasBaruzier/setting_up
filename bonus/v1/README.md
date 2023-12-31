# Setting Up

## Description
The "Setting Up" project is a C program that finds the largest possible square on a board while avoiding obstacles. The board can be obtained in two ways: by reading a file passed as the program’s argument or by generating one based on given parameters.

## Features
- Read a file passed as the program’s argument to obtain the board.
- Generate a board based on given parameters (width, height, and pattern).
- Print the board with the largest square represented by "x".
- Handle multiple solutions by choosing the highest square and, if still multiple solutions, choosing the square to the left.

## Project Structure
The project consists of the following files:
- `include/setting.h`: Header file containing function prototypes and macros.
- `src/conv.c`: File containing functions for converting strings to integers and vice versa.
- `src/lib.c`: File containing functions for file operations and error handling.
- `src/main.c`: Main file containing the program's entry point and logic for reading file or generating a board.
- `src/solve.c`: File containing functions for solving the board and finding the largest square.
- `src/str.c`: File containing string manipulation functions.
- `tests/tests.sh`: Shell script for running project tests.

## How to Use
To use the program, follow these steps:
1. Compile the program using the provided makefile: `make fast`.
2. Run the program with the following command:
   - To read a file: `./setting_up <file_path>`
   - To generate a board: `./setting_up <width> <pattern>`
3. The program will print the solved board with the largest square represented by "x".

## Testing
The project includes a shell script `tests/tests.sh` for running tests on the program. The script runs the program with various input files and compares the output with expected results.

## Conclusion
The "Setting Up" project provides a practical implementation of finding the largest square on a board while avoiding obstacles. It demonstrates file operations, string manipulation, error handling, and logic for solving a specific problem. The project can be further extended to include additional features and optimizations.
