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
        static int temp[100001];
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

void quickSort2(int a[], int s,int d){
    int k;
    while(s < d){
        partitionare(a,s,d,k);
        if(k-s > d-k){
            quickSort2(a,k+1,d);
            d = k-1;
        }
        else{
            quickSort2(a,s,k-1);
            s = k+1;
        }
    }
}

    void partitionare(int a[], int s, int d, int &k) {
    int x = a[s];
    int i = s + 1;
    int j = d;
    while (i <= j) {
        while (i <= d && a[i] < x) i++;
        while (j >= s + 1 && a[j] > x) j--;
        
        if (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        } else {
            break; 
        }
    }
    k = i-1;
    swap(a[s], a[k]);
}