#include <iostream>
#include "../include/Array.h"

int main() {
    Array<int> arr(2);

    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(15); // sprawdza realloc

    std::cout << "Size: " << arr.get_size() << std::endl;

    for(int i = 0; i < arr.get_size(); i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    // test modyfikacji
    arr[1] = 99;

    std::cout << "After change: ";
    for(int i = 0; i < arr.get_size(); i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}