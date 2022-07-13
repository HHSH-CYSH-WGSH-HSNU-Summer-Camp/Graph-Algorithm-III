#define MAXN 1005

int n, m;
int dis[MAXN][MAXN][4];
char c[MAXN][MAXN];

const int px[] = {0, 1, 0, -1};
const int py[] = {1, 0, -1, 0};

bool check(int x, int y) {
	return x && y && x <= n && y <= m;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];

	memset(dis, 0x3f, sizeof(dis));
	dis[1][1][0] = 0;
			
	deque<tuple<int, int, int>> dq;
	
	dq.push_back({1, 1, 0});
	
	while (dq.size()) {
		auto [x, y, dir] = dq.front();
		dq.pop_front();
	
		int xx, yy;
		xx = x + px[dir];
		yy = y + py[dir];
		
		if (check(xx, yy) && dis[xx][yy][dir] > dis[x][y][dir]) {
			dq.push_front({xx, yy, dir});
			dis[xx][yy][dir] = dis[x][y][dir];
		}
		
		if (c[x][y] == '#') {
			for (int i = 0; i < 4; i++) {
				if (i == dir)
					continue;
					
				dis[x][y][i] = min(dis[x][y][i], dis[x][y][dir] + 1);
				xx = x + px[i];
				yy = y + py[i];
				
				if (check(xx, yy) && dis[xx][yy][i] > dis[x][y][i]) {
					dq.push_back({xx, yy, i});
					dis[xx][yy][i] = dis[x][y][i];
				}		
			}
		}
	}
	
	if (dis[n][m][0] != INF)
		cout << dis[n][m][0] << endl;
	else
		cout << -1 << endl;
}