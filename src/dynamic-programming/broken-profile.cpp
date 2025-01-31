int n, m;
vvi dp;
void getMasks(int i, int mask, int nextMask, vi &nextMasks) {
    if (i == n) {
        nextMasks.push_back(nextMask); return;
    } if (i + 1 < n && ((1 << i) & mask) == 0 && ((1 << (i + 1)) & mask) == 0) {
        getMasks(i + 2, mask, nextMask, nextMasks);
    } if (((1 << i) & mask) == 0) {
        getMasks(i + 1, mask, nextMask + (1 << i), nextMasks);
    } if ((((1 << i) & (mask)) != 0)) {
        getMasks(i + 1, mask, nextMask, nextMasks);
    } return;
}

int f(int i, int mask) {
    if (i == m) {
        if (mask) { return 0; }
        return 1;
    }
    if (dp[i][mask] != -1) { return dp[i][mask]; }
    int answer = 0; vi nextMasks;
    getMasks(0, mask, 0, nextMasks);
    for (auto x : nextMasks) {
        answer += f(i + 1, x); answer %= MOD;
    }
    return dp[i][mask] = answer;
}

void solve() {
    cin >> n >> m;
    dp.assign(m, vi(1 << n, -1));
    int answer = f(0, 0);
    print(answer);
}