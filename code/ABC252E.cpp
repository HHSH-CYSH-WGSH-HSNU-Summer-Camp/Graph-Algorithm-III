#define MAXN 200005
#define F first
#define S second

int n, m;
int dis[MAXN];
int from[MAXN];
vector<pair<int, pair<int, int>>> G[MAXN];

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	MEM(dis, 0x3f);
	dis[1] = 0;
	pq.push({0, 1});
	
	while (pq.size()) {
		auto now = pq.top();
		pq.pop();
		
		if (dis[now.S] != now.F)
			continue;
		
		for (auto e: G[now.S]) {
			if (dis[e.F] > now.F + e.S.F) {
				dis[e.F] = now.F + e.S.F;
				from[e.F] = e.S.S;
				pq.push({dis[e.F], e.F});
			}
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1, a, b, c; i <= m; i++) {
		cin >> a >> b >> c;
		G[a].pb({b, {c, i}});
		G[b].pb({a, {c, i}});
	}
	dijkstra(1);
	
	for (int i = 2; i <= n; i++)
		cout << from[i] << " ";
	cout << endl;
}