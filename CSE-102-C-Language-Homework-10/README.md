# Assignment 10: Advanced Data Structures & Management System

## Overview
This project serves as the final, capstone assignment for the CSE 102 Computer Programming course. It brings together all the fundamental C programming concepts learned throughout the semester to build a comprehensive, terminal-based management system. The core focus of this project is the efficient use of dynamic data structures (such as Linked Lists) to handle varying amounts of data at runtime, alongside persistent file I/O operations.

## Key Features
* **Dynamic Data Handling:** Implements dynamic data structures allowing the system to scale its memory usage smoothly without relying on fixed-size arrays.
* **Full CRUD Functionality:** Supports Create, Read, Update, and Delete operations for managing individual records through a user-friendly Command Line Interface (CLI).
* **Persistent Storage (File I/O):** Seamlessly saves all database changes to structured text files and rebuilds the dynamic memory structures from these files upon restarting the program.
* **Robust Input Validation:** Ensures program stability by meticulously verifying all user inputs, preventing buffer overflows, memory leaks, and segmentation faults.

## Technical Implementation
This assignment demonstrates mastery over advanced C programming paradigms:
* **Linked Lists & Structs:** Utilizes custom `struct` definitions linked via pointers (`next` / `prev`) to create flexible and dynamic nodes.
* **Memory Management:** Strictly enforces dynamic memory allocation using `malloc()` for new nodes and robust cleanup loops using `free()` to prevent memory leaks during node deletion and program termination.
* **Pointer Arithmetic & Manipulation:** Heavily relies on advanced pointer logic to traverse lists, insert nodes in specific sorted orders, and safely detach/delete nodes from memory.