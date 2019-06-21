# Artificial Intelligence First Assignment - Search Strategies

## 15-puzzle
The goal of this assignment was to solve the 15-puzzle using the following search algorithms: breadth first search, depth first search, iterative deepening depth-first search, A* and greedy.

This was one of four assignments required by the Artificial Intelligence course in the Computer Science degree of the Faculty of Sciences of the University of Porto.

Authors:
* Ana Dias (github.com/Ana365Dias)
* João Duarte (github.com/jsilduarte)
* João Neves (github.com/jbfneves)

## How it works
The program takes two input states, one for the initial state and one for the goal state. It starts by evaluating whether it is  possible to reach the goal state from the initial state. If it is, it tries to find a solution and gives you the path to the solution along with the resulting search tree depth for the solution.

The program should accept states in the format:
1 2 3 4 5 6 8 12 13 9 0 7 14 11 10 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0

Some example configurations are:

```
13 11 15 4 8 9 1 5 12 14 0 2 7 10 3 6
13 11 4 5 8 0 14 15 12 1 3 2 7 9 10 6
```
Optimal solution depth: 12.

```
0 9 12 7 14 5 13 2 6 1 4 8 10 15 3 11
9 5 12 7 14 13 0 8 1 3 2 4 6 10 15 11
```
Optimal solution depth: 13.

```
6 12 0 9 14 2 5 11 7 8 4 13 3 10 1 15
14 6 12 9 7 2 5 11 8 4 13 15 3 0 10 1
```
Optimal solution depth: 10.

```
6 0 9 12 14 2 5 11 7 8 4 13 3 10 1 15
14 6 12 9 7 2 5 11 8 4 13 15 3 10 0 1
```
Unsolvable.

## What's missing?
Data structures we won't include right now as they contain code given to us for the purpose of the project.

## What's next?
* Replace those data structures.
* Clean up the code.
* Provide visualization of performance differences between the different methods. 


## Compiler version:
gcc (GCC) 8.2.1

## Compiling and executing
$ gcc -o jogo15 jogo15.c

$ ./jogo15

## File description

* Main files

jogo15.c - main game file

depth.h - depth-first search

breadth.h - breadth-first search

idfs.h - iterative deepening depth-first search

a_star.h - A* search

greedy.h - greedy search

* Structures

matrix.h

heapMin.h

priorityqueue.h
 
queue.h

stack.h
