vector<bool> prime(2e7 + 1, true);
prime[0] = prime[1] = false;
int n = 2e6 + 1;
for (int p = 2; p <= n; p++) {
    if (prime[p] == true) {
        for (int i = p * p; i <= n; i += p)
            prime[i] = false;
    }
}