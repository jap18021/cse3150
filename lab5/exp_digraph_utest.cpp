#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>
#include <algorithm> 
#include <iterator>
#include "exp_digraph.h"
#include "ints_read_vector.h"
#include "ints_read_matrix.h"

// first  test case is to ensure that values are being properly written, read, and processed
// second test case is to ensure the algorithm's correctness

TEST_CASE("Integers to Matrix works properly") {
    SUBCASE("Base Case 1") {
        istringstream basecase1("5");
        vector<vector<int>> matrix = ints_read_matrix(basecase1);
        REQUIRE(matrix.size() == 1);
        REQUIRE(matrix[0].size() == 1);
        CHECK(matrix[0][0] == 5);
    }

    SUBCASE("Base Case 2") {
        istringstream basecase2("1 2 3\n4 5 6\n7 8 9");
        vector<vector<int>> matrix = ints_read_matrix(basecase2);
        REQUIRE(matrix.size() == 3);
        CHECK(matrix[0][0] == 1);
        CHECK(matrix[0][1] == 2);
        CHECK(matrix[0][2] == 3);
        CHECK(matrix[1][0] == 4);
        CHECK(matrix[1][1] == 5);
        CHECK(matrix[1][2] == 6);
        CHECK(matrix[2][0] == 7);
        CHECK(matrix[2][1] == 8);
        CHECK(matrix[2][2] == 9);
    }

    SUBCASE("Small Matrix") {
        istringstream smallMatrix("0 1 2\n4 5 6\n7 8 9");
        vector<vector<int>> matrix = ints_read_matrix(smallMatrix);
        CHECK(0 == matrix[0][0]);
        CHECK(1 == matrix[0][1]);
        CHECK(2 == matrix[0][2]);
        CHECK(3 == matrix.size());
        CHECK(3 == matrix[0].size());
        CHECK(3 == matrix[2].size());
    }

    SUBCASE("Uneven Matrix") {
        istringstream unevenMatrix("1 2 3\n4 5\n6 7 8");
        vector<vector<int>> matrix = ints_read_matrix(unevenMatrix);
        REQUIRE(matrix.size() == 3);
        REQUIRE(matrix[0].size() == 3);
        REQUIRE(matrix[1].size() == 2);
        REQUIRE(matrix[2].size() == 3);
        CHECK(matrix[0][0] == 1);
        CHECK(matrix[0][1] == 2);
        CHECK(matrix[0][2] == 3);
        CHECK(matrix[1][0] == 4);
        CHECK(matrix[1][1] == 5);
        CHECK(matrix[2][0] == 6);
        CHECK(matrix[2][1] == 7);
        CHECK(matrix[2][2] == 8);
    }

    SUBCASE("Vector Test 1") {
        istringstream Vec1("1 2 3 4 5");
        vector<int> vec = ints_read(Vec1);
        REQUIRE(vec.size() == 5);
        CHECK(vec[0] == 1);
        CHECK(vec[1] == 2);
        CHECK(vec[2] == 3);
        CHECK(vec[3] == 4);
        CHECK(vec[4] == 5);
    }

    SUBCASE("Vector Test 2") {
        istringstream Vec2("1 2 3\n4 5 6\n7 8 9");
        vector<int> vec = ints_read(Vec2);
        REQUIRE(vec.size() == 9);
        CHECK(vec[0] == 1);
        CHECK(vec[1] == 2);
        CHECK(vec[2] == 3);
        CHECK(vec[3] == 4);
        CHECK(vec[4] == 5);
        CHECK(vec[5] == 6);
        CHECK(vec[6] == 7);
        CHECK(vec[7] == 8);
        CHECK(vec[8] == 9);
    }

    SUBCASE("Vector Test 3") {
        istringstream Vec3("5 6 7 8 9");
        vector<int> vec = ints_read_one_line(Vec3);
        REQUIRE(vec.size() == 5);
        CHECK(vec[0] == 5);
        CHECK(vec[1] == 6);
        CHECK(vec[2] == 7);
        CHECK(vec[3] == 8);
        CHECK(vec[4] == 9);
    }
}

TEST_CASE("Expensive Digraph Algorithm Tests") {
    SUBCASE("Small Graph Test") {
        vector<vector<int>> DNeg1 = {{0, -1}, {1, 0}};
        vector<vector<int>> DZero = {{1, 1}, {1, 1}};
        vector<vector<int>> DPos1 = {{0, 1}, {0, 0}};

        expensiveDigraphExactPaths(DNeg1, DZero, DPos1);
        CHECK(DZero[0][1] == 0);
        CHECK(DZero[0][0] == 0);
        CHECK(DZero[1][1] == 0);
        CHECK(DZero[1][0] == 0);
        CHECK(DPos1[0][0] == 1);
        CHECK(DPos1[0][1] == 1);
        CHECK(DPos1[1][0] == 1);
        CHECK(DPos1[1][1] == 1);
        CHECK(DNeg1[0][0] == -1);
        CHECK(DNeg1[0][1] == -1);
        CHECK(DNeg1[1][0] == -1);
        CHECK(DNeg1[1][1] == -1);
    }

    SUBCASE("Medium Graph Test"){
        vector<vector<int>> DNeg1 = {
            {0, 0, 0, 0, -1, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0}
        };
        vector<vector<int>> DPos1 = {
            {0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0}
        };
        vector<vector<int>> DZero = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0}
        };

        expensiveDigraphExactPaths(DNeg1, DZero, DPos1);
        CHECK(DZero[0][1] == 0);
        CHECK(DPos1[0][1] == 1);
        CHECK(DNeg1[0][1] == -1);
    }

    SUBCASE("Large Graph Test"){
        vector<vector<int>> DNeg1 = {
                                            {0, -1, 1, 1, 1, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                                        };
        vector<vector<int>> DZero = {
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                                };
        vector<vector<int>> DPos1 = {
                                    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                                };
                                
        expensiveDigraphExactPaths(DNeg1, DZero, DPos1);
        CHECK(DZero[0][1] == 0);
        CHECK(DPos1[0][1] == 1);
        CHECK(DNeg1[0][1] == -1);
    }
}