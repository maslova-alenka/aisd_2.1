#ifndef TREE_INCLUDE_TASK_H
#define TREE_INCLUDE_TASK_H

#include "tree.h"
#include <iostream>


Set union_set(Set& set1, Set& set2) {
	Set set;
	for (auto el1 : set1)
		set.insert(el1);
	for (auto el2 : set2)
		set.insert(el2);
	return set;
}

Set difference(Set& set1, Set& set2) {
	Set set = set1;
	for (auto el : set2)
		set.erase(el);
	return set;
}
Set symmetric_difference(Set& set1, Set& set2) {
	Set dif1 = difference(set1, set2);
	Set dif2 = difference(set2, set1);
	return union_set(dif1, dif2);
}
#endif