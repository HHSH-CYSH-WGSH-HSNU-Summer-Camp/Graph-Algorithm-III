int n, m;
int dis[MAXN];
vector<pair<int, pair<int, int>>> E;

bool Bellman_Ford() { // return true if there is a negative cycle
    for (int i = 0; i <= n; i++) {
        bool upd = true;
        for (int j = 0; j < E.size(); j++) {
            int u = E[j].F, v = E[j].S.F, w = E[j].S.S;

            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                upd = true;
            }
        }
        if (i == n)
            return upd;
    }
}

void sol() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        string s;

        cin >> a >> b >> s >> c;
        if (s == "<=") {
            E.push_back({a, {b, -c}});
        }
        else
            E.push_back({b, {a, c}});
    }

    Bellman_Ford();
}