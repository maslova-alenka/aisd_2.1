#ifndef TREE_INCLUDE_RAND_H
#define TREE_INCLUDE_RAND_H

#include "tree.h"
#include <vector>

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

Set generate_rand_set(size_t size) {
    Set set;
    for (size_t i = 0; i < size; ++i) {
        set.insert(lcg());
    }
    return set;
}

std::vector<int> generate_rand_vector(size_t size) {
    std::vector<int> vec;
    for (size_t i = 0; i < size; ++i) {
        vec.push_back(lcg());
    }
    return vec;
}


#endif