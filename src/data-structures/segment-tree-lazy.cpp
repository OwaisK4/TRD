class SegmentTree {
public:
    int n;
    vi tree, lazy;
    SegmentTree(vi &array) {
        n = array.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(array, 1, 0, n - 1);
    }
    int f(int a, int b) {
        return a + b;
    }
    void build(vi &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = array[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(array, v * 2, tl, tm);
            build(array, v * 2 + 1, tm + 1, tr);
            tree[v] = f(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void updateRange(int v, int tl, int tr, int l, int r, int value) {
        if (lazy[v] != 0) {
            tree[v] += (tr - tl + 1) * lazy[v];
            if (tl != tr) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            tree[v] += (tr - tl + 1) * value;
            if (tl != tr) {
                lazy[v * 2] += value;
                lazy[v * 2 + 1] += value;
            }
            return;
        }
        // int tm = midpoint(tl, tr);
        int tm = (tl + tr) / 2;
        updateRange(v * 2, tl, tm, l, min(tm, r), value);
        updateRange(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, value);
        tree[v] = f(tree[v * 2], tree[v * 2 + 1]);
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (lazy[v] != 0) {
            tree[v] += (tr - tl + 1) * lazy[v];
            if (tl != tr) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return f(query(v * 2, tl, tm, l, min(tm, r)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};