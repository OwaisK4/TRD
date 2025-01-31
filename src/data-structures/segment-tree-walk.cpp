class SegmentTree {
public:
    int n;
    vii tree;
    SegmentTree(vi &array) {
        n = array.size();
        tree.assign(4 * n, pii());
        build(array, 1, 0, n - 1);
    }
    pii f(pii a, pii b) {
        if (a.f > b.f) {
            return a;
        } else if (a.f < b.f) {
            return b;
        } else {
            return pii(a.f, a.s + b.s);
        }
    }
    void build(vi &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {array[tl], 1};
        } else {
            int tm = midpoint(tl, tr);
            build(array, 2 * v, tl, tm);
            build(array, 2 * v + 1, tm + 1, tr);
            tree[v] = f(tree[2 * v], tree[2 * v + 1]);
        }
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].f -= val;
        } else {
            int tm = midpoint(tl, tr);
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, val);
            } else {
                update(2 * v + 1, tm + 1, tr, pos, val);
            }
            tree[v] = f(tree[2 * v], tree[2 * v + 1]);
        }
    }
    pii conquer(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return {-INF, -INF};
        } else if (l == tl && r == tr) {
            return tree[v];
        } else {
            int tm = midpoint(tl, tr);
            pii answer = f(conquer(2 * v, tl, tm, l, min(tm, r)), conquer(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
            return answer;
        }
    }
    int walk(int v, int tl, int tr, int needed) {
        if (needed > tree[v].first) {
            return -1;
        }
        if (tl == tr) {
            return tl;
        }
        int tm = midpoint(tl, tr);
        if (needed <= tree[2 * v].f) {
            return walk(2 * v, tl, tm, needed);
        } else {
            return walk(2 * v + 1, tm + 1, tr, needed);
        }
    }
};