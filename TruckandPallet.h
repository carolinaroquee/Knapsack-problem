#ifndef TRUCKANDPALLETE_H
#define TRUCKANDPALLETE_H

#include "Pallet.h"
#include <vector>

using namespace std;

/**
 * @struct TruckandPallet
 * @brief Estrutura que guarda os dados do camião e dos paletes.
 */
struct TruckandPallet {
    int truckCapacity;          /**< Capacidade máxima do camião */
    int numPallets;             /**< Número de paletes disponíveis */
    vector<Pallet> pallets;      /**< Vetor com os paletes */
};
#endif //TRUCKANDPALLETE_H
