int n, m;
vector<vector<int>> adj, adj2, components;
vector<int> nodes, root;
vector<bool> visited;
void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    nodes.push_back(v);
}
void dfs2(int v) {
    visited[v] = true;
    components.back().push_back(v);
    root[v] = components.size() - 1;
    for (auto u : adj2[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}
adj.assign(n, vector<int>()); adj2.assign(n, vector<int>());
visited.assign(n, false); root.assign(n, 0);
for (int i = 0; i < n; i++) {
    if (!visited[i]) { dfs(i); }
}
reverse(all(nodes));
visited.assign(n, false);
for (int i = 0; i < n; i++) {
    if (!visited[nodes[i]]) {
        components.push_back(vi());
        dfs2(nodes[i]);
    }
}