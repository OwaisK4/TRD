// rem y mod tienen el mismo numero de elementos
long long chinese_remainder(vector<int> rem, vector<int> mod) {
    long long ans = rem[0], m = mod[0];
    int n = rem.size();
    for (int i = 1; i < n; ++i) {
        int a = modular_inverse(m, mod[i]);
        int b = modular_inverse(mod[i], m);
        ans = (ans * b * mod[i] + rem[i] * a * m) % (m * mod[i]);
        m *= mod[i];
    }

    return ans;
}
// cp-algo
struct Congruence {
    long long a, m;
};
long long chinese_remainder_theorem(vector<Congruence> const &congruences) {
    long long M = 1;
    for (auto const &congruence : congruences) {
        M *= congruence.m;
    }
    long long solution = 0;
    for (auto const &congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}