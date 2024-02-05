#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://m.blog.naver.com/kks227/220992598966
//https://kth990303.tistory.com/31
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct Trie{
    Trie *go[4];
    Trie *fail;
    int output;

    Trie() : output(0), fail(nullptr) {
        fill(go, go+4, nullptr);
    }
    ~Trie() {
        for (int i=0; i<4; i++) {
            if (go[i]) delete go[i];
        }
    }
    void insert(string& s, int idx) {
        if (idx >= s.length()) {
            output = 1;
            return;
        }
        int next = s[idx]-'0';
        if (!go[next]) go[next] = new Trie;
        go[next]->insert(s, idx+1);
    }
};

void fail(Trie* root) {
    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while (!q.empty()) {
        Trie* current = q.front(); q.pop();

        for (int i=0; i<4; i++) {
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
            next->output += next->fail->output;
            q.push(next);
        }
    }
}
int find(string s, Trie* root) {
    Trie * current = root;
    int result = 0;
    for (int c=0; c<s.size(); c++) {
        int next = s[c]-'0';
        while (current!=root && !current->go[next])
            current = current->fail;
        if (current->go[next])
            current = current->go[next];
        result += current->output;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s, p;
        cin >> s >> p;
        Trie* root = new Trie;
        for (int i=0; i<n; i++) {
            if (s[i] == 'A') s[i] = '0';
            else if (s[i] == 'C') s[i] = '1';
            else if (s[i] == 'G') s[i] = '2';
            else if (s[i] == 'T') s[i] = '3';
        }
        for (int i=0; i<m; i++) {
            if (p[i] == 'A') p[i] = '0';
            else if (p[i] == 'C') p[i] = '1';
            else if (p[i] == 'G') p[i] = '2';
            else if (p[i] == 'T') p[i] = '3';
        }
        root->insert(p, 0);
        for (int i=0; i<=m; i++) {
            for (int j=i+2; j<=m; j++) {
                reverse(p.begin()+i, p.begin()+j);
                root->insert(p, 0);
                reverse(p.begin()+i, p.begin()+j);
            }
        }
        fail(root);
        cout << find(s, root) << '\n';
        delete root;
    }
    return 0;
}