//
// Created by carol on 22/05/2025.
//

#ifndef KNAPSACK_H
#define KNAPSACK_H
#include "Pallet.h"
#include <vector>

using namespace std;

unsigned int knapsackDP(vector<Pallet>& pallets, int truckCapacity, bool usedItems[]);

#endif //KNAPSACK_H
