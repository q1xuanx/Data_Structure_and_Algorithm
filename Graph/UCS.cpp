#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
#define link "C:/Users/Admin/Desktop/2180605539-PhamHoangNhan-UCS-GTS1-GTS2/inputucs.txt"
int size = 0;
struct Graph{
    int a[MAX][MAX], n;
};
struct  P_Queue
{
    int l, w;
};
int read(Graph &g){
    fstream in(link);
    if (!in){
        cerr << "\nError !\n";
        return 0;
    }
    in >> g.n;
    for (int i = 0; i < g.n; i++){
        for (int j = 0; j < g.n; j++){
            in >> g.a[i][j];
        }
    }
    return 1;
}
void push(P_Queue q[], int v, int cost){
    if (size + 1 > MAX){
        return;
    }
    q[size].l = v;
    q[size].w = cost;
    size++;
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (q[i].w > q[j].w){
                swap(q[i],q[j]);
            }
        }
    }
}
void pop(P_Queue q[]){
    if (size == 0) return;
    for (int i = 0; i < size-1; i++){
        q[i].l = q[i+1].l;
        q[i].w = q[i+1].w;
    }
    size--;
}
void UCS(Graph g, int start, int end){
    P_Queue q[MAX];
    push(q,start,0);
    int visted[MAX];
    for (int i = 0; i < g.n; i++){
        visted[i] = -1;
    }
    visted[q[0].l] = 0;
    while(size > 0){
        int vis = q[0].l, cost = q[0].w;
        pop(q);
        for (int i = 0; i < g.n; i++){
            if (g.a[vis][i] != 0 and visted[i] == -1){
                push(q,i,cost + g.a[vis][i]);
                visted[i] = cost + g.a[vis][i];
            }
            else if (g.a[vis][i] != 0 and visted[i] != -1){
                if (cost + g.a[vis][i] < visted[i]){
                    pop(q);
                    push(q,i,cost + g.a[vis][i]);
                    visted[i] = cost + g.a[vis][i];
                }
            }
        }
    }
    cout << "Minimum cost: " << visted[end] << " ";
}

int main(){
    Graph g;
    if (read(g)){
        int s,e;
        cout << "Nhap dinh xuat phat: "; cin >> s;
        cout << "Nhap dinh ket thuc: "; cin >> e;
        UCS(g,s,e);
    }
    return 0;
}