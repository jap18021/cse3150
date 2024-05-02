#include "cosvecs.h"
#include <cmath>

double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    double dp = 0.0;
    int n = one.values.size();
    for (size_t i = 0; i < n; ++i) {
        dp += one.values[i] * two.values[i];
    }
    return dp;
}

double magnitude(const double_vector & my_vector) {
    double sum = 0.0;
    for (double value : my_vector.values) {
        sum += square(value);
    }
    return sqrt(sum);
};

double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot_prod = dot_product(one,two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod/(one_magnitude*two_magnitude) ;
    if (d > 1.0) 
        d = 1.0;
    if (d < -1.0)
        d = -1.0;

    return acos(d);
}