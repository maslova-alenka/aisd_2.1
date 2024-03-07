#include "../include/tree.h"

int main() {
    Set set;

    set.insert(5);
    set.insert(3);
    set.insert(7);

    set.print(); //  3 5 7

    std::cout << "Contains 3: " << set.contains(3) << std::endl; //  Contains 3: 1

    set.erase(5);

    set.print(); //  5 7

    return 0;

}