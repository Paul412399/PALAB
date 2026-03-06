#include <iostream>
#include "header.h"

using namespace std;

void interclasare(int a[], int s, int d, int m, int temp[]){
    int i = s;
    int j = m+1;
    int k = -1;
    while(i<=m && j <=d){
        if(a[i] < a[j])
            temp[++k] = a[i++];
        else
            temp[++k] = a[j++];
    }
    while(i<=m)
        temp[++k] = a[i++];
    while(j<=d)
        temp[++k] = a[j++];
}

void mergeSort(int a[], int s, int d){
    if(s<d){
        static int temp[101];
        int m =(s+d)/2;
        mergeSort(a,s,m);
        mergeSort(a,m+1,d);
        interclasare(a,s,d,m, temp);
        for(int i = s; i<= d;i++)
            a[i] = temp[i-s];
    }
}// sa se faca fara temp ca parametru

void afisare(int a[], int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
}

void quickSort(int a[], int s, int d){
    int k;
    if(s < d){
        partitionare(a,s,d,k);
        quickSort(a,s,k-1);
        quickSort(a,k+1,d);
    }
}  

    void partitionare(int a[], int s, int d, int &k){
        int x = a[s];
        int i = s+1;
        int j = d;
        while(i <= j){
            while(a[i] < x)
                i++;
            while(a[j] > x)
                j--;
            if(i < j){
                swap(a[i], a[j]);
                i++;
                j--;
            }  
        }
        k = i-1;
        a[s] = a[k];
        a[k] = x;
    }