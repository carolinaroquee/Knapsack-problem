#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "TruckandPallet.h"
#include "DataLoader.h"
#include "ExhaustiveBF.h"
#include "knapsackDP.h"

void command_line(){
    TruckandPallet truck;
    string datasetChoice;
    int choice=0;


  while (choice != 5){

      cout << "What planning do you want to run the program?" << endl;
      cout << "1. Exhaustive (Brute-Force) Approach" << endl;
      cout << "2. Dynamic Programming Approach " << endl;
      cout << "3. Approximation Algorithms (Greedy Approach)" << endl;
      cout << "4. Integer Linear Programming Algorithm (ILP)" << endl;
      cout << "5. Exit" << endl;

      cin >> choice;

    if (choice == 1){
        cout << " Select the dataset (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)";
        cin>> datasetChoice;
        loadData(datasetChoice,truck);

        std::vector<Pallet> bestSolution;
        int maxProfit = ExhaustiveBF(truck.pallets, truck.truckCapacity, bestSolution);

        cout << "Max profit: " << maxProfit << endl;
        cout << "Selected pallets:"<< endl;
        int totalWeight = 0;
        for (const auto& p : bestSolution) {
            cout << " - Pallet " << p.id << " (Weight: " << p.weight << ", Profit: " << p.profit << ")"<< endl;
            totalWeight += p.weight;
        }
        cout << "Total weight: " << totalWeight << endl;
    }

    else if (choice == 2) {
        cout << " Select the dataset (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)";
        cin>> datasetChoice;
        loadData(datasetChoice,truck);

        bool usedItems[truck.pallets.size()] = {false};
        unsigned int maxProfit = knapsackDP(truck.pallets, truck.truckCapacity, usedItems);

        cout << "Max profit (Dynamic Programming): " << maxProfit << endl;
        cout << "Selected pallets:" << endl;
        int totalWeight = 0;

        // Exibe as paletes selecionadas
        for (size_t i = 0; i < truck.pallets.size(); ++i) {
            if (usedItems[i]) {
                cout << " - Pallet " << truck.pallets[i].id << " (Weight: " << truck.pallets[i].weight
                     << ", Profit: " << truck.pallets[i].profit << ")" << endl;
                totalWeight += truck.pallets[i].weight;
            }
        }
        cout << "Total weight: " << totalWeight << endl;

    }

    else if (choice == 3) {
        cout << " Select the dataset (1, 2, 3, 4)";
        cin>> datasetChoice;
        loadData(datasetChoice,truck);
    }

    else if (choice == 4) {
        cout << " Select the dataset (1, 2, 3, 4)";
        cin>> datasetChoice;
        loadData(datasetChoice,truck);
    }
  }

}
