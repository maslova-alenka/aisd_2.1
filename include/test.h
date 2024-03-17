#ifndef TREE_INCLUDE_TEST_H
#define TREE_INCLUDE_TEST_H

#include <algorithm>
#include <chrono>

#include "rand.h"

const size_t num_attempts = 100;
const size_t num_attempts2 = 1000;

template<typename T>
double average_filling_time(T generate_func, size_t lenght) {
    double total_time = 0.0;

    for (int i = 0; i < num_attempts; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        generate_func(lenght);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_time += duration.count();
    }

    double average_time = total_time / num_attempts;
    return average_time;
}

//tree
double average_search_set(Set& set) {
	double total_time = 0.0;
	for (size_t i = 0; i < num_attempts2; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		set.contains(lcg());
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> duration = end - start;
		total_time += duration.count();
	}
	double average_time = total_time / num_attempts2;
	return average_time;
}

double average_insert_set(Set& set) {
    double total_time = 0.0;

    for (int i = 0; i < num_attempts2; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        set.insert(lcg());
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_time += duration.count();
    }

    double average_time = total_time / num_attempts2;
    return average_time;
}

double average_erase_set(Set& set) {
    double total_time = 0.0;

    for (int i = 0; i < num_attempts2; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        set.erase(lcg());
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_time += duration.count();
    }

    double average_time = total_time / num_attempts2;
    return average_time;
}

//vector
double average_search_vector(const std::vector<int>& vec) {
    double total_time = 0.0;
    for (size_t i = 0; i < num_attempts2; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        std::find(vec.begin(), vec.end(), lcg());
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_time += duration.count();
    }
    double average_time = total_time / num_attempts2;
    return average_time;
}

double average_insert_vector(std::vector<int> vec, int index) {
    double total_time = 0.0;
    for (size_t i = 0; i < num_attempts2; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        vec.insert(vec.begin() + index, lcg());
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_time += duration.count();
    }
    double average_time = total_time / num_attempts2;
    return average_time;
}

double average_erase_vector(std::vector<int>& vec,int index) {
    double total_time = 0.0;
    for (size_t i = 0; i < num_attempts2; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        vec.erase(vec.begin() + index);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_time += duration.count();
    }
    double average_time = total_time / num_attempts2;
    return average_time;
}

#endif