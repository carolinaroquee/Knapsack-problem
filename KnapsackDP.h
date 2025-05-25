#ifndef KNAPSACK_H
#define KNAPSACK_H
#include "Pallet.h"
#include <vector>

using namespace std;

/**
 * @brief Solução por Programação Dinâmica para o problema da mochila.
 *
 * Usa uma tabela para calcular o lucro máximo possível para cada peso e
 * número de paletes considerados. Reconstrói a solução ótima ao final.
 *
 * @param pallets Vetor com todos os paletes disponíveis.
 * @param truckCapacity Capacidade máxima do camião.
 * @param usedItems Array booleano que indicará quais paletes foram selecionados.
 *
 * @return unsigned int Lucro máximo obtido.
 *
 * @complexity
 * Tempo: O(n * W), onde n é o número de paletes e W é a capacidade do camião.
 * Espaço: O(n * W) para a tabela dp.
 */
unsigned int knapsackDP(vector<Pallet>& pallets, int truckCapacity, bool usedItems[]);

#endif //KNAPSACK_H
