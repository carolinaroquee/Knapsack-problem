#include "Pallet.h"
#include <vector>
#include "subProblem.h"
#include <iostream>

using namespace std;

/**
 * @brief Implementação do algoritmo de Programação Dinâmica para o problema da mochila.
 *
 * Calcula o lucro máximo possível respeitando a capacidade do camião e
 * reconstrói a solução ótima.
 */
unsigned int knapsackDP(vector<Pallet>& pallets, int truckCapacity, bool usedItems[]) {
    unsigned int n = pallets.size();
    vector dp(n+1, vector<subProblem>(truckCapacity+1, {0, 0}));
    vector choice(n+1, vector(truckCapacity+1, false));

    for (unsigned int i = 1; i <= n; i++) {
        for (unsigned int k = 0; k <= truckCapacity; k++) {
            if (k < pallets[i-1].weight) {
                dp[i][k] = dp[i-1][k];
                choice[i][k] = false;
            } else {
                subProblem noPick = dp[i-1][k];
                subProblem pick = {
                    dp[i-1][k - pallets[i-1].weight].profit + pallets[i-1].profit,
                    dp[i-1][k - pallets[i-1].weight].count + 1
                };
                if (noPick < pick) { //quando são iguais
                    dp[i][k] = pick;
                    choice[i][k] = true;  // escolheu palete i
                } else {
                    dp[i][k] = noPick;
                    choice[i][k] = false; // não escolheu palete i
                }
            }
        }
    }

    // Reconstruir solução usando choice
    unsigned int remainingWeight = truckCapacity;
    for (int i = n; i > 0; i--) {
        if (choice[i][remainingWeight]) {
            usedItems[i-1] = true;
            remainingWeight -= pallets[i-1].weight;
        } else {
            usedItems[i-1] = false;
        }
    }

    return dp[n][truckCapacity].profit;
}
