vector<int> price(n, 0), pages(n, 0), dp(x + 1, 0);
for (int i = 0; i < n; i++) {
    for (int j = x; j >= price[i]; j--) {
        dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
    }
}
print(dp[x]);