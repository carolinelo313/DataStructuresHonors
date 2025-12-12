# DataStructuresHonors

Honors project for Data Structures  
Author: Caroline Lo
Semester: Spring 2024

---

## Overview

This project implements and tests the following data structures:

- 2D array of linked lists
- Stack ADT

We treat the file input as a 2D grid of characters and use depth-first search (DFS) to find connected objects. Two implementations are provided:

- A recursive DFS
- An iterative DFS using an explicit stack

For each unvisited, non-background cell, DFS explores all reachable cells by checking its four neighbors (up, down, left, right), ignoring diagonals. As each cell in an object is visited, it is marked as counted, and the total size of that object is accumulated. This process is repeated until all objects in the grid have been identified and quantified.

The implementation also makes use of file I/O for reading input grids and careful memory management for allocating and freeing dynamic data structures.

---

## How to Run

Requirements:

- macOS (Apple Silicon, arm64)
- C++ compiler (tested with Apple clang version 16.0.0)
- Terminal to compile and run from the command line

No external libraries are required beyond the C++ standard library.

### Steps

1. Clone the repo:

   ```bash
   git clone https://github.com/carolinelo313/DataStructuresHonors.git
   cd DataStructuresHonors
   
2. Compile:

   clang++ -std=c++17 -Wall -Wextra -o grid main.cpp Matrix.cpp
