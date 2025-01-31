vector<int> factorial(MAXN + 1);
vector<int> inv(MAXN + 1);

factorial[0] = 1;
for (int i = 1; i <= MAXN; i++)
    factorial[i] = factorial[i - 1] * i % m;

inv[0] = 0; inv[1] = 1;
for (int a = 2; a <= MAXN; ++a)
    inv[a] = m - (long long)(m / a) * inv[m % a] % m;

long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}