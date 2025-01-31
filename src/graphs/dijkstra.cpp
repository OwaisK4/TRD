vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> dist;

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0; pq.push({0, source});
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