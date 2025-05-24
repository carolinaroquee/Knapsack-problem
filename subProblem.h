#ifndef SUBPROBLEM_H
#define SUBPROBLEM_H

struct subProblem {
    unsigned int profit;  // lucro total obtido
    unsigned int count;   // número de pallets usados

    // Operador de comparação para decidir qual estado é "melhor"
    // Retorna true se este estado for "menor" (pior) do que o outro
    bool operator<(const subProblem &other) const {
        if (profit != other.profit)
            return profit < other.profit;   // maior lucro é melhor
        return count > other.count;         // menor número de pallets é melhor
    }
};

#endif // SUBPROBLEM_H

