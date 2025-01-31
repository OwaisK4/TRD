void multiply(vector<vector<int>> &A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> X(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            X[i][j] = 0;
            for (int k = 0; k < n; k++) {
                X[i][j] += (A[i][k] * B[k][j]);
                X[i][j] %= MOD;
            }
        }
    }
    A = X;
}
int n;
cin >> n;
vector<vector<int>> F = {{0, 1}, {1, 1}};
vector<vector<int>> A = {{1, 0}, {0, 1}};
while (n > 0) {
    if (n & 1) {
        multiply(A, F);
    }
    multiply(F, F);
    n >>= 1;
}
multiply(A, {{1, 0}, {1, 0}});
print(A[0][0]);