#include <iostream>
#include <fstream>
#include <vector>
#define MAX 100
#define link "C:/Users/Admin/Desktop/2180605539-PhamHoangNhan-UCS-GTS1-GTS2/inputgts2.txt"
using namespace std;
struct Graph
{
    int n, a[MAX][MAX];
};
int read(Graph &g)
{
    fstream in(link);
    if (!in)
    {
        cerr << "Error !"
             << "\n";
        return 0;
    }
    in >> g.n;
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            in >> g.a[i][j];
        }
    }
    return 1;
}
bool check(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            return false;
    }
    return true;
}
void GTS1(Graph g, int x, vector<pair<int,int>> &b, int &total)
{
    int traver[MAX];
    for (int i = 0; i < g.n; i++)
    {
        traver[i] = -1;
    }
    int mn = 1e9 + 1, cost = 0, idx = 0, t = x;
    while (1)
    {
        mn = 1e9 + 1;
        traver[x] = 1;
        for (int i = 0; i < g.n; i++)
        {
            if (x == i)
                continue;
            if (g.a[x][i] < mn and traver[i] == -1 and x != i)
            {
                mn = g.a[x][i];
                idx = i;
            }
        }
        cost += mn;
        int te = x;
        x = idx;
        traver[idx] = 1;
        b.push_back(make_pair(te,idx));
        if (check(traver, g.n))
        {
            break;
        }
    }
    total = cost + g.a[x][t];
}
void GTS2 (Graph g, int b[], int num){
    int mn = 1e9 + 1;
    vector<pair<int,int>> ans;
    for (int i = 0; i < num; i++){
        vector<pair<int,int>> temp;
        int total = 0;
        GTS1(g,b[i],temp,total);
        if (total < mn){
            mn = total;
            ans = temp;
        }
    }
    cout << "Chi phi: " <<  mn << "\n";
    cout << "Hanh trinh: ";
    for (int i = 0; i < ans.size(); i++){
        cout << "(" << ans[i].first << ", " << ans[i].second << ") ";
    }
}
int main()
{
    Graph g;
    int x, b[MAX];
    if (read(g))
    {
        cout << "Moi nhap so dinh can xet: ";
        cin >> x;
        for (int i = 0; i < x; i++){
            cin >> b[i];
        }
        GTS2(g,b,x);
    }
    return 0;
}