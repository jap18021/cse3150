#include <iostream>
#include "prefixsum_valley.h"

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> list = generate_balanced_list(n);
    std::vector<int> scrambled_list = scramble_list(list);
    auto [P1, P2] = split_list(scrambled_list);
    std::vector<int> result = create_final_list(P1, P2);

    std::cout << "Final list: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}