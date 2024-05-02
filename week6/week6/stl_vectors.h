#ifndef __VECTOR_EXTRA_H_
#define __VECTOR_EXTRA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct int_vector {
    int id;
    int from;
    int to;
    int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {};
    int_vector() : id(-1), from(0), to(0) {};
    void print_int_vector() {std::cout << from << " " << to;};
    void print_int_vector_rev() {std::cout << to << " " << from;};
};
std::vector<int_vector> read_vector_file(const std::string& file_name);
std::vector<int> linetovec(const std::string& line);
void print_stlvec(const std::vector<int_vector> &vector);
void print_stlvec_rev(const std::vector<int_vector> &vector);

#endif