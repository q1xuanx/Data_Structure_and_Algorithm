#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define MAX 100
#define link "C:/Users/Admin/Desktop/2180605539-Pham HoangNhan-ToMau/input.txt"
struct Graph
{
    int n, a[MAX][MAX];
};
int read (Graph &g){
    fstream in (link);
    if (!in){
        cerr << "Error !\n";
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
void print(Graph g){
    cout << "So dinh cua do thi: " << g.n << "\n";
    for (int i = 0; i < g.n; i++){
        for (int j = 0; j < g.n; j++){
            cout << g.a[i][j] << " ";
        }
        cout << "\n";
    }
}
void create (Graph g, int b[])
{
    for (int i = 0; i < g.n; i++){
        int s = 0;
        for (int j = 0; j < g.n; j++){
            s += g.a[i][j];
        }
        b[i] = s;
    }
}
bool check(int a[], Graph g){
    for (int i = 0; i < g.n; i++){
        if (a[i] == -1) return false;
    }
    return true;
}
void color(Graph g)
{
    int b[MAX];
    create(g,b);
    int sortArr[MAX];
    for (int i = 0; i < g.n; i++){
        int mx = 0, idx = 0;
        for (int j = 0; j < g.n; j++){
            if (b[j] > mx and b[j] != -1){
                mx = b[j];
                idx = j;
            }
        }   
        sortArr[i] = idx;
        b[idx] = -1;
    }   
    int color[MAX], num = 1;
    for (int i = 0; i < g.n; i++){
        color[i] = -1;
    }
    for (int i = 0; i < g.n; i++){
        if (color[sortArr[i]] != -1){
            continue;
        }
        int te = sortArr[i];
        color[sortArr[i]] = num;
        vector<int> t;
        for (int j = 0; j < g.n; j++){
            if (g.a[te][j] == 0 and color[j] == -1 and t.size() == 0){
                color[j] = num;
                t.push_back(te);
                te = j;
            }
            else if (g.a[te][j] == 0 and color[j] == -1 and t.size() > 0){
                bool check = true;
                for (int k = 0; k < t.size(); k++){
                    if (g.a[t[k]][j] == 1){
                        check = false;
                        break;
                    }
                }
                if (check){
                    color[j] = num;
                    t.push_back(te);
                    te = j;
                }
            }
        }
        if (check(color,g)) break;
        num++;
    }
    vector<int> answer[MAX];
    for (int i = 0; i < g.n; i++){
        answer[color[i]].push_back(i);
    }
    cout << "So mau can to: " << num << "\n";
    for (int i = 1; i <= num; i++){
        cout << "Color " << i << ": ";
        for (auto j : answer[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}
int main()
{
    Graph g;
    if (read(g)){
        print(g);
        color(g);
    }
}
/*
10
0 1 1 1 1 0 1 1 0 0
1 0 1 0 1 1 0 0 0 0
1 1 0 1 0 1 0 0 0 0
1 0 1 0 0 1 1 0 1 0
1 1 0 1 0 1 0 1 0 0
0 1 1 1 1 0 0 0 0 0
1 0 0 1 0 0 0 1 1 1
1 0 0 0 1 0 1 0 0 1
0 0 0 1 0 0 1 0 0 0
0 0 0 0 0 0 1 1 0 0
*/
