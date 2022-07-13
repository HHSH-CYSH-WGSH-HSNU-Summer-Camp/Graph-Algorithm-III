#define MAXN 405

int n, m, ans = 0;
int dis[MAXN][MAXN];
 
void sol() {
	cin >> n >> m;
	MEM(dis, 0x3f);
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
		
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		dis[a][b] = c;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				ans += dis[i][j] * (dis[i][j] != INF);
			}
		}
	}
	cout << ans << endl;
}