vt<vt<int>> a(100001);
vt<int> dist(100001);
void bfs(int v){
	vt<bool> check(100001);
	queue<int> q;
	dist[v] = 0;
	int length = -1;
	check[v] = true;
	q.push(v);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i : a[u]){
			if (!check[i]){
				check[i] = true;
				dist[i] = dist[u] + 1;
				q.push(i);
			}
		}
	}
}
