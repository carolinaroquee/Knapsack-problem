#ifndef EXHAUSTIVE_BRUTE_FORCE_H
#define EXHAUSTIVE_BRUTE_FORCE_H

#include "Pallet.h"
#include <vector>

using namespace std;

/**
 * @brief Algoritmo Exaustivo (Força Bruta) para o problema da mochila.
 *
 * Testa todas as combinações possíveis de paletes para maximizar o lucro,
 * respeitando a capacidade máxima do camião. Em caso de empate de lucro,
 * escolhe a solução com menos paletes e, se persistir empate, desempata lexicograficamente.
 *
 * @param pallets Vetor com todos os paletes disponíveis.
 * @param truckCapacity Capacidade máxima do camião.
 * @param bestSolution Vetor onde será guardada a melhor combinação de paletes.
 *
 * @return int Lucro máximo obtido.
 *
 * @complexity
 * Tempo: O(2^n), onde n é o número de paletes, pois verifica todas as combinações.
 * Espaço: O(n) para armazenar a combinação atual.
 */
int ExhaustiveBF(vector<Pallet>& pallets, int truckCapacity, vector<Pallet>& bestSolution);

#endif //EXHAUSTIVE_BRUTE_FORCE_H
