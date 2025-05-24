import sys
from pulp import LpProblem, LpMaximize, LpVariable, lpSum, LpBinary, value


with open(sys.argv[1]) as f:

    max_pallets = int(f.readline())
    max_weight = int(f.readline())
    weights_line = f.readline().strip()
    profits_line = f.readline().strip()

    weights = list(map(int, weights_line.split()))
    profits = list(map(int, profits_line.split()))

    n = len(weights)

    model = LpProblem("Knapsack", LpMaximize)

    x = [LpVariable(f"x{i}", cat=LpBinary) for i in range(n)]

    model += lpSum(x[i] * profits[i] for i in range(n)), "Total_Profit"

    model += lpSum(x[i] for i in range(n)) <= max_pallets, "Max_Pallets"
    model += lpSum(x[i] * weights[i] for i in range(n)) <= max_weight, "Max_Weight"

    from pulp import *
    model.solve(PULP_CBC_CMD(msg=False))
    total_weight=0

    print("Solution state:", LpStatus[model.status])
    print("Max profit (ILP Algorithm):", value(model.objective))
    print("Selected pallets:")
    for i in range(n):
        if x[i].varValue == 1:
            print(f" - Pallet {i+1} (Weight: {weights[i]}, Profit: {profits[i]})")
            total_weight += weights[i]

    print(f"Total weight: {total_weight}\n")

