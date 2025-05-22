
#include "Pallet.h"
#include "DataLoader.h"
#include "TruckandPallet.h"

using namespace std;

int ExhaustiveBF(vector<Pallet>& pallets, int truckCapacity, vector<Pallet>& bestSolution) {
    int n = pallets.size();
    int maxProfit = 0;
    int totalSubsets = 1 << n; // 2^n subconjuntos

    for (int i = 0; i < totalSubsets; i++) {
        int totalWeight = 0;
        int totalProfit = 0;
        vector<Pallet> currentSelection;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                totalWeight += pallets[j].weight;
                totalProfit += pallets[j].profit;
                currentSelection.push_back(pallets[j]);
            }
        }

        if (totalWeight <= truckCapacity && totalProfit > maxProfit) {
            maxProfit = totalProfit;
            bestSolution = currentSelection;
        }
    }

    return maxProfit;
}