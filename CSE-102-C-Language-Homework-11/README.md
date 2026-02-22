# Assignment 11: Advanced Data Structures & Dynamic Memory Management

## Overview
This project is an advanced C programming assignment developed for the CSE 102 Computer Programming course. It tackles complex computational problems by implementing custom, dynamic data structures from scratch. The system is designed to handle large datasets efficiently without the constraints of fixed-size arrays, focusing on scalability, memory safety, and algorithmic efficiency.

## Key Features
* **Dynamic Data Allocation:** Seamlessly manages memory at runtime, allowing the dataset to grow or shrink dynamically based on user operations.
* **Complex Data Traversals:** Implements efficient searching, sorting, and traversal algorithms to process and retrieve information from the custom data structures quickly.
* **Advanced File I/O Operations:** Features robust data persistence, capable of reading from and writing to text/binary files to ensure no data is lost between system executions.
* **Interactive Command-Line Interface (CLI):** Provides a comprehensive menu-driven interface for users to perform CRUD (Create, Read, Update, Delete) operations effortlessly.

## Technical Implementation
This assignment demonstrates a deep understanding of low-level memory management and advanced C paradigms:
* **Custom Structs & Pointers:** Heavily relies on self-referential `struct` definitions and complex pointer manipulation (e.g., pointers to pointers) to link data nodes dynamically.
* **Strict Memory Management:** All dynamically allocated memory (`malloc`, `calloc`) is meticulously tracked and freed (`free`) during program termination and node deletion to prevent memory leaks and segmentation faults.
* **Modular Code Architecture:** The logic is strictly decoupled into single-purpose functions, ensuring the codebase remains highly readable, maintainable, and scalable.