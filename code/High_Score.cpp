#define MAXN 2505
#define MAXM 5005
int n, m;
int dis[MAXN];
bool has_neg_cir[MAXN];
bitset<MAXN> vis;
vector<pair<int, int>> G[MAXN];
pair<pair<int, int>, int> E[MAXM];
 
bool find_neg_cir(int i, int sum, int start) {
	if (vis[i])
		return (i == start && sum < 0);
	vis[i] = true;
	
	bool res = false;
	for (pii e: G[i]) {
		res |= find_neg_cir(e.F, sum + e.S, start);
	}
	return res;
}
 
void dfs(int i) {
	vis[i] = true;
	
	for (pii e: G[i]) {
		if (!vis[e.F])
			dfs(e.F);
	}
}
 
bool check(int i, int j) {
	vis.reset();
	dfs(i);
	
	return vis[j];
}
 
void sol() {
	cin >> n >> m;
	for (int i = 0, a, b, v; i < m; i++) {
		cin >> a >> b >> v;
		G[a].pb({b, -v});
		E[i] = {{a, b}, -v};
	}
	
	for (int i = 1; i <= n; i++)
		sort(G[i].begin(), G[i].end(), [](pair<int, int> _a, pair<int, int> _b) {
			return _a.S < _b.S;
		});
	
	MEM(dis, 0x3f);
	dis[1] = 0;
	
	for (int i = 1; i <= n; i++) {
		vis.reset();
		has_neg_cir[i] = find_neg_cir(i, 0, i);
		
		if (has_neg_cir[i]) {
			if (check(1, i) && check(i, n)) {
				cout << -1 << endl;
				return;
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++)	{
			int a = E[j].F.F;
			int b = E[j].F.S;
			int v = E[j].S;
			if (dis[b] > dis[a] + v) {
				dis[b] = dis[a] + v;
			}
		}
	}
	cout << -dis[n] << endl;
}
 