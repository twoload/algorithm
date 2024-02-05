#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

//https://iot624.tistory.com/155
//https://ghdic.github.io/ps/boj-9202/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
int score[9] = {0,0,0,1,1,2,3,5,11};
bool visited[4][4];
set<string> ans;
int wordSizeMax = 0;
int maxScore = 0;
string a[4], wordMax;

struct Trie {
    Trie* node[26];
    bool finished;
    Trie() : finished(false) {
        for (int i=0; i<26; i++) node[i] = NULL;
    }
    ~Trie() {
        for (int i=0; i<26; i++) {
            if (node[i]) delete node[i];
        }
    }
    void insert(string& key) {
        Trie* pNode = this;
        for (int i=0; i<key.length(); ++i) {
            int index = key[i]-'A';
            if (!pNode->node[index]) pNode->node[index] = new Trie();
            pNode = pNode->node[index];
        }
        pNode->finished = true;
    }
};


void dfs(int x, int y, string key, Trie* node) {
    if (key.length() > 8) return;
    visited[x][y] = true;
    key += a[x][y];

    Trie* pNode = node->node[a[x][y]-'A'];
    if (pNode == NULL) {
        visited[x][y] = false;
        return;
    }
    if (pNode->finished) {
        ans.insert(key);
    }
    for (int i=0; i<8; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx<0 || ny<0 || nx>=4 || ny>4) continue;
        if (visited[nx][ny]) continue;
        dfs(nx,ny,key,pNode);
    }
    visited[x][y] = false;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    Trie* root = new Trie;
    for (int i=0; i<n; i++) {
        cin >> words[i];
        root->insert(words[i]);
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        for (int i=0; i<4; i++) {
            cin >> a[i];
        }
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                visited[i][j] = false;
            }
        }
        ans.clear();
        wordSizeMax=0; maxScore=0; wordMax.clear();
        for (int r=0; r<4; r++) {
            for (int c=0; c<4; c++) {
                string s;
                s.push_back(a[r][c]);
                dfs(r, c, s, root);
            }
        }
        cout << maxScore << " " << wordMax << " " << ans.size() << '\n';
    }

    return 0;
}
