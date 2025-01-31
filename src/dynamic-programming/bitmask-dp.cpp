int n;
vector<vector<int>> a;
vector<int> dp(1 << 21, -1);
cin >> n;
a.assign(n, vector<int>(n, 0));
dp.assign(1 << n, 0);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> a[i][j];
    }
}
// Recursive
int f(int bitmask) {
    if (bitmask == (1 << n) - 1) {
        return 1;
    }
    if (dp[bitmask] != -1)
        return dp[bitmask];
    int answer = 0;
    int males = __builtin_popcount(bitmask);
    for (int i = 0; i < n; i++) {
        if (a[males][i] == 1 && (bitmask & (1 << i)) == 0) {
            answer += f(bitmask | (1 << i));
            answer %= MOD;
        }
    }
    return dp[bitmask] = answer;
}
// Iterative
dp[0] = 1;
for (int i = 0; i < (1 << n); i++) {
    int males = __builtin_popcount(i);
    for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) || a[males][j] == 0)
            continue;
        dp[i | (1 << j)] += dp[i];
        dp[i | (1 << j)] %= MOD;
    }
}
print(dp[(1 << n) - 1]);