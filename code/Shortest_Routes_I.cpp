#define MAXN 200005

int n, m;
int dis[MAXN];
vector<pair<int, int>> G[MAXN];

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	dis[s] = 0;
	
	while (pq.size()) {
		auto now = pq.top();
		pq.pop();
		
		if (dis[now.S] != now.F)
			continue;
			
		for (auto e: G[now.S]) {
			if (dis[e.F] > now.F + e.S) {
				dis[e.F] = now.F + e.S;
				pq.push({dis[e.F], e.F});
			}
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}
	
	dijkstra(1);
	
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	cout << endl;
}