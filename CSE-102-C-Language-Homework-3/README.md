# Assignment 3: Virtual ATM Simulator

## Overview
This project is a Virtual ATM Simulator developed in C for the CSE 102 Computer Programming course[cite: 2, 5]. It mimics basic banking operations, allowing users to check their balance, deposit funds, and withdraw money[cite: 5]. The system ensures data persistence by saving the account balance to a text file (`account.txt`) between program executions.

## Key Features
* **Account Initialization:** Automatically creates a new account with an initial balance of $100.00 if no previous record exists.
* **Transactions:** Supports depositing and withdrawing money while preventing invalid actions such as entering negative amounts or overdrawing beyond the current balance.
* **Persistent Storage:** Reads and updates the balance via File I/O (`account.txt`) after each transaction to maintain accurate records.

## Technical Constraints & Implementation
This assignment was designed to strengthen fundamental programming concepts under strict constraints:
* **Control Flow:** The program execution relies entirely on conditional statements (`if`, `else`, and `switch`) without the use of loops.
* **Data Structures:** Restricted to scalar variables only; no arrays, structs, or pointers were utilized.
* **Modular Design:** The logic is strictly divided into specific, single-purpose functions for each bank transaction.
* **Libraries:** Utilizes only standard C libraries (`stdio.h` for input/output and `stdlib.h` for file handling).
