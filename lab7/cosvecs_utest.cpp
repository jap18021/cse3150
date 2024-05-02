#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "cosvecs.h"

TEST_CASE("Functions"){

    SUBCASE("Square"){
        double array[5];
        for(int i = 0; i < 5; i++)
            {array[i] = (double)i*i;}
        for(int i = 0; i < 5; i++)
            {CHECK(square(i) == array[i]);}
    }

    SUBCASE("Dot product"){
        double_vector v1, v2;
        /*v1.x = 3.0;
        v1.y = 7.0;

        v2.x = 10.0;
        v2.y = 6.0;*/

        v1.values  = {3.0, 7.0};
        v2.values = {10.0, 6.0};

        CHECK(dot_product(v1, v2) == 72.0);
    }

    SUBCASE("Magnitude"){
        double_vector v1;
        /*v1.x = 3.0;
        v1.y = 3.0;*/
        v1.values = {3.0, 3.0};
        CHECK(magnitude(v1) == sqrt(18));


    }
    SUBCASE("Cosine Distance"){
        double_vector v1, v2;
        /*v1.x = 3.0;
        v1.y = 7.0;
        v2.x = 10.0;
        v2.y = 6.0;*/

        v1.values  = {3.0, 7.0};
        v2.values = {10.0, 6.0};

        double res = cosine_distance(v1, v2);

        CHECK(res < 0.63);
        CHECK(res > 0.62);
    }

}