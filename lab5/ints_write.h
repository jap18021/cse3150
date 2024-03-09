#ifndef _INTS_WRITE_H_
#define _INTS_WRITE_H_

#include <iostream>
#include <vector>

// for some reason i ran into errors using namespace here

std::ostream &operator<<(std::ostream &os, const std::vector<int> & my_vector);
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<int>> & my_matrix);

#endif