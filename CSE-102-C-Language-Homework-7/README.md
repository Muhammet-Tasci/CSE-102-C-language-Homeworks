# Assignment 7: Terminal-Based Minesweeper

## Overview
This project is a dynamic, terminal-based implementation of the classic Minesweeper game, developed in C for the CSE 102 Computer Programming course. It features a dynamically generated NxN grid with randomized mine placement. The game includes an advanced recursive flood-fill algorithm for uncovering empty areas and a custom Stack data structure to provide a complete move-history and an "undo" feature.

## Key Features
* **Dynamic Board Generation:** Automatically scales the game board to a random size between 2x2 and 10x10 at startup, randomly dispersing mines and saving the underlying map to `map.txt`.
* **Recursive Flood-Fill:** When a user selects a "safe" cell with 0 neighboring mines, the program uses recursion to automatically uncover all adjacent safe cells in a single turn, mimicking the behavior of the original game.
* **"Undo" Mechanics via Stack:** Integrates a custom Last-In-First-Out (LIFO) Stack system. Players can type `undo` to pop their last move from the stack and revert the board to its previous state.
* **Persistent Gameplay Logging:** Automatically tracks all valid actions and exports the complete sequence of moves to `moves.txt` at the end of the game for review.

## Technical Implementation
* **Custom Stack Structure:** Implemented using parallel fixed-size arrays (`move_rows` and `move_cols`) to manage state without relying on C structs, strictly following the LIFO principle with custom `push()` and `pop()` functions.
* **Advanced Memory Management:** Utilizes pointers to pointers (`char**`) to dynamically allocate memory for 2D arrays (`board` and `board_user`) based on the randomized dimension N, ensuring proper cleanup via `free()` loops to prevent memory leaks.
* **Complex State Management:** Accurately calculates adjacent mines in all 8 directions and manages distinct game states: hidden (`#`), revealed (counts), and triggered mine (`X`).
