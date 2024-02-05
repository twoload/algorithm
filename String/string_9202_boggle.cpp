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
    void insert(string& str, int idx) {
        if (idx == str.size()) {
            return;
        }
        int curr = str[idx]-'A';
        if (node[curr] == NULL) node[curr] = new Trie;
        node[curr]->insert(str, idx+1);
    }
    bool find(string& str, int idx) {
        if (idx == str.size()) return true;
        int curr = str[idx]-'A';
        if (node[curr] == NULL) return false;
        return node[curr]->find(str, idx+1);
    }
    bool findWord(string& str, int idx) {
        if (finished && find(str, idx)) return true;
        return false;
    }
};

int score(int size) {
    if (size == 1 || size == 2) return 0;
    if (size == 3 || size == 4) return 1;
    if (size == 5) return 2;
    if (size == 6) return 3;
    if (size == 7) return 5;
    if (size == 8) return 11;
    return 0;
}
void dfs(int x, int y, string word, Trie* root) {
    if (visited[x][y]) return;
    if (word.size() > 8) return;

    if (root->findWord(word, 0)) {
        if (ans.find(word) == ans.end()) {
            ans.insert(word);
            maxScore += score(word.length());
            if (word.length() > wordSizeMax) {
                wordSizeMax = word.length();
                wordMax = word;
            } else if (word.length() == wordSizeMax) {
                wordMax = min(wordMax, word); // in order of dictionary
            }
        }
    }
    visited[x][y] = true;
    for (int i=0; i<8; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx<0 || ny<0 || nx>=4 || ny>4) continue;
        word += a[nx][ny];
        dfs(nx,ny,word,root);
        word.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    Trie* root = new Trie;
    for (int i=0; i<n; i++) {
        cin >> words[i];
        root->insert(words[i], 0);
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
