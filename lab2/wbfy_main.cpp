#include <iostream>
#include <cstdlib>
#include <ctime>
#include "wbfy.h"

int runSimulation(int n, int total) {
    int wellBalancedCount = 0;

    for (int run = 0; run < total; ++run) {
        std::vector<int> sequence(2 * n);
        std::fill(sequence.begin(), sequence.begin() + n, 1);
        std::fill(sequence.begin() + n, sequence.end(), -1);
        fisher_yates_shuffle(sequence);
        if (is_well_balanced(sequence)) {
            wellBalancedCount++;
        }
    }

    return wellBalancedCount;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int n = 6; 
    int total = 100000;  

    int wellBalancedCount = runSimulation(n, total);

    double proportionWellBalanced = static_cast<double>(wellBalancedCount) / total;
    std::cout << "total: " << total << std::endl;
    std::cout << "validated: " << wellBalancedCount << std::endl;
    std::cout << "Proportion: " << proportionWellBalanced << std::endl;

    return 0;
}