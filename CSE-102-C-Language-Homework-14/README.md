# Assignment 14: Comprehensive Student Management System

## Overview
This project is the capstone assignment for the CSE 102 Computer Programming course. It is a fully functional, terminal-based Student Management System designed to handle academic records dynamically. The system allows administrators to seamlessly manage a scalable registry of students, track their enrolled courses, record grades, and automatically compute accurate Grade Point Averages (GPA) based on specific course credits.

## Key Features
* **Scalable Student Registry:** Dynamically adds, searches, and removes student profiles using advanced data structures, ensuring the system can handle an arbitrary number of records without the limits of static arrays.
* **Dynamic Academic Tracking:** Allows granular updates to individual student profiles, including the addition or removal of specific lectures (e.g., CSE101, CSE102) and their corresponding grades.
* **Automated GPA Calculation:** Features an internal algorithm that instantly recalculates a student's GPA whenever a grade is added or removed, heavily factoring in the predefined credit weights of each specific course.
* **Interactive Command-Line Interface:** Provides a robust, 8-option menu-driven CLI for intuitive database management and data retrieval.

## Technical Implementation
This final assignment demonstrates mastery over core C programming paradigms and low-level system design:
* **Linked List Architecture:** The core database is built entirely from scratch using a Singly Linked List. It utilizes custom, self-referential `struct` nodes (`typedef struct M`) to link dynamically allocated student records in memory.
* **Complex Data Encapsulation:** Employs advanced `struct` nesting and `enum` types to cleanly encapsulate student attributes, lecture identifiers, and array-based grade tracking within a single memory block.
* **Strict Memory Management:** Meticulously manages heap memory utilizing `malloc()` for node creation. It features a comprehensive `free_all()` garbage collection routine to traverse the entire linked list and safely deallocate all pointers upon program termination, guaranteeing zero memory leaks.