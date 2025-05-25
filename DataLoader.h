#ifndef DATALOADER_H
#define DATALOADER_H

#include "TruckandPallet.h"
#include <string>

using namespace std;

/**
* @brief Carrega dados dos arquivos CSV para a estrutura TruckandPallet.
*
* @param datasetId Identificador do dataset a carregar (ex: "01", "02", ...).
* @param data Referência para a estrutura onde os dados serão armazenados.
*
* @details
* Lê arquivos TruckAndPallets_<datasetId>.csv e Pallets_<datasetId>.csv
* e preenche os dados do camião e lista de pallets.
*/
void loadData(string datasetId, TruckandPallet& data);

#endif //DATALOADER_H
