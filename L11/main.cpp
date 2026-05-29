#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int rez[100];



struct Digraf{
    int n;
    vector<int> lad[50];
    int indegree[50];
};

void sortareTopologica(Digraf D, int rez[]){
    queue<int> C;

    for(int i = 0; i < D.n; i++){
        if(D.indegree[i] == 0)
            C.push(i);
    }

    int idx = 0;

    while(!C.empty()){
        int u = C.front();
        C.pop();

        rez[idx++] = u;
        for(int v : D.lad[u]){
            D.indegree[v]--;
            if(D.indegree[v] == 0)
                C.push(v);
        }
        }   
    }


    void adaugareMuchie(Digraf &D, int x, int y){
        D.lad[x].push_back(y);
        D.indegree[y]++;
    }

int main(){
    Digraf D;
    D.n = 5;
    for(int i=0; i<D.n;i++){
        D.lad[i].clear();
        D.indegree[i] = 0;
    }
  
    adaugareMuchie(D,1,2);
    adaugareMuchie(D,1,4);
    adaugareMuchie(D,2,3);
    adaugareMuchie(D,4,5);
    adaugareMuchie(D,3,4);

    sortareTopologica(D,rez);
    for(int i = 0; i < D.n; i++)
        cout<<rez[i]<<' ';
    return 0;

}
