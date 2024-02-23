#include "prefixsum_valley.h"
#include <algorithm> // for std::shuffle
#include <random> // for std::default_random_engine
#include <ctime> // for std::time

// Function to generate a balanced list
std::vector<int> generate_balanced_list(int n) {
    std::vector<int> list(2*n + 1);
    std::fill(list.begin(), list.begin() + n, 1);
    std::fill(list.begin() + n, list.end(), -1);
    return list;
}

// Function to scramble the list using Fisher-Yates algorithm
std::vector<int> scramble_list(std::vector<int>& list) {
    std::default_random_engine engine(std::time(0));
    for (int i = list.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> distribution(0, i);
        std::swap(list[i], list[distribution(engine)]);
    }
    return list;
}

// Function to find the lowest depth
int find_lowest_depth(const std::vector<int>& list) {
    int lowest_depth = 0;
    int sum = 0;
    for (int i = 0; i < list.size(); i++) {
        sum += list[i];
        if (sum < lowest_depth) {
            lowest_depth = sum;
        }
    }
    return lowest_depth;
}

// Function to split the list
std::pair<std::vector<int>, std::vector<int>> split_list(const std::vector<int>& list) {
    int lowest_depth_index = std::distance(list.begin(), std::min_element(list.begin(), list.end()));
    std::vector<int> P1(list.begin(), list.begin() + lowest_depth_index + 1);
    std::vector<int> P2(list.begin() + lowest_depth_index + 1, list.end());
    return std::make_pair(P1, P2);
}

// Function to create the final list
std::vector<int> create_final_list(std::vector<int>& P1, std::vector<int>& P2) {
    P1.pop_back(); // Remove the last -1 of P1
    std::vector<int> final_list;
    final_list.insert(final_list.end(), P2.begin(), P2.end());
    final_list.insert(final_list.end(), P1.begin(), P1.end());
    return final_list;
}