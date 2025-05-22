
#include "Pallet.h"
#include "DataLoader.h"
#include "TruckandPallet.h"

using namespace std;
int ExhaustiveBF(vector<Pallet>& pallets, int truckCapacity, vector<Pallet>& bestSolution){

  int n = pallets.size();
  int maxProfit = 0;
  int totalSubsets = 1 << n; // 2^n possíveis subconjuntos

 for (int i = 0; i < totalSubsets; i++) { // 1 << n é equivalente a 2^n
 	int totalWeight = 0;
    int totalProfit = 0;
	vector<Pallet> currentSelection;

 	for (int j = 0; j < n; ++j) {
		if (i & (1 << j)) {  // Check if palete is included in the subset
			totalWeight += pallets[j].weight;
			totalProfit += pallets[j].profit;
            currentSelection.push_back(pallets[j]);

            if (totalWeight > truckCapacity) break;
        }
    }

    if (totalWeight <= truckCapacity && totalProfit > maxProfit) {
            maxProfit = totalProfit;
            bestSolution = currentSelection;
        }
 }

 return maxProfit;
}