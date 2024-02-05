#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://m.blog.naver.com/kks227/220992598966
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct Trie{
    Trie *go[26];
    Trie *fail;
    bool output;

    Trie() {
        fill(go, go+26, nullptr);
        output = false;
    }
    ~Trie() {
        for (int i=0; i<26; i++) {
            if (go[i]) delete go[i];
        }
    }
    void insert(const char* key) {
        if (*key == '\0') {
            output = true;
            return;
        }
        int next = *key-'a';
        if (!go[next]) go[next] = new Trie;
        go[next]->insert(key+1);
    }
};

int main() {
    int n, m;
    cin >> n;
    string str;
    Trie* root = new Trie;
    for (int i=0; i<n; i++) {
        cin >> str;
        root->insert(str.c_str());
    }

    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while (!q.empty()) {
        Trie* current = q.front(); q.pop();

        for (int i=0; i<26; i++) {
            Trie* next = current->go[i];
            if (!next) continue;

            if (current == root) next->fail = root;
            else {
                Trie *dest = current->fail;
                while (dest!=root && !dest->go[i])
                    dest = dest->fail;
                
                if (dest->go[i]) dest = dest->go[i];
                next->fail = dest;
            }
            if (next->fail->output) next->output = true;
            q.push(next);
        }
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        Trie * current = root;
        bool result = false;
        for (int c=0; c<s.size(); c++) {
            int next = s[c]-'a';
            while (current!=root && !current->go[next])
                current = current->fail;
            if (current->go[next])
                current = current->go[next];
            if (current->output) {
                result = true;
                break;
            }
        }
        cout << (result ? "YES" : "NO") << '\n';
    }
    return 0;
}