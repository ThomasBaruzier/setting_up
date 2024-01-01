# Setting Up

## Overview

The Setting Up project is designed to find the largest possible square on a board while avoiding obstacles. The board is represented by a grid of characters where `.` denotes an empty space and `o` denotes an obstacle. The program can read the board from a file or generate one based on given parameters. Once the board is processed, the program prints the board with the largest square marked by replacing some `.` with `x`. The solution prioritizes the highest and leftmost largest square in case of multiple possibilities.

## Implementation Details

### Strategy

The algorithm used to find the largest square is a variant of dynamic programming, where we traverse the board in a systematic way to keep track of potential square borders. We use a set of nodes to represent the current edges of a growing square. These nodes are updated as we move through the board, allowing us to efficiently track and update the largest square found so far.

### Complexity and Efficiency

The time complexity of the algorithm is O(n), where n is the number of cells in the grid. This is because each cell is visited a constant number of times. The space complexity is also O(n), mainly due to the storage of node information.

Here it is in action:
![Stats](https://github.com/ThomasBaruzier/setting_up/blob/main/bonus/stats.png?raw=true)

### Code Structure

The project is divided into several source files, each with a specific purpose:

- `include/setting.h`: Header file containing function prototypes, macros, and constants.
- `src/forward.c`: Contains functions to move the nodes forward and update the edges of the potential square.
- `src/genverif.c`: Handles the generation of the board based on input parameters and verifies the integrity of the map.
- `src/initnodes.c`: Initializes the nodes used to track the edges of the potential largest square.
- `src/main.c`: The main entry point of the program, handling argument parsing and high-level logic.
- `src/read.c`: Functions to read the board from a file.
- `src/solve.c`: Contains the core algorithm to solve the board and find the largest square.
- `src/str.c`: Utility functions for string manipulation.
- `tests/tests.sh`: A shell script to run automated tests.

### Example Execution

Let's take a step-by-step look at how the algorithm works using the example provided:

1. Initial board from `example_file`:

```
....................
.o.....o............
....o...............
................o...
....................
...o.o............o.
....................
..............o.....
....................
....................
```

2. The algorithm initializes nodes to track the edges and starts scanning the board. The nodes are updated as we encounter obstacles:

```
####################
#o#####o#..........#
####o####......###.#
#..###.........#o#.#
#.#####........#####
#.#o#o#..........#o#
#.#####......###.###
#............#o#...#
#............###...#
####################

####################
#o#####o############
####o#####....######
##########....##o###
########......######
###o#o##....######o#
########....########
########....##o#####
####################
####################

####################
#o#####o############
####o###############
###########..###o###
####################
###o#o###..#######o#
#########..#########
##############o#####
####################
####################

####################
#o#####o############
####o###############
################o###
####################
###o#o############o#
####################
##############o#####
####################
####################
```

3. From there, the algorithm marks all the centers of the possible largest square. It will analyze each one of them to find the largest 2x2 area that is the closest to the origin of the board. If no 2x2 area is found, the algorithms falls back to the closest 1x1 spot.
```
####################
#o#####o############
####o###############
###########..###o###
####################
###o#o###x.#######o#
#########..#########
##############o#####
####################
####################
```

4. Finally, it uses the board information to find the coordinates of the square. The solution is found and the solved board is printed.
```
....................
.o.....o............
....o.xxxxxxxx......
......xxxxxxxx..o...
......xxxxxxxx......
...o.oxxxxxxxx....o.
......xxxxxxxx......
......xxxxxxxxo.....
......xxxxxxxx......
......xxxxxxxx......
```

### Running the Program

The program can be executed in two ways:

1. By reading a board from a file:

```
./setting_up example_file
```

2. By generating a board based on given parameters:

```
./setting_up 6 "..o.."
```

### Error Handling

The program includes robust error handling to manage different types of errors, such as file read/write issues, invalid arguments, and memory allocation failures. These are handled gracefully, providing clear error messages to the user.

### Testing

The project includes a shell script `tests/tests.sh` to run automated tests on various input boards. This ensures that the program behaves as expected and can handle a variety of scenarios.

## Conclusion

The Setting Up project showcases an efficient algorithm for finding the largest square on a board with obstacles. The code is structured to be modular, with clear separation of concerns and robust error handling. The use of dynamic programming techniques allows for a solution that is both time and space-efficient. The project is thoroughly tested to ensure reliability and correctness.
