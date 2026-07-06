# Matrix Template Library

A generic, template-based C++ matrix library supporting core linear algebra operations, including an efficiency-optimized three-matrix multiplication.

## Problem

Matrix operations are foundational to countless computational problems, but hard-coding them for a single numeric type (int, float, double) means rewriting the same logic repeatedly. This project builds a generic matrix class using C++ templates so the same operations work across any numeric type, while also exploring how multiplication order affects computational efficiency when chaining more than two matrices together.

## Approach

- Built a generic `MatOp<T>` template class supporting any numeric type, avoiding duplicated code across int/float/double matrix implementations
- Implemented core operations: transpose, submatrix extraction, matrix addition, and deep copy
- Implemented both row-major and column-major traversal, useful for understanding memory access patterns and cache performance
- Solved multiplication of three matrices using dimension-based contraction ordering — choosing the multiplication order that minimizes total scalar operations, rather than just multiplying left-to-right
- Wrapped everything in a menu-driven `main.cpp` for interactive testing of each operation

## Results

The library correctly performs all supported operations (transpose, addition, submatrix extraction, multi-matrix multiplication) across generic numeric types via templates. The three-matrix multiplication specifically demonstrates that multiplication order matters computationally — contracting dimensions in the right order reduces the total number of scalar multiplications compared to naive left-to-right evaluation, a classic optimization problem in its own right (related to the matrix chain multiplication problem in algorithm design).

## Tech Stack

C++ (templates, OOP, generic programming)

## How to Run

```bash
g++ main.cpp -o matrix
./matrix
```

Then follow the on-screen menu to select and run each operation.

---

**Contributors:** Khushbu Mahendra Patil, Khalid Vafa, Muhammad Israr
**University:** Ca' Foscari University of Venice
**Subject:** Advanced Programming Languages [CM0632]
