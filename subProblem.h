#ifndef SUBPROBLEM_H
#define SUBPROBLEM_H

/**
 * @struct subProblem
 * @brief Representa um estado do problema auxiliar para a programação dinâmica.
 *
 * Usado para armazenar lucro total e número de paletes usados numa dada subsolução,
 * com operador de comparação para escolher a melhor solução.
 */
struct subProblem {
    unsigned int profit;    /**< Lucro total obtido */
    unsigned int count;     /**< Número de paletes usados */

    /**
     * @brief Operador de comparação para decidir qual estado é "melhor".
     *
     * Retorna true se este estado for "menor" (pior) do que o outro,
     * considerando maior lucro melhor e menor número de paletes melhor.
     *
     * @param other Outro estado para comparar.
     * @return true Se este estado for pior que o outro.
     */
    bool operator<(const subProblem &other) const {
        if (profit != other.profit)
            return profit < other.profit;
        return count > other.count;
    }
};

#endif // SUBPROBLEM_H

