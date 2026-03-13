#include <iostream>
#include "header.h"

using namespace std;

int main(){
    int L[10] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    RadixSort(L,n);
    Afisare(L,n);
    return 0;
}