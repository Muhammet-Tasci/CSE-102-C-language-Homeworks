# Assignment 4: Rocket Trajectory Simulator

## Overview
This project is a C-based simulation tool developed for the CSE 102 Computer Programming course. Acting as a computational model for aerospace analysis, the program calculates and visualizes the flight trajectory of a rocket based on user-defined launch parameters. It plots the rocket's path on a dynamically generated 2D ASCII graph and systematically handles data persistence.

## Key Features
* **Interactive Simulation Menu:** A user-friendly console interface that guides the user through entering parameters, running the simulation, and saving the results.
* **Input Validation & Error Handling:** Implements strict data validation to prevent program crashes from non-numeric or invalid inputs, ensuring stable execution.
* **ASCII Trajectory Visualization:** Dynamically generates a text-based 2D graph mapping the rocket's altitude over time, plotted accurately without the use of graphical libraries.
* **File I/O Data Management:** Systematically records launch parameters to `rocket_data.txt` and exports the final trajectory graph and flight statistics to `trajectory.txt`.

## Mathematical Models
The simulation relies on fundamental kinematic physics equations to compute the trajectory dynamically:
* **Height over time:** $h(t) = -\frac{1}{2}gt^2 + V_0t + h$
* **Maximum Altitude:** $h_{max} = \frac{V_0^2}{2g} + h_0$
* **Total Flight Duration:** $t_{flight} = \frac{V_0 + \sqrt{V_0^2 + 2gh_0}}{g}$

## Technical Constraints & Implementation
This project was engineered under strict academic constraints to emphasize algorithmic problem-solving:
* **No Arrays Permitted:** The entire 2D graph and data processing are handled strictly using scalar variables and mathematical logic, eliminating the reliance on arrays.
* **Modular Architecture:** The system avoids global variables and is heavily modularized into specialized functions (e.g., `simulate()`, `enter_parameters()`, `max_h()`) for reusability and clean structure.
* **Algorithmic Graphing:** The grid, axes, and trajectory points (`#`) are computed and printed line-by-line dynamically based on the specific flight duration and maximum altitude.