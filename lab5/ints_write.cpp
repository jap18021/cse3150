#include <iostream>
#include <vector>
#include "ints_write.h"

// for some reason i ran into errors using namespace here

std::ostream &operator<<(std::ostream &os, const std::vector<int> & my_vector) {
    for (auto const & i: my_vector) {
        os << i << " ";
    }

    return os;
};

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<int>> & my_matrix) {
    for ( auto row_vector : my_matrix ) {
        os << row_vector << "\n" ;
    }
   
    return os;
}