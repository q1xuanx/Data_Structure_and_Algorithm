#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define fast ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rever(i, a) for (int i = a; i > 0; i--)
#define pb push_back
#define vt vector
// CODE HERE !
int n;
vt<vt<int>> g(100001);
bool check[100001];
void DFS (int v){
	check[v] = true;
	cout << v + 1 << " ";
	for (auto i : g[v]){
		if (!check[i]) DFS(i);
	}
}
void BFS(){
	vt<bool> check(100001);
	queue<int> q;
	check[0] = true;
	q.push(0);
	while (!q.empty()){
		int u = q.front();
		cout << u + 1 << " ";
		q.pop();
		for (auto i : g[u]){
			if (!check[i]){
				check[i] = true;
				q.push(i);
			}
		}
	}
	
}
void solve(){
	int n,m; cin >> n >> m;
	for (int j = 0; j < m; j++){
		int x,y; cin >> x >> y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	BFS();
	cout << "\n";
	DFS(0);
}
// Run Code 
int main()
{
	// freopen("word.in", "r", stdin);
	// freopen("word.out", "w", stdout);
	fast;
    ll test_case = 1;
	//cin >> test_case;
    while (test_case-->0)
    {
        solve();
    }
	return 0;
}
 
/*
-6 -2 0 4 35 #000000#000000
*/
