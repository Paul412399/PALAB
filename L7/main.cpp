#include <iostream>

using namespace std;

void RucsacDiscret(int M, int w[], int p[], int n, int DP[][101]){
    for(int i = 0;i <= n;i++)
        for(int j = 0; j <= M; j++)
            DP[i][j] = 0;
    for(int i = 1; i<=n; i++)
        for(int j=1; j<=M; j++)
        {
            if(w[i] > j)
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = max(DP[i-1][j], p[i] + DP[i-1][j-w[i]]);
        }
}

void ConstruireSol(int DP[][101], int n, int M, int x[], int w[]){
    if(n == 0)
        return;
    if(DP[n][M] == DP[n-1][M])
    {
        x[n] = 0;
        ConstruireSol(DP, n-1, M, x, w);
    }
    else{
        x[n] = 1;
        ConstruireSol(DP, n-1, M - w[n], x, w);

    }
}

void AfisareMatrice(int DP[][101], int n, int M){
    for(int i = 0; i<=n;i++){
        for(int j=0;j<=M;j++)
            cout<<DP[i][j]<<' ';
    cout<<endl;
    }
}

int main(){
    int DP[101][101];
    int w[101] = {0, 1 , 3 ,4 , 5};
    int p[101] = {0, 1, 4, 5 , 7};
    int n = 4;
    int M = 7;
    int x[101] = {0};
    RucsacDiscret(M, w, p, n, DP);
    ConstruireSol(DP, n, M, x, w);
    AfisareMatrice(DP,n ,M );
    cout<<endl;
    for(int i=1; i<=n;i++)
        cout<<x[i]<<' ';
}
