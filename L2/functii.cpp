#include <iostream>
#include "header.h"
#include <list>
#include <cmath>

using namespace std;

int getD(int L[], int n){
    int maxx = L[0];
    for(int i = 1;i<n;i++)
        if(L[i] > maxx)
            maxx = L[i];
    int count = 0;
    while(maxx){
        count++;
        maxx = maxx/10;
    }
    return count;
}

int getCifra(int x, int i){
    static int putere = 1;
    static int i_anterior = 0;
    if(i > i_anterior)
        putere = putere * 10;
    i_anterior = i;
    return (x/putere)%10;

}

void Afisare(int L[], int n){
    for(int i = 0; i < n; i++)
        cout<<L[i]<<' ';
}


void RadixSort(int L[], int n){
    list<int> pachete[10];
    int d = getD(L,n);
    for(int i = 0; i<d;i++){
        // Impachetare
        for(int j = 0; j<n;j++){
            int cifra = getCifra(L[j], i);
            pachete[cifra].push_back(L[j]);
        }
        // Despachetare
        int index = 0;
        for(int j = 0; j < 10; j++){
            for(int numar : pachete[j]){
                L[index++] = numar;
            }
            pachete[j].clear();
        }
    }
}

// de modificat a.i sa sorteze si siruri de caractere   