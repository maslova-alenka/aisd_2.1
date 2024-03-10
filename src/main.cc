#include "../include/tree.h"
#include "../include/task.h"

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

    return 0;

}