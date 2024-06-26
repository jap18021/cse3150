#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "stl_vectors.h"

TEST_CASE("Vector Testing") {

    SUBCASE("Vector Test") {
        std::vector<int_vector> actual_vector1 = read_vector_file("vectors_2d.txt");
        std::vector<int_vector> expected_vector1;
        std::vector<int> expected_value_list = {1, 2, 1, 3, 1, 4, 2, 7, 9, 11};
        for (int i=0; i < (expected_value_list.size()/2); i ++) {
            int_vector new_inner;
            new_inner.id = i;
            new_inner.from = expected_value_list[i * 2];
            new_inner.to = expected_value_list[i * 2 + 1];
            expected_vector1.push_back(new_inner);
        }
        
        for (int i=0; i < actual_vector1.size(); i++) {
            CHECK_EQ(actual_vector1[i].id, expected_vector1[i].id);
            CHECK_EQ(actual_vector1[i].from, expected_vector1[i].from);
            CHECK_EQ(actual_vector1[i].to, expected_vector1[i].to);
        }
    };

    SUBCASE("No Vectors") {
        std::vector<int_vector> empty_vector = read_vector_file("empty.txt");
        CHECK(empty_vector.size()==0);
    };
};

TEST_CASE("Build Test") {

    SUBCASE("Constructor") {
        int_vector expected_vector1;
        expected_vector1.id = -1;
        expected_vector1.from = 0;
        expected_vector1.to = 0;
        int_vector actual_vector1;

        CHECK_EQ(expected_vector1.id, actual_vector1.id);
        CHECK_EQ(expected_vector1.from, actual_vector1.from);
        CHECK_EQ(expected_vector1.to, actual_vector1.to);
    
        int_vector expected_vector2;
        expected_vector2.id = 0;
        expected_vector2.from = -1;
        expected_vector2.to = -1;

        int_vector actual_vector2;

        CHECK_FALSE(expected_vector2.id==actual_vector2.id);
        CHECK_FALSE(expected_vector2.from==actual_vector2.from);
        CHECK_FALSE(expected_vector2.to==actual_vector2.to);
    };

    SUBCASE("Copy Constructor") {
        int_vector original_vector1;
        int_vector new_vector1 = original_vector1;

        CHECK_EQ(original_vector1.id, new_vector1.id);
        CHECK_EQ(original_vector1.from, new_vector1.from);
        CHECK_EQ(original_vector1.to, new_vector1.to);
        int_vector original_vector2;
        original_vector2.id = 10000;
        original_vector2.from = 432;
        original_vector2.to = 43252;

        int_vector new_vector2 = original_vector2;

        CHECK_EQ(original_vector2.id, new_vector2.id);
        CHECK_EQ(original_vector2.from, new_vector2.from);
        CHECK_EQ(original_vector2.to, new_vector2.to);
    };

};