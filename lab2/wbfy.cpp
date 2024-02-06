#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "wbfy.h"

void fisher_yates_shuffle(std::vector<int>& list) {
    srand(time(0));
    for (int i = list.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(list[i], list[j]);
    }
}

bool is_well_balanced(const std::vector<int>& list) {
    int sum = 0;
    for (int i : list) {
        sum += i;
        if (sum < 0) return false;
    }
    return sum == 0;
}

double generate_and_test(int n) {
    std::vector<int> list(2 * n);
    std::fill(list.begin(), list.begin() + n, 1);
    std::fill(list.begin() + n, list.end(), -1);

    int total = 0;
    int well_balanced = 0;

    for (int i = 0; i < 7000; ++i) {
        fisher_yates_shuffle(list);
        ++total;
        if (is_well_balanced(list)) ++well_balanced;
    }

    return static_cast<double>(well_balanced) / total;
}