#include "Pallet.h"
#include "TruckandPallet.h"

using namespace std;

/**
 * @brief Implementação do algoritmo exaustivo (força bruta) para mochila.
 *
 * Testa todas as combinações de pallets e retorna a melhor solução.
 *
 * @param pallets Vetor dos pallets disponíveis.
 * @param truckCapacity Capacidade máxima do camião.
 * @param bestSolution Vetor para armazenar a melhor combinação encontrada.
 *
 * @return int Lucro máximo obtido.
 */
int ExhaustiveBF(std::vector<Pallet>& pallets, int truckCapacity, std::vector<Pallet>& bestSolution) {
    const int n = pallets.size();

    bool curCandidate[n] = {false};  //representar uma combinação de pallets atual, pallet está incluído (true) ou não (false).
    bool foundSol = false;
    int maxProfit = 0;
    int minPallets = n + 1; // para guardar o mínimo número de pallets na melhor solução

    while (true) {
        // Calcula peso e lucro da combinação atual
        int totalWeight = 0;
        int totalProfit = 0;
        int countPallets = 0;
        for (int i = 0; i < n; ++i) {
            if (curCandidate[i]) {
                //Passa por cada pallet: se ele está incluído na combinação atual (curCandidate[i] == true),
                ////soma o peso, lucro e conta um pallet.
                totalWeight += pallets[i].weight;
                totalProfit += pallets[i].profit;
                countPallets++;
            }
        }

        if (totalWeight <= truckCapacity) {//valida se o peso total não ultrapassar o limite do caminhão.
            if (!foundSol || totalProfit > maxProfit) { //Se ainda não encontrou a solução ou encontrou lucro maio
                // Melhor lucro encontrado, atualiza tudo
                foundSol = true;
                maxProfit = totalProfit;
                minPallets = countPallets;

                bestSolution.clear();
                for (int i = 0; i < n; ++i) {
                    if (curCandidate[i]) {
                        bestSolution.push_back(pallets[i]);
                    }
                }
            }
            else if (totalProfit == maxProfit) {
                // Desempate pelo menor número de pallets
                if (countPallets < minPallets) {
                    minPallets = countPallets;
                    bestSolution.clear();
                    for (int i = 0; i < n; ++i) {
                        if (curCandidate[i]) {
                            bestSolution.push_back(pallets[i]);
                        }
                    }
                }
                else if (countPallets == minPallets) {
                    // Desempate lexicográfico pela ordem dos pallets
                    bool better = false; //Serve para indicar se a solução atual (curCandidate) é melhor que a melhor solução até agora (bestSolution), segundo o critério lexicográfico.
                    for (int i = 0; i < n; ++i) {
                        bool inCurrent = curCandidate[i]; // Está o pallet i na solução atual?
                        bool inBest = false;// Está o pallet i na melhor solução atual?
                        for (auto& p : bestSolution) {
                            if (p.id == pallets[i].id) {
                                inBest = true;
                                break;
                            }
                        }
                        if (inCurrent && !inBest) { // a solução atual tem um pallet que a melhor não tem, logo é "menor" lexicograficamente
                            better = true;
                            break;
                        }
                        else if (!inCurrent && inBest) {// a solução melhor tem um pallet que a atual não tem, logo a atual não é melhor
                            better = false;
                            break;
                        }
                        // Se igual, continua comparando próximo índice
                    }
                    if (better) {
                        bestSolution.clear();
                        for (int i = 0; i < n; ++i) {
                            if (curCandidate[i]) {
                                bestSolution.push_back(pallets[i]);
                            }
                        }
                    }
                }
            }
        }

        // Gera próxima combinação (incremento binário)
        int curIndex = 0;
        while (curIndex < n && curCandidate[curIndex]) {
            curCandidate[curIndex] = false;
            curIndex++;
        }
        if (curIndex == n) break;
        curCandidate[curIndex] = true;
    }

    return maxProfit;
}