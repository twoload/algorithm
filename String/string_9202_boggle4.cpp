#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
int scores[9] = {0,0,0,1,1,2,3,5,11};
bool c[4][4];
void generate(int x, int y, string word, vector<string> &board, vector<string> &words) {
    words.push_back(word);
    if (word.size() == 8) return;
    for (int k=0; k<8; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0<=nx && nx<4 && 0<=ny && ny<4 && c[nx][ny]==false) {
            c[nx][ny] = true;
            generate(nx,ny,word+board[nx][ny],board,words);
            c[nx][ny] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for (int i=0; i<n; i++) {
        cin >> dictionary[i];
    }
    int t;
    cin >> t;
    while (t--) {
        vector<string> board(4);
        for (int i=0; i<4; i++) {
            cin >> board[i];
        }
        vector<string> words;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                c[i][j] = true;
                generate(i,j,string(1,board[i][j]), board, words);
                c[i][j] = false;
            }
        }
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        int score = 0;
        string longest = "";
        int cnt = 0;
        for (auto &a : dictionary) {
            if (binary_search(words.begin(), words.end(), a)) {
                score += scores[a.size()];
                cnt += 1;
                if (longest.size() < a.size()) {
                    longest = a;
                } else if (longest.size() == a.size() && longest > a) {
                    longest = a;
                }
            }
        }
        cout << score << ' ' << longest << ' ' << cnt << '\n';
    }
    return 0;
}