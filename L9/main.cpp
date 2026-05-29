#include <iostream>
#include <chrono>

using namespace std;

int nrPasi = 0;
int nrPasiPlus = 0;
int sumvect(int a[], int n){
    int s = 0;
    for(int i=0;i<n;i++)
        s+=a[i];
    return s;
}

void afisare(int a[] , int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}

void bkt(int s, int k, int r, int w[], int x[], int M, int n){
    nrPasi++;
    if(k>=n)
        return;
    x[k] = 1;
    if(s+w[k] == M)
        afisare(x,n);
    else{
            bkt(s+w[k], k+1, r-w[k], w,x,M,n);
        x[k] = 0;
            bkt(s, k+1, r-w[k], w,x,M,n);
    }
}

void bktplus(int s, int k, int r, int w[], int x[], int M, int n){
    nrPasiPlus++;
    if(k>=n)
        return;
    x[k] = 1;
    if(s+w[k] == M)
        afisare(x,n);
    else{
        if(s+w[k]+w[k+1] <= M)
            bktplus(s+w[k], k+1, r-w[k], w,x,M,n);
        x[k] = 0;
        if(s+(r-w[k]) >= M && s+w[k+1] <=M)  
            bktplus(s, k+1, r-w[k], w,x,M,n);
    }
}

int main(){
    int n = 25; int M = 50;
    int w[25] = {0};
    int x[25] = {0};
    for(int i=0;i<n;i++)
        w[i] = i+1;
    int r = sumvect(w,n);
    bktplus(0,0,r,w,x,M,n);
    bkt(0,0,r,w,x,M,n);
    cout<<nrPasi;
    cout<<endl<<nrPasiPlus;
    cout<<"\nEste de "<<nrPasi/nrPasiPlus<<" mai rapid\n";
    return 0;
}