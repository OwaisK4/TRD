vector<int> a(n);
vector<int> b = a;
sort(b.begin(), b.end());
map<int, int> m;
for (int i = 0; i < n; i++) {
    m[b[i]] = i;
}
for (int i = 0; i < n; i++) {
    a[i] = m[a[i]];
}
// Now every value of an array lies in [0, n).
// The most convineint it that if you need the original value for a[i],
// you can just write b[a[i]].