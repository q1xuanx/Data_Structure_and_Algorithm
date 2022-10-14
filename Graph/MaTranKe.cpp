#include<bits/stdc++.h>
using namespace std;

void addZero(int a[][1001], int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
}
void printArr (int a[][1001], int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int a[1001][1001];
int main(){
    int n, m;
    cin >> n >> m;
    addZero(a,n);
    for (int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    printArr(a,n);
    return 0;
}

//input 
// 5 9
// 1 2 
// 1 3 
// 1 4 
// 2 3 
// 2 4 
// 2 5 
// 3 4 
// 3 5 
// 4 5 
// output
// 0 1 1 1 0 
// 1 0 1 1 1
// 1 1 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0
