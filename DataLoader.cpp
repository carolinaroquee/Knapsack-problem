#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Pallet.h"
#include "TruckandPallet.h"

using namespace std;

void loadData(string datasetId, TruckandPallet& data) {


    string truckFile = "../datasets/TruckAndPallets_0" + datasetId + ".csv";
    string palletsFile = "../datasets/Pallets_0" + datasetId + ".csv";

    ifstream file1(truckFile);
    string line;
    getline(file1, line);
    getline(file1, line);

    stringstream ss(line);
    string truckCapacity;
    string truckPallets;

    getline(ss, truckCapacity, ','); // Capacidade da truck
    data.truckCapacity = stoi(truckCapacity);

    getline(ss,truckPallets); // Número de paletes
    data.numPallets = stoi(truckPallets);

    file1.close();


    ifstream file2(palletsFile);
    getline(file2, line);

    data.pallets.clear();

    while (getline(file2, line)) {
        stringstream ss(line);
        Pallet pallet;
        string palletNum;
        string palletWeight;
        string palletProfit;


        getline(ss, palletNum, ',');
        pallet.id = stoi(palletNum);

        getline(ss, palletWeight, ',');
        pallet.weight = stoi(palletWeight);

        getline(ss, palletProfit, '\0');
        pallet.profit = stoi(palletProfit);

        data.pallets.push_back(pallet);
    }

    file2.close();

}