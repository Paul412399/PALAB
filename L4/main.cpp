#include "header.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>

using namespace std;

int main(){
    int v[100001];
    int d = 65536;
    for(int i = 0; i < d; i++)
        v[i] = rand() % 1000;
    cout<<"Numere aleatorii\n";
    auto start = std::chrono::high_resolution_clock::now();
    batcher_sort(v,0,d,false);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = (end - start);
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(duration); // Microsecond (as int)
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration); // Milliseconds (as int)
    float ms_fractional = static_cast<float>(us.count()) / 1000;         // Milliseconds (as float)
    std::cout << "Duration = " << us.count() << "µs (" << ms_fractional << "ms)" << std::endl;
    start = chrono::high_resolution_clock::now();
    batcher_sort(v,0,16384,false);
    end = chrono::high_resolution_clock::now();
    duration = (end-start);
    us = chrono::duration_cast<chrono::microseconds>(duration);
    ms_fractional = static_cast<float>(us.count()) / 1000;
    cout<<"Deja sortat crescator = " << ms_fractional << " ms\n";
    batcher_sort(v,0,d,true);
    start = chrono::high_resolution_clock::now();
    batcher_sort(v,0,d, false);
    end = chrono::high_resolution_clock::now();
    duration = (end - start);
    us = chrono::duration_cast<chrono::microseconds>(duration);
    ms_fractional = static_cast<float>(us.count()) / 1000;
    cout<<"Deja sortat descrescator: " << ms_fractional << " ms\n";
    return 0;
}