# Assignment 8: Sliding Window Data Processor & Image Filter Simulator

## Overview
This project is an advanced C program developed for the CSE 102 Computer Programming course. It acts as a rudimentary image processing simulator, applying mathematical operations across large sets of numerical data using a "sliding window" (chunk) technique. The program reads numerical sets from a file, allows the user to stack specific operations (Max or Average), and dynamically outputs the processed data mapped to standard color paradigms (RGB, BGR, or Grayscale).

## Key Features
* **Sliding Window Algorithm:** Systematically slides a smaller numerical "chunk" (size 3, 6, or 9) over larger data lines (size 20, 50, or 80), mimicking the convolution process used in digital image filtering.
* **Dynamic Auto-Generation:** Includes a robust fallback mechanism that automatically generates a randomized, correctly formatted `input.txt` file if the source file is missing.
* **Color Paradigm Formatting:** Outputs the processed numerical results formatted into array structures based on user-selected Enum values:
  * **RGB:** `[line2, line3, line4]`
  * **BGR:** `[line4, line3, line2]`
  * **GRAY:** Prints each line array separately.
* **State Management via Stack:** Uses a custom Stack data structure to record and retrieve the sequence of operations ("max" or "avg") inputted by the user.

## Technical Implementation
This assignment demonstrates proficiency in advanced C programming paradigms:
* **Function Pointers:** Highly modularized execution using function pointers (`int (*operation)(int*, int*, int)`). The program dynamically swaps between `max_operation` and `avg_operation` at runtime based on the popped values from the user's stack.
* **String Tokenization & Parsing:** Implements `<string.h>` functions like `strtok` alongside custom string-to-integer conversion logic to parse CSV-style formatted text into usable integer arrays.
* **Dynamic Memory Allocation:** Efficiently handles arrays of varying lengths by utilizing `malloc()` to allocate memory for temporary calculation chunks and final result arrays, strictly followed by `free()` to prevent memory leaks.