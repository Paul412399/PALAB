#include <iostream>
#include "header.h"
#include <chrono>
#include <unordered_set>

using namespace std;

int main(){
    static int v [100001];
    static int a1[100001];
    static int a2[100001];
    unordered_set<int> vazute;
    int generate = 0;
    int n = 100000;
    while (generate < n){
        int nr = rand();
        if(vazute.find(nr) == vazute.end()){
            vazute.insert(nr);
            v[generate++] = nr;
        }
    }
    for(int i = n-1; i > 0; i--){
        int j = rand() % (i+1);
        swap(v[i], v[j]);
    }
    for(int i = 0;i <100001;i++){
        a1[i] = v[i];
        a2[i] = v[i];
    }
    int s = 0;
    int d = 7;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(v,0,n-1);
    auto end =  chrono::high_resolution_clock::now();
    auto duration = (end - start);
    auto us = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    float ms_fractional = static_cast<float>(us.count()) / 1000;
    cout<<"MergeSort\n";
    cout<< "Duration = " << us.count() <<' '<<ms_fractional << "ms" << endl;
    start = chrono::high_resolution_clock::now();
    quickSort(a1,0,n-1);
    end =  chrono::high_resolution_clock::now();
    duration = (end - start);
    us = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    ms_fractional = static_cast<float>(us.count()) / 1000;
    cout<<"QuickSort1\n";
    cout<< "Duration = " << us.count() <<' '<<ms_fractional << "ms" << endl;
    start = chrono::high_resolution_clock::now();
    quickSort2(a2,0,n-1);
    end =  chrono::high_resolution_clock::now();
    duration = (end - start);
    us = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    ms_fractional = static_cast<float>(us.count()) / 1000;
    cout<<"QuickSort2\n";
    cout<< "Duration = " << us.count() <<' '<<ms_fractional << "ms" << endl;
    
    return 0;
}