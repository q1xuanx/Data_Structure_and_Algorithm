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
const int inf = 1e9;
#define pb push_back
class Graph{
    int v;
    vector<list<int>> adj;
    public:
        Graph(int v);
        void addE(int v, int w);
        void BFS (int s);
};
Graph::Graph(int v){
    this-> v = v;
    adj.resize(v);
}
void Graph::addE(int v, int w){
    adj[v].pb(w);
}
void Graph::BFS(int s){
    vector<bool> visted;
    visted.resize(v,false);
    
    list<int> queue;
    visted[s] = true;
    queue.pb(s);
    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (auto adjecent : adj[s]){
            if (!visted[adjecent]){
                visted[adjecent] = true;
                queue.pb(adjecent);
            }
        }
    }
}
int main(){
    Graph g(4);
    g.addE(0,1);
    g.addE(0, 2);
    g.addE(1, 2);
    g.addE(2, 0);
    g.addE(2, 3);
    g.addE(3, 3);
    cout << "BFS ";
    g.BFS(2);
}

// More info: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
