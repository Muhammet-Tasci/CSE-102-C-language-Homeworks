# Assignment 9: Vector Database Search System

## Overview
This project is a C-based implementation of a Vector Database Search Engine developed for the CSE 102 Computer Programming course. It simulates how modern semantic search engines operate by calculating the Euclidean distance between a user-provided query embedding and pre-computed text embeddings. The system processes the data, ranks the embeddings based on their similarity (shortest distance), and retrieves the top corresponding text entries from a database.

## Key Features
* **Semantic Search Simulation:** Takes a multi-dimensional query vector and finds the most semantically similar sentences by comparing floating-point embeddings.
* **Euclidean Distance Calculation:** Utilizes advanced mathematical operations to compute the multi-dimensional distance $d(p, q) = \sqrt{\sum_{i=1}^{n} (q_i - p_i)^2}$ between the query and database vectors.
* **Top-N Result Ranking:** Iterates through the calculated distances and sorts them to identify and rank the closest matching entries (Top 5).
* **Synchronized File I/O:** Seamlessly reads and correlates data between two distinct files: `embedding.txt` (containing the float arrays) and `database.txt` (containing the actual text strings).

## Technical Implementation
This assignment heavily utilizes custom data structures and algorithms:
* **Struct-Based Data Management:** Defines a custom `struct` to neatly bind the dynamically allocated embedding vectors (`double *vector`), their calculated `distance` from the query, and their original `line` index together.
* **Dynamic Memory Allocation:** Uses `malloc()` to allocate memory for the highly dimensional vector arrays based on the dataset, ensuring the program handles varying data sizes efficiently without hardcoded limits.
* **Sorting Algorithms:** Implements sorting logic to reorder the structs based on the `distance` property, ensuring the most relevant text blocks are retrieved quickly.
* **String Parsing:** Utilizes `strtok()` and memory-safe string functions to parse comma-separated values (CSV) from the embedding text file into computable double arrays.