#define MAXN 200005

int n, m;
int dis[MAXN], cnt[MAXN], minf[MAXN], maxf[MAXN];
vector<pair<int, int>> G[MAXN];

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	dis[s] = 0;
	cnt[s] = 1;
	
	while (pq.size()) {
		auto now = pq.top();
		pq.pop();
		
		if (dis[now.S] != now.F)
			continue;
			
		for (auto e: G[now.S]) {
			if (dis[e.F] > now.F + e.S) {
				dis[e.F] = now.F + e.S;
				cnt[e.F] = cnt[now.S];
				minf[e.F] = minf[now.S] + 1;
				maxf[e.F] = maxf[now.S] + 1;
				pq.push({dis[e.F], e.F});
			}
			else if (dis[e.F] == now.F + e.S) {
				cnt[e.F] += cnt[now.S];
				cnt[e.F] %= P;
				minf[e.F] = min(minf[e.F], minf[now.S] + 1);
				maxf[e.F] = max(maxf[e.F], maxf[now.S] + 1);
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
	
	cout << dis[n] << " " << cnt[n] << " " << minf[n] << " " << maxf[n] << endl;
}