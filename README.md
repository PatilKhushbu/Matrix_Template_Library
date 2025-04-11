# Matrix_Template_Library in C++

# 🧮 Matrix Template Library in C++

## 📌 Overview
This project implements a **C++ template-based matrix library** supporting generic matrix operations like transpose, submatrix extraction, addition, and multiplication — including optimized multiplication of three matrices.

## 🚀 Features
- Generic matrix class using templates (`MatOp<T>`)
- Matrix addition and multiplication
- Transpose of a matrix
- Submatrix extraction
- Deep copy support
- Row-major and column-major traversal
- Optimized multiplication of 3 matrices (based on dimension contraction)

## 📁 File Structure
- `main.cpp` – Contains the menu-driven main function for user interaction
- `MatOp.h` – Header file with the implementation of the `MatOp<T>` class and all matrix operations

## 🛠️ Operations Supported
1. Matrix Transpose
2. Submatrix Extraction
3. Matrix Addition
4. Multiplication of 3 Matrices with Efficient Order
5. Matrix Traversal (Row-wise & Column-wise)

## 🔧 How to Use
1. Compile the project:
   ```bash
   g++ main.cpp -o matrix
   ```
2. Run the executable:
   ```bash
   ./matrix
   ```

3. Follow the on-screen menu to perform different operations.

## 👨‍💻 Contributors
- Khushbu Mahendra Patil
- Khalid Vafa
- Muhammad Israr
