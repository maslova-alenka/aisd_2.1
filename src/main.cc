#include "../include/tree.h"
#include "../include/task.h"
#include "../include/rand.h"
#include "../include/test.h"

int main() {
    Set set;

    set.insert(5);
    set.insert(3);
    set.insert(7);

	std::cout << "set: ";
    set.print(); //  3 5 7

    std::cout << "contains 3: " << set.contains(3) << std::endl; //  Contains 3: 1

    set.erase(5);
	std::cout << "set erase: ";
    set.print(); //  5 7
	std::cout << std::endl;

	Set set1;
	Set set2;

	set1.insert(40);
	set1.insert(83);
	set1.insert(91);
	set1.insert(34);
	set1.insert(61);
	set1.insert(18);
	set1.insert(22);
	set1.insert(41);

	set2.insert(2);
	set2.insert(34);
	set2.insert(55);
	set2.insert(22);

	Set union_tree = union_set(set1, set2);

	Set difference_tree = difference(set1, set2);

	Set difference_set= symmetric_difference(set1, set2);

	std::cout << "set1: ";
	for (auto el : set1)
		std::cout << el << " ";
	std::cout << std::endl;

	std::cout << "set2: ";
	for (auto el : set2)
		std::cout << el << " ";
	std::cout << std::endl;

	std::cout << "union_set: ";
	union_tree.print();
	std::cout << "difference_set: ";
	difference_tree.print();
	std::cout << "symmetric_difference_set: ";
	difference_set.print();

	//Set set3 = generate_rand_set(100000);
	//std::vector<int> vec = generate_rand_vector(100000);

	//std::cout << "average_fiiling_time_set: " << average_filling_time(generate_rand_set, 100000) << std::endl;
	//std::cout << "average_fiiling_time_vector: " << average_filling_time(generate_rand_vector, 100000) << std::endl;
	//std::cout << "average_search_set: " << average_search_set(set3) << std::endl;
	//std::cout << "average_search_vector: " << average_search_vector(vec) << std::endl;
	//std::cout << "average_insert_set: " << average_insert_set(set3) << std::endl;
	//std::cout << "average_insert_vector: " << average_insert_vector(vec,10) << std::endl;
	//std::cout << "average_erase_set: " << average_erase_set(set3) << std::endl;
	//std::cout << "average_erase_vector: " << average_erase_vector(vec,10) << std::endl;

    return 0;

}