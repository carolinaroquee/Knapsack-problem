//
// Created by anita on 23/05/2025.
//

#include <vector>
#include <algorithm>
#include "Pallet.h"
#include "GreedyByProfit.h"

using namespace std;

bool comparebyValue(const Pallet& pallet1,const Pallet& pallet2) {
  return pallet1.profit > pallet2.profit;

}

unsigned int GreedyByProfit(vector<Pallet>& pallets, int truckCapacity,  bool usedItems1[]) {
  vector<Pallet> byProfit= pallets;
  sort(byProfit.begin(), byProfit.end(), comparebyValue);
  int total_profit=0;
  int cur_weight=0;
  for(int i=0;i<byProfit.size();i++) {

    if(cur_weight + byProfit[i].weight <= truckCapacity) {
      usedItems1[byProfit[i].id - 1]= true;
      total_profit+=byProfit[i].profit;
      cur_weight += byProfit[i].weight;
    }
  }
  return total_profit;
}