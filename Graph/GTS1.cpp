#include <iostream>
#include <fstream>
#define MAX 100
#define link "C:\\Users\\Admin\\Desktop\\2180605539-PhamHoangNhan-UCS-GTS1-GTS2\\inputgts1.txt"
using namespace std;
struct Graph
{
    int n, a[MAX][MAX];
};
int read (Graph &g){
    ifstream in (link);
    if (!in){
        cerr << "Error !" << "\n";
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
bool check(int a[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] == -1) return false;
    }
    return true;
}
void GTS1(Graph g, int x){
    int traver[MAX];
    for (int i = 0; i < g.n; i++){
        traver[i] = -1;
    }
    int mn = 1e9+1, cost = 0, idx = 0, t = x;
    cout << "Hanh trinh: ";
    while(1){
        mn = 1e9+1;
        cout <<"(" << x  << ",";
        traver[x] = 1;
        for (int i = 0; i < g.n; i++){
            if (x == i) continue;
            if (g.a[x][i] < mn and traver[i] == -1 and x != i){
                mn = g.a[x][i];
                idx = i;
            }
        }
        cost += mn;
        x = idx;
        traver[idx] = 1;
        cout << x << ") ";
        if (check(traver,g.n)){
            break;
        }
    }
    cout << "\nChi phi: " << cost + g.a[x][t];
}

int main(){
    Graph g;
    int x;
    cout << "Nhap dinh can xet: "; cin >> x;
    if (read(g)){
        GTS1(g,x);
    }
    return 0;
}