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
void solve(){
	int n; cin >> n;
	vt<int> a(n);
	priority_queue<int> p;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > 0){
			p.push(a[i]);
		}else if (p.size() != 0 and a[i] == 0){
			ans += p.top();
			p.pop();
		}
	}
	cout << ans << "\n";
}
// Run Code 
int main()
{
	// freopen("speeding.in", "r", stdin);
	// freopen("speeding.out", "w", stdout);
	fast;
    long long test_case = 1;	
	cin >> test_case;
    while (test_case-->0)
    {
		solve();
	}
	return 0;
}
 
/*
test case: 
5
5
3 3 3 0 0
6
0 3 3 0 0 3
7
1 2 3 0 4 5 0
7
1 2 5 0 4 3 0
5
3 1 0 0 4
*/
