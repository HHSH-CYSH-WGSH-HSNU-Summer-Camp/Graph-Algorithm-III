#define MAXN 200005
#define F first
#define S second

int n, m;
int dis[MAXN][2];
vector<pair<int, int>> G[MAXN];

void dijkstra(int s) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	MEM(dis, 0x3f);
	dis[1][0] = dis[1][1] = 0;
	pq.push({0, {1, 0}});
	
	while (pq.size()) {
		auto now = pq.top();
		pq.pop();
		
		if (dis[now.S.F][now.S.S] != now.F)
			continue;
		
		for (auto e: G[now.S.F]) {
			if (dis[e.F][now.S.S] > now.F + e.S) {
				dis[e.F][now.S.S] = now.F + e.S;
				pq.push({dis[e.F][now.S.S], {e.F, now.S.S}});
			}
			if (now.S.S == 0 && dis[e.F][now.S.S + 1] > now.F + e.S / 2) {
				dis[e.F][now.S.S + 1] = now.F + e.S / 2;
				pq.push({dis[e.F][now.S.S + 1], {e.F, now.S.S + 1}});
			}
		}
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1, a, b, c; i <= m; i++) {
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}
	dijkstra(1);
	cout << dis[n][1] << endl;
}