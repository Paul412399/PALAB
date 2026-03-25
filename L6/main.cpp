#include <iostream>
#include <climits>

using namespace std;

void Afis(float a[], int n){
    for(int i = 0; i < n; i ++){
        cout<<a[i]<<' ';
    }
}


void rucsac_1(int w[], int p[], int n, int M, float x[]){
    int vizitat[3] = {0};
    float C = 0; 
    for(int i = 0; i < n; i++){
        x[i] = 0;
    }
    bool ok = true;
    while((C < M) && ok){
        double best = -1;
        int poz = -1;
        for(int i = 0; i < n; i++){
            if(p[i] > best && vizitat[i] != 1){
                best = p[i];
                poz = i;
            }
        }
         vizitat[poz] = 1;
        if(poz != -1){
        if( C+w[poz] <= M){
            x[poz] = 1;
            C += w[poz];
        }
        else{
            x[poz] = (float)(M-C)/w[poz];
            C = M;
        }}
        else{
            ok = false;
        }
    }
}


void rucsac_2(int w[], int p[], int n, int M, float x[]){
    float C = 0; 
    for(int i = 0; i < n; i++){
        x[i] = 0;
    }
    double pw[101];
    for(int i = 0; i < n; i++)
        pw[i] = (double)p[i] / w[i];
    bool ok = true;
    while((C < M) && ok){
        double best = -1;
        int poz = -1;
        for(int i = 0; i < n; i++){
            if(pw[i] > best){
                best = pw[i];
                poz = i;
            }
        }
        pw[poz] = -1;
        if(poz != -1){
        if( C+w[poz] <= M){
            x[poz] = 1;
            C += w[poz];
        }
        else{
            x[poz] = (float)(M-C)/w[poz];
            C = M;
        }}
        else{
            ok = false;
        }
    }
}

int main(){ 
    int w[] = {6, 4 , 8};
    int p[] = {3, 4, 6};
    int n = 3;
    int M = 10;
    float x[3] ={0};
    rucsac_1(w,p,n,M,x);
    double total = 0;
    for(int i = 0; i < n; i++){
        total += x[i] * p[i];
    }
    Afis(x,3);
    cout<<"\n"<<total<<endl;

    int w2[] = {6,4,8};
    int p2[] = {3,4,6};
    rucsac_2(w2,p2,n,M,x);
    total = 0;
    for (int i = 0; i < n; i++){
        total += x[i] * p2[i];
    }
    Afis(x,3);
    cout<<"\n"<<total;
    
    return 0;
}