#include <bits/stdc++.h>
using namespace std;

vector<int> a[1001];
int main(){
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int x : a[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
