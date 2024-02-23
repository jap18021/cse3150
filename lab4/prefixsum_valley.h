#ifndef PREFIXSUM_VALLEY_H
#define PREFIXSUM_VALLEY_H

#include <vector>

std::vector<int> generate_balanced_list(int n);
std::vector<int> scramble_list(std::vector<int>& list);
int find_lowest_depth(const std::vector<int>& list);
std::pair<std::vector<int>, std::vector<int>> split_list(const std::vector<int>& list);
std::vector<int> create_final_list(std::vector<int>& P1, std::vector<int>& P2);

#endif // PREFIXSUM_VALLEY_H