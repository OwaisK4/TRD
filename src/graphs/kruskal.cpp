class Edge {
public:
    int u, v, w;
};
int n, m;
vector<Edge> edgeList(m);
DSU dsu(n);
sort(all(edgeList), [](Edge &a, Edge &b) { return a.w < b.w; });
int cost = 0;
for (Edge e : edgeList) {
    if (dsu.find_set(e.u) != dsu.find_set(e.v)) {
        cost += e.w;
        dsu.union_set(e.u, e.v);
    }
}