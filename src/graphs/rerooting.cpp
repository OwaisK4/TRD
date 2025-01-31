int N = 7;
vvi g(N);
void dfs0(int node, int par, vvi &g, vi &dp, vi &size) {
    dp[node] = 0; size[node] = 1;
    for (auto nebr : g[node]) {
        if (par != nebr) {
            dfs0(nebr, node, g, dp, size);
            size[node] += size[nebr];
            dp[node] += size[nebr] + dp[nebr];
        }
    }
}
void reroot(int from, int to, vector<int> &dp, vector<int> &size) {
    dp[from] -= size[to] + dp[to];
    size[from] -= size[to];
    size[to] += size[from];
    dp[to] += size[from] + dp[from];
}
void dfs1(int node, int par, vvi &g, vi &dp, vi &ans, vi &size) {
    ans[node] = dp[node];
    for (auto nebr : g[node]) {
        if (par != nebr) {
            reroot(node, nebr, dp, size);
            dfs1(nebr, node, g, dp, ans, size);
            reroot(nebr, node, dp, size);
        }
    }
}
void edge(int a, int b, vvi &g) {
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
}
vector<int> pathSum(vvi &g, int N) {
    vector<int> dp(N), ans(N), size(N);
    dfs0(0, -1, g, dp, size);
    dfs1(0, -1, g, dp, ans, size);
    return ans;
}