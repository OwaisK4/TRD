#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, pair<int, int>>> edg;
vector<vector<pair<int, int>>> mst;
vector<int> h, parent, Rank;
vector<vector<int>> up, dp;
void dfs(int u, int p, int log, int d) {
    up[u][0] = p;
    dp[u][0] = d;
    h[u] = 1 + h[p];
    // for (int i = 1; i <= log; i++)
    // {
    //     up[u][i] = up[up[u][i - 1]][i - 1];
    //     dp[u][i] = max(dp[u][i - 1], dp[up[u][i - 1]][i - 1]);
    // }
    for (auto v : mst[u]) {
        if (v.first != p) {
            dfs(v.first, u, log, v.second);
        }
    }
}
int lca(int u, int v, int log) {
    int ans = -2;
    if (h[u] < h[v]) {
        swap(u, v);
    }
    for (int i = log; i >= 0; i--) {
        if (h[u] - pow(2, i) >= h[v]) {
            ans = max(ans, dp[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) {
        return ans;
    }
    for (int i = log; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            ans = max(ans, max(dp[u][i], dp[v][i]));
            u = up[u][i];
            v = up[v][i];
        }
    }
    ans = max(ans, max(dp[u][0], dp[v][0]));
    return ans;
}
int findParent(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}
void unionByRank(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);
    if (px == py)
        return;
    if (Rank[px] < Rank[py])
        parent[px] = py;
    else if (Rank[px] > Rank[py])
        parent[py] = px;
    else {
        parent[px] = py;
        Rank[py]++;
    }
}
signed main() {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    int log = (int)ceil(log2(n));
    map<pair<int, int>, int> edg_ind;
    parent.assign(n + 1, 0);
    Rank.assign(n + 1, 0);
    h.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(log + 1, 0));
    dp.assign(n + 1, vector<int>(log + 1, 0));
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    mst.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edg.push_back({c, {a, b}});
        edg_ind[{a, b}] = i;
    }
    sort(edg.begin(), edg.end());
    vector<int> vis(m, 0);
    vector<int> ans(m, 0);
    int MST = 0;
    for (int i = 0; i < m; i++) {
        if (findParent(edg[i].second.first) != findParent(edg[i].second.second)) {
            unionByRank(edg[i].second.first, edg[i].second.second);
            MST += edg[i].first;
            ans[edg_ind[{edg[i].second.first, edg[i].second.second}]] = -1;
            vis[i] = 1;
            mst[edg[i].second.first].push_back({edg[i].second.second, edg[i].first});
            mst[edg[i].second.second].push_back({edg[i].second.first, edg[i].first});
        }
    }
    int pp = -1;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i)
            pp = i;
    }
    dfs(pp, pp, log, 0);
    for (int i = 1; i <= log; i++) {
        for (int j = 1; j <= n; ++j) {
            if (up[j][i - 1] != -1) {
                int v = up[j][i - 1];
                up[j][i] = up[v][i - 1];
                dp[j][i] = max(dp[j][i - 1], dp[v][i - 1]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            int rem = lca(edg[i].second.first, edg[i].second.second, log);
            ans[edg_ind[{edg[i].second.first, edg[i].second.second}]] = MST - rem + edg[i].first;
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == -1)
            cout << MST << endl;
        else
            cout << ans[i] << endl;
    }
}