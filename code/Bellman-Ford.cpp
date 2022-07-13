int n, m;
int dis[MAXN];
tuple<int, int, int> E[MAXM];


bool Bellman_Ford(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = get<0>(E[j]);
            int v = get<1>(E[j]);
            int w = get<2>(E[j]);
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = get<0>(E[j]);
        int v = get<1>(E[j]);
        int w = get<2>(E[j]);
        if (dis[v] > dis[u] + w) {
            return false;
        }
    }
}