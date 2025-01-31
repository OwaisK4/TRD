class DSU {
public:
    int n; vector<int> parent, size;
    DSU(int n) {
        this->n = n; parent.assign(n, -1); size.assign(n, 0);
    }
    void make_set(int v) {
        parent[v] = v; size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) { return v; }
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a); b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a; size[a] += size[b];
        }
    }
    int total_sets() {
        int total = 0;
        for (int i = 1; i < parent.size(); i++) 
        { if (i == parent[i]) total++; }
        return total;
    }
};