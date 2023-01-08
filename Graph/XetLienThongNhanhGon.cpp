#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define fast ios_base::sync_with_stdio(0), cin.tie(0);
#define debugg cout << "\nDebug...OK !\n"
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rever(i, a) for (int i = a; i > 0; i--)
#define pb push_back
#define vt vector
const int inf = 5e3 + 5;
#define MAX 101
// CODE HERE !
int a[MAX][MAX] = {0};
void traver(int a[][MAX], int check[MAX], int i, int n){
	for (int j = 1; j <= n; j++){
		if (a[i][j] != 0 and check[i] != check[j]){
			check[j] = check[i];
			traver(a,check,j,n);
		}
	}
}
void solve()
{
	int n,m; cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x,y; cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	int ans = 0;
	int check[MAX] = {};
	for (int i = 1; i <= n; i++){
		if (check[i] == 0){
			ans++;
			check[i] = ans;
			traver(a,check,i,n);
		}
	}
	cout << ans;
}
// Run Code 
int main()
{
	// freopen("word.in", "r", stdin);
	// freopen("word.out", "w", stdout);
	fast;
    int test_case = 1;
	//cin >> test_case;
    while (test_case--)
    {
        solve();
    }
	return 0;
}

/*
-6 -2 0 4 35 #000000#000000
*/
