//
// Created by anita on 23/05/2025.
//
#include "Pallet.h"
#include <vector>
#include <algorithm>
#include "GreedyByRatio.h"

using namespace std;

bool comparebyRatio(const Pallet& pallet1,const Pallet& pallet2) {
    return (double)pallet1.profit/ pallet1.weight > (double)pallet2.profit / pallet2.weight;

}

unsigned int GreedyByRatio(vector<Pallet>& pallets, int truckCapacity,  bool usedItems2[]) {
    vector<Pallet> byProfit= pallets;
    sort(byProfit.begin(), byProfit.end(), comparebyRatio);
    int total_profit=0;
    int cur_weight=0;
    for(int i=0;i<byProfit.size();i++) {
        if(cur_weight + byProfit[i].weight <= truckCapacity) {
            usedItems2[byProfit[i].id - 1]= true;
            total_profit+=byProfit[i].profit;
            cur_weight += byProfit[i].weight;
        }
    }
    return total_profit;
}