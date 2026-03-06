#include <iostream>
#include "header.h"
#include <chrono>

using namespace std;

int main(){
    int v[] = {83, 15, 23, 12, 8, 95, 44 ,65};
    int s = 0;
    int d = 7;
    auto start = chrono::high_resolution_clock::now();
    quickSort(v,0,7);
    auto end =  chrono::high_resolution_clock::now();
    auto duration = (end - start);
    auto us = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    const float ms_fractional = static_cast<float>(us.count()) / 1000;
    afisare(v,d);
    return 0;
}