#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Pallet.h"
#include "TruckandPallet.h"

using namespace std;

/**
 * @brief Implementação da função que carrega dados dos arquivos CSV para TruckandPallet.
 *
 * @param datasetId Identificador do dataset a carregar.
 * @param data Estrutura onde os dados serão armazenados.
 *
 * @details
 * Lê arquivo TruckAndPallets_<datasetId>.csv para capacidade e número de pallets,
 * e Pallets_<datasetId>.csv para dados dos pallets.
 */
void loadData(string datasetId, TruckandPallet& data) {

    if (datasetId.size() == 1) datasetId = "0" + datasetId;

    string truckFile = "../datasets/TruckAndPallets_" + datasetId + ".csv";
    string palletsFile = "../datasets/Pallets_" + datasetId + ".csv";

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