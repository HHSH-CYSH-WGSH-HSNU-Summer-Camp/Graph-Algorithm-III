#define MAXN 1005

int n, m, q;
int dis[MAXN];
vector<pair<int, pair<int, int>>> E;
map<pair<int, int>, pair<int, int>> mp;

void init() {
	for (int i = 1; i <= n; i++)
		dis[i] = 0;
	for (int i = n + 1; i <= n + m; i++)
		dis[i] = 0;
	dis[1] = 0;
	mp.clear();
	E.clear();
}

bool Bellman_Ford() {
	for (int i = 0; i <= n + m; i++) {
		bool upd = false;
		for (int j = 0; j < E.size(); j++) {
			int a = E[j].F;
			int b = E[j].S.F;
			int w = E[j].S.S;
			
			if (dis[b] < dis[a] - w) {
				dis[b] = (dis[a] - w);
				upd = true;
			}
		}
		if (i == n + m && upd)
			return true;
	}
	return false;
}

void sol() {
	while (cin >> n >> m >> q  && (n * m * q)) {
		init();
		bool legal = true;
		
		for (int i = 0; i < q; i++) {
			int a, b, c;
			string s;
			cin >> a >> b >> s >> c;
			
			if (s == "<=") {
				E.push_back({a, {b + n, c}});
			}
			else {
				E.push_back({b + n, {a, -c}});
			}
		}
		cout << ((Bellman_Ford() == false && legal == true) ? "Possible" : "Impossible") << endl;
	}
}