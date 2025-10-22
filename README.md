# Knapsack problem project

## Overview
This C++ command-line application addresses the Delivery Truck Pallet Packing Optimization Problem, a variation of the 0/1 Knapsack Problem. The goal is to maximize profit by selecting pallets to load onto a truck while respecting its weight capacity. The system implements multiple algorithmic approaches—exhaustive search (brute-force), dynamic programming, greedy by profit-to-weight ratio, and integer linear programming (via Python script)—to explore trade-offs between optimality and efficiency. Data is loaded from CSV files (`TruckAndPallets_X.csv` and `Pallets_X.csv`), supporting real-world logistics optimization scenarios. The project demonstrates proficiency in algorithm design, data structures, and performance analysis.

## Features
- **Exhaustive Search (Brute-Force)**: Tests all possible pallet combinations to find the optimal solution, with lexicographic tie-breaking for equal profits.
- **Dynamic Programming**: Uses a table-based approach to compute the optimal subset of pallets efficiently.
- **Greedy Algorithm**: Selects pallets based on profit-to-weight ratio for a fast, approximate solution.
- **Integer Linear Programming (ILP)**: Integrates with a Python script to solve the problem using ILP (external solver).
- **Interactive Menu**: Allows users to select datasets (1-10) and algorithms, displaying results (profit, selected pallets, total weight).
- **Data Loading**: Parses CSV files to load truck capacity and pallet data (ID, weight, profit).

## Technologies Used
- **C++**: Core language (C++11, Standard Library: vectors, streams).
- **Data Structures**: Arrays, vectors, custom structs (`Pallet`, `TruckandPallet`, `subProblem`).
- **Algorithms**: Brute-force, dynamic programming, greedy, ILP integration.
- **Python**: External ILP solver script (`KnapsackSolver.py`).
- **File I/O**: CSV parsing for input data.

## Project Structure
- `main.cpp`: Program entry point; launches the command-line menu.
- `Pallet.h`: Defines the `Pallet` struct (ID, weight, profit).
- `TruckandPallet.h`: Defines the `TruckandPallet` struct for truck capacity and pallets.
- `subProblem.h`: Struct for dynamic programming state (profit, pallet count).
- `DataLoader.h` / `DataLoader.cpp`: Loads truck and pallet data from CSV files.
- `CommandLineMenu.h` / `CommandLineMenu.cpp`: Implements the interactive menu and algorithm execution.
- `ExhaustiveBF.h` / `ExhaustiveBF.cpp`: Brute-force algorithm implementation.
- `KnapsackDP.h` / `KnapsackDP.cpp`: Dynamic programming algorithm implementation.
- `GreedyByRatio.h` / `GreedyByRatio.cpp`: Greedy algorithm implementation.
- `KnapsackSolver.py`: External Python script for ILP (not included in provided files).


Compile the C++ source files:
```bash
g++ -std=c++11 -o pallet_packer main.cpp DataLoader.cpp CommandLineMenu.cpp ExhaustiveBF.cpp KnapsackDP.cpp GreedyByRatio.cpp
