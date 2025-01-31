vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> dist;
void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        int source = pq.top().second;
        pq.pop();
        if (visited[source]) {
            continue;
        }
        visited[source] = true;
        for (auto it : adj[source]) {
            if (dist[it.first] > dist[source] + it.second) {
                dist[it.first] = dist[source] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}
// K shortest paths
int n, m, k, a, b, c;
vector<vii> adj;
vi counter, answer;
void solve() {
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (counter[n - 1] < k) {
        auto [length, src] = pq.top();
        pq.pop();
        if (counter[src] == k)
            continue;
        counter[src]++;
        if (src == n - 1)
            answer.push_back(length);
        for (auto [dest, w] : adj[src]) {
            pq.push({length + w, dest});
        }
    }
    print(answer);
}