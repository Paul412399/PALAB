#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
    vector<int> board;
    int nivel;
    int dir;

    Node() : board({}), nivel(0), dir(-1){};

    Node(vector<int> x, int nivel){
        this->board = x;
        this-> nivel = nivel;
        this-> dir = -1;
    }
};


int g_str(Node a){
    int count = 0;
    for(int i = 0; i<a.board.size(); i++){
        if(a.board[i] != i+1 && a.board[i] != 0)
            count++;
    }
    return count;
};

struct Comparator{
    bool operator()(Node a,Node b){
        return g_str(a) >= g_str(b);
    }
};


void print_solutie(Node v){
    for(int i=0;i<v.board.size();i++){
        cout<<v.board[i]<<' ';
    }
}

/* 
   1
2     3
   4             */ /* Numarul reprezinta directia din care a fost mutat zero-ul*/

void expand(priority_queue<Node, vector<Node>, Comparator> &A, Node V){
    Node c;
    auto poz = find(V.board.begin(), V.board.end(), 0);
    int idx;
    if (poz != V.board.end()){
        idx = poz - V.board.begin();
    }
    
    int n = 3;

    if(idx % n != 0 && V.dir != 2){
        c = V;
        swap(c.board[idx], c.board[idx-1]);
        c.nivel++;
        c.dir = 3;
        A.push(c);        
    }
    if(idx > n && V.dir != 1){
        c = V;
        swap(c.board[idx], c.board[idx-3]);
        c.nivel++;
        c.dir = 4;
        A.push(c);
    }
    if((idx - 2) % n != 0 && V.dir != 3){
        c = V;
        swap(c.board[idx], c.board[idx + 1]);
        c.nivel++;
        c.dir = 2;
        A.push(c);
    }
    if(idx < n * 2 && V.dir != 4){
        c = V;
        swap(c.board[idx], c.board[idx + 3]);
        c.nivel++;
        c.dir = 1;
        A.push(c);
    }
}

void perspico(Node start){ 
    priority_queue<Node, vector<Node>, Comparator> A;
    A.push(start);
    while(A.empty()==0){
        Node v = A.top();
        A.pop();
        if(g_str(v) == 0){
            print_solutie(v);
            return;
        }
        expand(A,v);
    }
}

int main(){
    vector<int> x ={1,2,3,4,0,6,7,5,8};
    Node start(x,0);
    perspico(start);
}