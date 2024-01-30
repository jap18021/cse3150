#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

int test_arr1[] = {0, 0} // BOOL TRUE for both
int test_arr2[] = {1, -1, 1, -1} // BOOL FALSE for non_positive_prefix
int test_arr3[] = {-1, 1, -1, 1} // BOOL FALSE for non_negative_prefix
int test_arr4[] = {1, -1, -1, 1} // BOOL FALSE for both

TEST_CASE("Combined Nonpositive and Nonnegative prefix functions") {
    SECTION("Test case 1: True for both cases") {
        CHECK(non_positive_prefix(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0])));
        CHECK(non_negative_prefix(test_arr1, sizeof(test_arr1) / sizeof(test_arr1[0])));
    }

    SECTION("Test case 2: {1, -1, 1, -1}") {
        CHECK_FALSE(non_positive_prefix(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0])));
        CHECK(non_negative_prefix(test_arr2, sizeof(test_arr2) / sizeof(test_arr2[0])) == true);
    }

    SECTION("Test case 3: {-1, 1, -1, 1}") {
        CHECK(non_positive_prefix(test_arr3, sizeof(test_arr3) / sizeof(test_arr3[0])) == true);
        CHECK_FALSE(non_negative_prefix(test_arr3, sizeof(test_arr3) / sizeof(test_arr3[0])));
    }

    SECTION("Test case 4: False for both cases") {
        CHECK_FALSE(non_positive_prefix(test_arr4, sizeof(test_arr4) / sizeof(test_arr4[0])));
        CHECK_FALSE(non_negative_prefix(test_arr4, sizeof(test_arr4) / sizeof(test_arr4[0])));
    }
}
