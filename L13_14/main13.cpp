#include <iostream>
#include <limits.h>
#include <stack>

#define inf INT_MAX

using namespace std;

void Floyd_Warshall(int a[4][4], int P[4][4],int n){
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0; j<n;j++)
                if(a[i][k] + a[k][j] < a[i][j]){
                    a[i][j] = a[i][k] + a[k][j];
                    P[i][j] = P[k][j];
                }
}


int main(){
    stack<int> s;
    int n=4;
    int A[4][4] = {
        {0,3,inf,7},
        {8,0,2,inf},
        {5,inf,0,1},
        {2,inf,inf,0}
    };
    int P[4][4];
    for(int i = 0;i<4;i++)
        for(int j = 0;j<4;j++)
            if(A[i][j] == inf || i == j)
                P[i][j] = -1;
            else
                P[i][j] = i;
    Floyd_Warshall(A,P,n);
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j)
                continue;
            cout<<"Drumul de la "<<i<<" la "<<j<<" este:";
            s.push(j);
            int aux = j;
            while(i != P[i][aux] && P[i][aux] != -1){
                s.push(P[i][aux]);
                aux = P[i][aux];
            }
            while(!s.empty()){
                int aux;
                aux = s.top();
                s.pop();
                cout<<aux<<' ';
            }
            cout<<endl;
        }
    }


}
