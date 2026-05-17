*This activity has been created as part of the 42 curriculum by yaaguerd.*

# Push_swap

## Description

Push_swap is an algorithmic sorting project from the 42 curriculum.

The goal of this project is to sort a list of integers using two stacks (a and b) and a limited set of allowed operations while generating the smallest possible number of instructions.

This project focuses on:

- Algorithmic complexity
- Optimization
- Data structures
- Sorting strategies
- Computational thinking

The program must analyze the input, choose an appropriate sorting strategy, and output a valid sequence of Push_swap operations capable of sorting the stack in ascending order.

---

## Allowed Operations

### Swap

sa
sb
ss

Swap the first two elements of a stack.

---

### Push

pa
pb

Push the top element from one stack to another.

---

### Rotate

ra
rb
rr

Shift all elements up by one.

---

### Reverse Rotate

rra
rrb
rrr

Shift all elements down by one.

---

## Objectives

The purpose of Push_swap is not only to sort numbers, but to sort them efficiently.

This project introduces several important algorithmic concepts:

- Time complexity
- Space complexity
- Adaptive sorting
- Stack manipulation
- Optimization of operations

The project also requires multiple sorting strategies with different complexity classes.

---

## Required Algorithms

This project includes four different strategies:

### Simple Algorithm — O(n²)

Used for small or simple datasets.

Examples:
- Selection sort
- Bubble sort
- Insertion sort

---

### Medium Algorithm — O(n√n)

Used for medium complexity sorting.

Examples:
- Chunk sorting
- Bucket-based strategies
- Range sorting

---

### Complex Algorithm — O(n log n)

Used for large random datasets.

Examples:
- Radix sort
- Quick sort adaptation
- Merge sort adaptation

---

### Adaptive Algorithm

The adaptive strategy computes the disorder of the stack before sorting and automatically selects the most appropriate internal strategy depending on the input configuration.

- Low disorder → O(n)
- Medium disorder → O(n√n)
- High disorder → O(n log n)

---

## Disorder Metric

The project introduces a disorder metric between 0 and 1.

- 0 means the stack is already sorted.
- 1 means the stack is completely reversed.

This metric helps the adaptive algorithm choose the most efficient strategy.

---

## Compilation

Compile the project using:

make

Available rules:

make
make clean
make fclean
make re

---

## Usage

### Basic usage

./push_swap 2 1 3 6 5 8

---

### Force a strategy

./push_swap --simple 5 4 3 2 1

./push_swap --medium 5 4 3 2 1

./push_swap --complex 5 4 3 2 1

./push_swap --adaptive 5 4 3 2 1

---

### Benchmark mode

./push_swap --bench 4 67 3 87 23

Benchmark mode displays:

- Disorder percentage
- Selected strategy
- Complexity class
- Total number of operations
- Count of each instruction

---

## Error Handling

The program displays:

Error

when:

- Invalid arguments are provided
- Duplicate numbers are detected
- Integers exceed valid limits
- Parsing fails

---

## Performance Goals

### 100 numbers

- Less than 2000 operations → pass
- Less than 1500 operations → good
- Less than 700 operations → excellent

### 500 numbers

- Less than 12000 operations → pass
- Less than 8000 operations → good
- Less than 5500 operations → excellent

---

## Project Structure

.
├── Makefile
├── include/
├── src/
├── utils/
├── parsing/
├── algorithms/
├── operations/
└── README.md

---

## Learning Outcomes

Through this project, I learned:

- Stack manipulation
- Sorting optimization
- Complexity analysis
- Adaptive algorithms
- Efficient data handling in C
- Operation cost reduction

---

## Resources

### Documentation

- The Push_swap subject PDF
- Linux man pages
- 42 intra resources
- Big-O complexity documentation

### Useful References

- https://www.bigocheatsheet.com/
- https://en.wikipedia.org/wiki/Radix_sort
- https://en.wikipedia.org/wiki/Sorting_algorithm

### AI Usage

AI tools were used for:

- Understanding algorithmic complexity
- Reviewing sorting strategies
- Improving explanations and documentation
- Debugging specific edge cases

All generated content was reviewed, tested, and fully understood before integration into the project.