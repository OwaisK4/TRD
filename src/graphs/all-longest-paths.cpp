void dfs1(int v, int p) {
    f[v] = h[v] = 0;
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs1(u, v);
        if (f[v] <= f[u] + 1) {
            h[v] = f[v]; f[v] = f[u] + 1;
        } else if (h[v] < f[u] + 1) {
            h[v] = f[u] + 1;
        }
    }
}
void dfs2(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p) continue;
        if (f[v] == f[u] + 1) {
            g[u] = max(g[v] + 1, h[v] + 1);
        } else {
            g[u] = max(g[v] + 1, f[v] + 1);
        }
        dfs2(u, v);
    }
}