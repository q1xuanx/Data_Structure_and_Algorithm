#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int a[n][n];
    vector<pair<int,int>> edge;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] and i < j){
                edge.push_back(make_pair(i,j));
            }
        }
    }
    for (int i = 0; i < edge.size(); i++){
        cout << edge[i].first << " " << edge[i].second << "\n";
    }
}
// INPUT
5
0 1 1 1 0 
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
