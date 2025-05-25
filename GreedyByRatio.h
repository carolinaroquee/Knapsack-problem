#ifndef GREEDYBYRATIO_H
#define GREEDYBYRATIO_H

#include "Pallet.h"
#include <vector>
using namespace std;

/**
 * @brief Algoritmo guloso baseado na razão lucro/peso para o problema da mochila.
 *
 * Ordena os paletes pela razão lucro/peso e seleciona-os enquanto a capacidade permitir.
 * É um algoritmo aproximado, não garante a solução ótima.
 *
 * @param pallets Vetor com todos os paletes disponíveis.
 * @param truckCapacity Capacidade máxima do camião.
 * @param usedItems2 Array booleano que indicará quais paletes foram selecionados.
 *
 * @return unsigned int Lucro total obtido pela seleção gulosa.
 *
 * @complexity
 * Tempo: O(n log n) devido à ordenação dos paletes.
 * Espaço: O(n) para o vetor auxiliar.
 */
unsigned int GreedyByRatio(vector<Pallet>& pallets, int truckCapacity,  bool usedItems2[]);

#endif //GREEDYBYRATIO_H
