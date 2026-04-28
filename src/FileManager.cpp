#include <fstream>
#include "FileManager.h"

template <typename T>
Array<T> loadFromFile(const std::string filename){
    std::ifstream in(filename);
    if(!in.is_open()){
        return NULL;//blad ladowania
    }

    int n;
    in >> n;
    Array<T> arr(n);

    for(int i = 0; i<n; i++){
        T value;
        in>>value;
        arr.push_back(value);
    }

    in.close();
    return arr;
}