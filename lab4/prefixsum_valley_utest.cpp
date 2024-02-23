#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefixsum_valley.h"

TEST_CASE("Testing prefixsum_valley") {
    SUBCASE("Simple test case 1: Check if the lowest prefix sum really is the lowest prefix sum") {
        std::vector<int> list = {1, 1, 1, -1, -1, -1, -1};
        CHECK(find_lowest_depth(list) == -1);
    }

    SUBCASE("Simple test case 2: Check if the list is correctly scrambled") {
        std::vector<int> list = generate_balanced_list(3);
        std::vector<int> scrambled_list = scramble_list(list);
        CHECK(list.size() == scrambled_list.size());
        std::sort(list.begin(), list.end());
        std::sort(scrambled_list.begin(), scrambled_list.end());
        CHECK(list == scrambled_list);
    }

    SUBCASE("Simple test case 3: Check if the final list starts with +1 and ends with -1") {
        std::vector<int> list = generate_balanced_list(3);
        std::vector<int> scrambled_list = scramble_list(list);
        auto [P1, P2] = split_list(scrambled_list);
        std::vector<int> final_list = create_final_list(P1, P2);
        CHECK(final_list.front() == 1);
        CHECK(final_list.back() == -1);
    }

    SUBCASE("Edge case 1: Check with a list of size 2") {
        std::vector<int> list = generate_balanced_list(1);
        CHECK(find_lowest_depth(list) == -1);
    }

    SUBCASE("Edge case 2: Check with a list of size 1") {
        std::vector<int> list = generate_balanced_list(0);
        CHECK(find_lowest_depth(list) == -1);
    }

    SUBCASE("Edge case 3: Check if the final list is correctly formed when the list size is 1") {
        std::vector<int> list = generate_balanced_list(1);
        std::vector<int> scrambled_list = scramble_list(list);
        auto [P1, P2] = split_list(scrambled_list);
        std::vector<int> final_list = create_final_list(P1, P2);
        CHECK(final_list.size() == 2);
        CHECK(final_list[0] == 1);
        CHECK(final_list[1] == -1);
    }
}
