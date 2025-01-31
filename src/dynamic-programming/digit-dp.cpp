// Counting Numbers (CSES DP)
int a, b, length;
vector<vvvi> dp;
int f(string &c, int index, int previous, int leading_zero, int is_lesser) {
    if (index == c.size()) {
        return 1;
    }
    if (dp[index][previous][leading_zero][is_lesser] != -1) {
        return dp[index][previous][leading_zero][is_lesser];
    }
    int answer = 0;
    int limit = 9;
    if (!is_lesser) {
        limit = c[index] - '0';
    }
    for (int i = 0; i <= limit; i++) {
        if (leading_zero == 0 && (i == previous)) {
            continue;
        }
        int new_leading_zero = (leading_zero == 1 && i == 0) ? 1 : 0;
        if (is_lesser) {
            answer += f(c, index + 1, i, new_leading_zero, is_lesser);
        } else {
            answer += f(c, index + 1, i, new_leading_zero, i < limit);
        }
    }
    return dp[index][previous][leading_zero][is_lesser] = answer;
    // return answer;
}
void solve() {
    cin >> a >> b;
    string r = to_string(b);
    string l = to_string(a - 1);
    dp.assign(r.size(), vvvi(10, vvi(2, vi(2, -1))));
    int answer = f(r, 0, 0, 1, 0);
    dp.assign(l.size(), vvvi(10, vvi(2, vi(2, -1))));
    if (a != 0)
        answer -= f(l, 0, 0, 1, 0);
    print(answer);
}
// Digit Sum (Atcoder DP)
string K;
int D;
vvvi dp;
int f(int index, int sum, int is_lesser) {
    if (index == K.size()) {
        return ((sum % D) == 0);
    }
    if (dp[index][sum][is_lesser] != -1) {
        return dp[index][sum][is_lesser];
    }
    int answer = 0;
    int limit = (is_lesser) ? 9 : K[index] - '0';
    for (int i = 0; i <= limit; i++) {
        int new_is_lesser = (is_lesser || (i < limit)) ? 1 : 0;
        answer += f(index + 1, (sum + i) % D, new_is_lesser);
        answer %= MOD;
    }
    return dp[index][sum][is_lesser] = answer % MOD;
}
void solve() {
    cin >> K >> D;
    dp.assign(K.size(), vvi(D, vi(2, -1)));
    int answer = f(0, 0, 0);
    K = "0";
    dp.assign(K.size(), vvi(D, vi(2, -1)));
    answer = (answer - f(0, 0, 0) + MOD) % MOD;
    print(answer);
}