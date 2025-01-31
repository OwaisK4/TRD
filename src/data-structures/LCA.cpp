vvi adj; vi depth;
void dfs(int v, int p, int d) {
    depth[v] = d;
    for (auto u : adj[v]) {
        if (u != p) { dfs(u, v, d + 1); }
    }
}
depth.assign(n, 0); adj.assign(n, vi());
int maxbit = 21;
vector<int> parent(n, -1);
vvi ancestor(maxbit + 1, vi(n, -1));
for (int i = 1; i < n; i++) {
    cin >> u; u--;
    parent[i] = u; ancestor[0][i] = u;
    adj[u].push_back(i); adj[i].push_back(u);
}
dfs(0, 0, 0);
for (int i = 1; i <= maxbit; i++) {
    for (int j = 0; j < n; j++) {
        if (ancestor[i - 1][j] == -1) continue;
        ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
    }
}
// LCA of a and b
if (depth[a] > depth[b])
    swap(a, b);
int diff = depth[b] - depth[a];
for (int j = maxbit; j >= 0; j--) {
    if ((1 << j) <= diff) {
        b = ancestor[j][b];
        diff -= (1 << j);
    }
}
if (a == b) { print(a + 1); }
else{ for (int j = maxbit; j >= 0; j--) {
    if (ancestor[j][a] != -1 && (ancestor[j][a] != ancestor[j][b])) {
        a = ancestor[j][a]; b = ancestor[j][b];
    }
}
print(ancestor[0][a] + 1); }