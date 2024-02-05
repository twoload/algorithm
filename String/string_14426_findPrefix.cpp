#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://jaimemin.tistory.com/629

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

//https://velog.io/@beclever/C-%EB%B0%B1%EC%A4%80-5052%EB%B2%88-%EC%A0%84%ED%99%94%EB%B2%88%ED%98%B8-%EB%AA%A9%EB%A1%9D-muqebko7

struct Trie {
    Trie* node[26];

    Trie() {
        for (int i=0; i<26; i++) node[i] = NULL;
    }

    ~Trie() {
        clear();
    }

    void clear(void) {
        for (int i=0; i<26; i++) {
            if (node[i] != NULL) {
                node[i]->clear();
                delete node[i];
            }
        }
    }

    void insert(string& str, int idx) {
        if (idx == str.size()) {
            return;
        }
        int curr = str[idx]-'a'; 
        if (node[curr] == NULL) {
            node[curr] = new Trie();
        }
        node[curr]->insert(str, idx+1);
    }

    bool find(string& str, int idx) {
        if (idx == str.size()) {
            return true;
        }
        int curr = str[idx]-'a';
        if (node[curr] == NULL) {
            return false;
        }
        return node[curr]->find(str, idx+1);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Trie * root = new Trie();

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        root->insert(s, 0);
    }

    int ans = 0;
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        if (root->find(s, 0)) {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}