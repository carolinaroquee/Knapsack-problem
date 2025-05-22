//
// Created by carol on 20/05/2025.
//

#ifndef TRUCKANDPALLETE_H
#define TRUCKANDPALLETE_H

#include "Pallet.h"
#include <vector>

using namespace std;

struct TruckandPallet {
    int truckCapacity;
    int numPallets;
    vector<Pallet> pallets;
};
#endif //TRUCKANDPALLETE_H
