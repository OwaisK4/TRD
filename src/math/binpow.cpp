int binmult(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int answer = binmult(a, b / 2) % MOD;
    answer = (answer * 2) % MOD;
    if (b & 1) {
        answer = (answer + a) % MOD;
    }
    return answer;
}
int binpow(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x % MOD;
    }
    int answer = binpow(x, n / 2) % MOD;
    answer = binmult(answer, answer);
    answer %= MOD;
    if (n & 1) {
        answer *= x;
        answer %= MOD;
    }
    return answer;
}