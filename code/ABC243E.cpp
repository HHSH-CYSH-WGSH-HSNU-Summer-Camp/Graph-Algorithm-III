#define MAXN 305
#define MAXM 90005
int n, m;
int dis[MAXN][MAXN];
tuple<int, int, int> E[MAXM];
 
void sol() {
	cin >> n >> m;
	MEM(dis, 0x3f);
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		dis[a][b] = c;
		dis[b][a] = c;
		E[i] = {a, b, c};
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i < m; i++) {
		auto [a, b, c] = E[i];
		bool unused = false;
		
		for (int j = 1; j <= n; j++)
			unused |= (dis[a][j] + dis[j][b] <= c);
		ans += unused;
	}
	cout << ans << endl;
}