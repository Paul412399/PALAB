#include "header.h"
#include <iostream>

using namespace std;

void sortare_secventa_bitona(int a[], int i , int d, bool s){
    if(d == 2){
        compara_si_schimba(a[i], a[i+1], s);
    }
    else{
        for(int j = i; j < i+d/2; j++){
            compara_si_schimba(a[j], a[j+d/2], s);
        }
        sortare_secventa_bitona(a,i, d/2, s);
        sortare_secventa_bitona(a,i+d/2, d/2,s);
    }
}

void compara_si_schimba(int &x, int &y, bool s){
    if(s == false){
        if(x > y)
            swap(x,y);
    }
    else{
        if(x < y)
            swap(x,y);
    }
}

void batcher_sort(int a[], int i, int d, int s){
    if(d==2){
        compara_si_schimba(a[i], a[i+1], s);
    }
    else{
        batcher_sort(a,i,d/2,false); // crescator pe jumatatea stanga
        batcher_sort(a,i+d/2, d/2, true); // descrescator pe jumatatea dreapta
        sortare_secventa_bitona(a,i,d,s);
    }
}

void afis(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout<<a[i]<<' ';
}