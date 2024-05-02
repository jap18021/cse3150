#ifndef __HEADER_H
#define __HEADER_H

using namespace std;
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

struct double_vector {
    int id;
    vector<double> values;

    double_vector(const double_vector &dv) : id(dv.id), values(dv.values) {
    };
    double_vector() : id(0) {}
    double_vector(const vector<double> &vals, int id) : values(vals), id(id) {}
};

struct my_distance {
    int id_1, id_2;
    double cos_distance;

    my_distance() : id_1(-1), id_2(-1), cos_distance(0.0) {};
    my_distance(const my_distance & dist) : id_1(dist.id_1), id_2(dist.id_2), cos_distance(dist.cos_distance) {};
    my_distance(int id_1, int id_2, double cos_distance) : id_1(id_1), id_2(id_2), cos_distance(cos_distance) {};
};

double square(const double & d);
double dot_product(const double_vector & one, const double_vector & two) ;
double magnitude(const double_vector & my_vector);
double cosine_distance(const double_vector & one, const double_vector & two);


#endif