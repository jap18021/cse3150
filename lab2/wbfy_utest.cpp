#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <algorithm>
#include "doctest.h"
#include "wbfy.h"

TEST_CASE("Testing Fisher-Yates Shuffle") {
    std::vector<int> list = {1, 1, -1, -1};
    std::vector<int> copy = list;
    fisher_yates_shuffle(list);
    CHECK(std::is_permutation(list.begin(), list.end(), copy.begin()));
}

TEST_CASE("Testing is_well_balanced") {
    std::vector<int> list1 = {1, -1, 1, -1};
    CHECK(is_well_balanced(list1) == true);

    std::vector<int> list2 = {1, 1, -1, -1};
    CHECK(is_well_balanced(list2) == false);
}
TEST_CASE("Testing generate_and_test") {
    double proportion = generate_and_test(1);
    CHECK(proportion == doctest::Approx(1.0).epsilon(0.01)); // For n = 1, all lists should be well-balanced

    proportion = generate_and_test(2);
    CHECK(proportion == doctest::Approx(0.5).epsilon(0.01)); // For n = 2, half of the lists should be well-balanced
}

TEST_CASE("Testing large n") {
    int n = 10;
    std::vector<int> list(2 * n);
    std::fill(list.begin(), list.begin() + n, 1);
    std::fill(list.begin() + n, list.end(), -1);
    fisher_yates_shuffle(list);
    // We can't predict the result, but the function should at least not crash
    CHECK_NOTHROW(is_well_balanced(list));
}