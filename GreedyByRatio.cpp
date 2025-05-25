#include "Pallet.h"
#include <vector>
#include <algorithm>
#include "GreedyByRatio.h"

using namespace std;

/**
 * @brief Função de comparação para ordenação por razão lucro/peso.
 *
 * @param pallet1 Primeiro pallet.
 * @param pallet2 Segundo pallet.
 * @return true Se a razão do primeiro for maior que a do segundo.
 */
bool comparebyRatio(const Pallet& pallet1,const Pallet& pallet2) {
    return (double)pallet1.profit/ pallet1.weight > (double)pallet2.profit / pallet2.weight;

}

/**
 * @brief Implementação do algoritmo guloso baseado em razão lucro/peso.
 *
 * Ordena os pallets e seleciona enquanto a capacidade permitir.
 *
 * @param pallets Vetor com os pallets disponíveis.
 * @param truckCapacity Capacidade máxima do camião.
 * @param usedItems2 Array booleano para marcar pallets usados.
 * @return unsigned int Lucro total obtido.
 */
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