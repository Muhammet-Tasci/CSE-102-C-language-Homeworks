# Assignment 13: Command-Driven Text Processing Engine

## Overview
This project is an automated, batch-processing text engine developed in C for the CSE 102 Computer Programming course. Acting as a lightweight command interpreter, the program systematically reads a source text file (`input.txt`), parses a sequence of user-defined operations from a script file (`commands.txt`), applies these transformations in real-time, and securely writes the final state to an output file (`output.txt`). 

## Key Features
* **Batch Command Execution:** Reads, decodes, and sequentially executes discrete text-manipulation commands without requiring manual user intervention during runtime.
* **Multi-Stream File I/O:** Safely and concurrently manages multiple file streams—reading source data, fetching operational commands, and writing processed results simultaneously.
* **Dynamic String Manipulation:** Performs complex text transformations (e.g., searching, replacing, inserting, or deleting specific strings/lines) based on the strict parameters defined in the command file.
* **State Preservation:** Ensures that each sequential command alters the state of the text correctly, chaining operations together to produce the exact desired output.

## Technical Implementation
This assignment demonstrates strong proficiency in low-level string and file handling in C:
* **Command Parsing Logic:** Utilizes advanced string parsing techniques (such as `strtok()`, `sscanf()`, or custom delimiters) to interpret varied command syntaxes and extract actionable arguments.
* **Buffer & Memory Management:** Implements secure character arrays and dynamic memory handling (where applicable) to prevent buffer overflows while processing lines of unpredictable lengths.
* **Algorithmic Text Transformation:** Employs precise pointer arithmetic and `<string.h>` library functions to shift, overwrite, and manipulate text efficiently in memory before committing changes to the hard drive.