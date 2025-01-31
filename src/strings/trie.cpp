class Trie {
public:
    Trie *child[26];
    bool worldEnd;
    Trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        worldEnd = false;
    }
};
void insert(Trie *root, string s) {
    int n = s.size();
    Trie *current = root;
    for (int i = 0; i < n; i++) {
        if (current->child[s[i] - 'a'] == nullptr) {
            current->child[s[i] - 'a'] = new Trie();
        }
        current = current->child[s[i] - 'a'];
    }
    current->worldEnd = true;
}
bool search(Trie *root, string s) {
    int n = s.size();
    Trie *current = root;
    for (int i = 0; i < n; i++) {
        if (current->child[s[i] - 'a'] == nullptr) {
            return false;
        }
        current = current->child[s[i] - 'a'];
    }
    return current->worldEnd;
}
void solve() {
    Trie *root = new Trie();
    vector<string> arr =
        {"and", "ant", "do", "geek", "dad", "ball"};
    for (const string &s : arr) {
        insert(root, s);
    }
    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys) {
        cout << "Key : " << s << "\n";
        if (search(root, s))
            cout << "Present\n";
        else
            cout << "Not Present\n";
    }
}