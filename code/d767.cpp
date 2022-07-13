#define MAXN 200005
#define F first
#define S second

int n, m;
int in[MAXN], out[MAXN], D[MAXN];
pair<int, int> ST[30][MAXN];
vector<int> G[MAXN];

struct timestamp {
	int tt, node, dep;
};

vector<timestamp> ett;

void init() {
	for (int i = 0; i <= n; i++)
		G[i].clear();
}

void dfs(int i, int dep) {
	in[i] = ett.size();
	ett.push_back({ett.size(), i, dep});
	D[i] = dep;
	
	for (int e: G[i]) {
		dfs(e, dep + 1);
		ett.push_back({ett.size(), i, dep});
	}
	
	out[i] = ett.size();
	ett.push_back({ett.size(), i, dep});
}

void build() {
	for (int i = 0; i < ett.size(); i++) {
		ST[0][i] = {ett[i].dep, ett[i].node};
	}
	
	for (int i = 1; i <= __lg(ett.size()); i++) {
		for (int j = 0; j < ett.size(); j++) {
			ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
		}
	}
}

pair<int, int> query(int l, int r) {
	int lg = __lg(r - l + 1);
	int range = 1 << lg;
	pair<int, int> res(INF, INF);
	
	res = min(ST[lg][l], ST[lg][r - range + 1]);
	return res;
}

void sol() {
	cin >> n >> m;
	init();
	
	for (int i = 1, a; i <= n; i++) {
		while (cin >> a && a)
			G[i].push_back(a);
	}
	
	dfs(1, 1);
	build();
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		
		if (in[a] > in[b])
			swap(a, b);
		
		auto res = query(in[a], in[b]);
		cout << res.second << " " << D[a] + D[b] - 2 * D[res.S] << endl;
	}
}