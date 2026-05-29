#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

#define NMAX 101
#define inf INT_MAX

int D[NMAX];

struct comp{
    bool operator()(int a, int b){
        return D[a] > D[b];
    }
};

struct Digraf{
    int n;
    vector<int> lad[NMAX];
};

void Dijkstra(Digraf G, int L[][6], int nod_initial, int P[]){
    int n = G.n;
    priority_queue<int, vector<int>, comp> C;
    for(int i=0; i<n;i++){
        D[i] = inf;
        P[i] = -1;
    }
    D[nod_initial] = 0;
    C.push(nod_initial);
        while(!C.empty()){
            int u = C.top();
            C.pop();

            for(int v : G.lad[u]){
                if(D[u] + L[u][v] < D[v]){
                    D[v] = D[u] + L[u][v];
                    P[v] = u;
                    C.push(v);
                }
            }
        }
    }


void adaugareMuchie(Digraf &D, int x, int y){
    D.lad[x].push_back(y);
}

void Afis(int P[], int v){
    if(P[v] == -1){
        cout<<v<<' ';
        return;
    }
    Afis(P, P[v]);
    cout<<v<<' ';
}

int main(){
    Digraf G;
    G.n = 6;
    for(int i=0; i<G.n;i++){
        G.lad[i].clear();
    }
    int L[6][6] ={
    {0, 2, 4, inf, inf, inf},
    {inf, 0, 1, 7, inf, inf},
    {inf, inf, 0, inf, 3, inf},
    {inf, inf, inf, 0, inf, 1},
    {inf, inf, inf, 2, 0, 5},
    {inf, inf, inf, inf, inf, 0}
    };
    int P[6];

    adaugareMuchie(G,0,1);
    adaugareMuchie(G,0,2);
    adaugareMuchie(G,1,2);
    adaugareMuchie(G,1,3);
    adaugareMuchie(G,2,4);
    adaugareMuchie(G,4 ,3 );
    adaugareMuchie(G,4 ,5 );
    adaugareMuchie(G,3 ,5 );
    for(int i=0; i<G.n;i++){
        Dijkstra(G,L ,i ,P);
        for(int j=0;j<G.n;j++)
            if(i != j && D[j] != inf){
                Afis(P,j);
                cout<<endl;
            }
    }
}
