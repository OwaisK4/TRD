const int BOARD_LEN = 15;
int nimber(int r, int c) {
	static std::map<std::pair<int, int>, int> cache;
	if (cache.count({r, c})) { return cache[{r, c}]; }
	if (r < 0 || BOARD_LEN <= r || c < 0 || BOARD_LEN <= c) {
		return -1;  // return -1 to not interfere with the mex operations
	}
	std::set<int> reachable{nimber(r - 2, c + 1), nimber(r - 2, c - 1),
	                        nimber(r + 1, c - 2), nimber(r - 1, c - 2)};

	int ret = 0;
	while (reachable.count(ret)) { ret++; }
	return cache[{r, c}] = ret;
}

int main() {
	int test_num; cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int coin_xor = 0, coin_num;
        cin >> coin_num;
		for (int i = 0; i < coin_num; i++) {
			int r, c; cin >> r >> c;
			coin_xor ^= nimber(r - 1, c - 1);
		}
		cout << (coin_xor == 0 ? "Second" : "First") << '\n';
	}
}