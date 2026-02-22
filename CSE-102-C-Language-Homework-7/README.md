# Assignment 7: Terminal-Based Minesweeper

## Overview
[cite_start]This project is a dynamic, terminal-based implementation of the classic Minesweeper game, developed in C for the CSE 102 Computer Programming course[cite: 397]. [cite_start]It features a dynamically generated NxN grid with randomized mine placement[cite: 398]. [cite_start]The game includes an advanced recursive flood-fill algorithm for uncovering empty areas and a custom Stack data structure to provide a complete move-history and an "undo" feature[cite: 401, 413].

## Key Features
* [cite_start]**Dynamic Board Generation:** Automatically scales the game board to a random size between 2x2 and 10x10 at startup, randomly dispersing mines and saving the underlying map to `map.txt`[cite: 398, 405, 406, 407].
* [cite_start]**Recursive Flood-Fill:** When a user selects a "safe" cell with 0 neighboring mines, the program uses recursion to automatically uncover all adjacent safe cells in a single turn, mimicking the behavior of the original game[cite: 401, 415].
* [cite_start]**"Undo" Mechanics via Stack:** Integrates a custom Last-In-First-Out (LIFO) Stack system[cite: 421, 425]. [cite_start]Players can type `undo` to pop their last move from the stack and revert the board to its previous state[cite: 412, 424, 430].
* [cite_start]**Persistent Gameplay Logging:** Automatically tracks all valid actions and exports the complete sequence of moves to `moves.txt` at the end of the game for review[cite: 403, 453, 454].

## Technical Implementation
* [cite_start]**Custom Stack Structure:** Implemented using parallel fixed-size arrays (`move_rows` and `move_cols`) to manage state without relying on C structs, strictly following the LIFO principle with custom `push()` and `pop()` functions[cite: 426, 429, 430].
* **Advanced Memory Management:** Utilizes pointers to pointers (`char**`) to dynamically allocate memory for 2D arrays (`board` and `board_user`) based on the randomized dimension N, ensuring proper cleanup via `free()` loops to prevent memory leaks.
* [cite_start]**Complex State Management:** Accurately calculates adjacent mines in all 8 directions and manages distinct game states: hidden (`#`), revealed (counts), and triggered mine (`X`)[cite: 417, 418, 419].