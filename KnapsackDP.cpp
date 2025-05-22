#include "Pallet.h"
#include "DataLoader.h"
#include "TruckandPallet.h"
#include <vector>
#include <iostream>

using namespace std;

int knapsackDP(vector<Pallet>& pallets, int truckCapacity, bool usedItems[]) {
    unsigned int n = pallets.size();  // Número de paletes
    unsigned int maxValue[n+1][truckCapacity+1];  // Tabela de DP

    //linha 0
    for (unsigned int k = 0; k <= truckCapacity; k++) {
        maxValue[0][k] = 0;  // Se não há paletes, o lucro é 0 para qualquer capacidade
    }

    //linha 1 para baixo
    for (unsigned int i = 1; i <= n; i++) {
        for (unsigned int k = 0; k <= truckCapacity; k++) {
            if (k < pallets[i-1].weight) {
                //Quando o peso k da mochila é menor que o peso da palete, a palete não pode ser incluída
                maxValue[i][k] = maxValue[i-1][k];
            } else {
                // Caso inclua a palete: max entre não incluir ou incluir a palete
                maxValue[i][k] = std::max(maxValue[i-1][k], maxValue[i-1][k - pallets[i-1].weight] + pallets[i-1].profit);
            }
        }
    }


    unsigned int remainingWeight = truckCapacity;
    for (unsigned int i = n; i > 0; i--) {
        // Se a solução não mudou entre incluir ou não incluir a palete, ela não foi escolhida
        if (maxValue[i][remainingWeight] != maxValue[i-1][remainingWeight]) {
            usedItems[i-1] = true;
            remainingWeight -= pallets[i-1].weight;
        }
    }
    return maxValue[n][truckCapacity];
}