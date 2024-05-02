#include "stl_vectors.h"

std::vector<int_vector> read_vector_file(const std::string& file_name) {

    std::ifstream inp_vector_file(file_name);
    std::vector<int_vector> stlvec;
    if (!inp_vector_file) {
        return stlvec;
    }

    std::string line;
    int int_vector_id=0;
    int_vector inner_vector;
    while (std::getline(inp_vector_file, line)) {
        std::vector<int> line_values = linetovec(line);

        int from = line_values[0];
        int to = line_values[1];
        inner_vector.id = int_vector_id;
        inner_vector.from = from;
        inner_vector.to = to; 
        stlvec.push_back(inner_vector);
        int_vector_id++;
    }
    return stlvec;
}

std::vector<int> linetovec(const std::string& line) {
    std::vector<int> out;
    std::istringstream iss(line);
    int value;
    while (iss >> value) {
        out.push_back(value);
    }
    return out;
}

void print_stlvec(const std::vector<int_vector> &vector) {
    for (auto inner_vector : vector) {
        std::cout << inner_vector.id << ": ";
        inner_vector.print_int_vector();
        std::cout << std::endl;
    }
}

void print_stlvec_rev(const std::vector<int_vector> &vector) {
    for (int vector_idx = vector.size()-1; vector_idx >= 0; vector_idx--) {
        int_vector inner_vector = vector[vector_idx];
        std::cout << inner_vector.id << ": ";
        inner_vector.print_int_vector();
        std::cout << std::endl;
    }
}