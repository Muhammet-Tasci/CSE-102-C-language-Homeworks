# Assignment 5: Battleship Game Simulation

## Overview
This project is a classic Battleship Game Simulation developed in C for the CSE 102 Computer Programming course. It features a $10 \times 10$ grid where a fleet of four ships is randomly deployed. The user interacts with the system by firing at specific coordinates to find and sink the hidden ships. The simulation includes dynamic board updates, input validation, and comprehensive move logging.

## Key Features
* **Procedural Ship Placement:** Automatically and randomly places 4 ships (one 4-cell, two 3-cell, and one 2-cell) on the board horizontally or vertically, ensuring strictly that no ships overlap.
* **Interactive Gameplay Loop:** The game dynamically updates the visual board after each turn, marking hits with `X` and misses with `O`. It actively detects and notifies the user when a specific ship is completely sunk.
* **Persistent Logging (File I/O):** The initial secret coordinates of all ships are saved to `ships.txt`, while every single shot taken by the user is appended to `battleship_log.txt` for post-game analysis.
* **Replayability & Safe Exit:** Users can safely exit the game at any moment by entering `X`, or choose to start a completely new, randomized game (`N`) after successfully sinking the entire fleet.

## Technical Implementation
* **2D Array Management:** Utilizes multiple multi-dimensional arrays (`char[10][10]`) to separate the underlying game logic (where ships are located) from the user-facing display board.
* **Robust Input Handling:** Employs `fgets` combined with `sscanf` to parse user input safely, preventing buffer overflows or infinite loops when unexpected or non-numeric data is entered.
* **Algorithmic Collision Detection:** Incorporates custom validation loops during the initialization phase to verify that randomly generated ship coordinates do not exceed board boundaries or collide with already placed ships.