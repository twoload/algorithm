#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

const int LIMIT = 5;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

#if 0
#TC 1
input:
4
2 16 16 0
32 16 4 1
4 16 32 0
2 0 8 8

correct answer: 128
output: 64

#TC 2
input:
4
0 8 1 1
8 0 1 4
8 0 8 32
1 32 32 0

correct answer: 128
output: 64

#TC 3
input:
4
2 32 16 8
4 0 4 4
0 1 8 4
32 32 0 32

correct answer: 64
output: 128
#endif

#if 1
vector<int> gen(int k) {
    vector<int> a(LIMIT);
    for (int i=0; i<LIMIT; i++) {
        a[i] = (k & 3);
        k >>= 2;
    }
    return a;
}


void print(vector<vector<pair<int,bool>>> a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j].first << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


// int dx[] = {0,0,1,-1};
// int dy[] = {1,-1,0,0};
int check(vector<vector<int>> a, vector<int> dir) {
    int n = a.size();
    vector<vector<pair<int, bool>>> d(n, vector<pair<int, bool>>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j].first = a[i][j];
        }
    }
    //vector<int> v = {1,2,1,3,0};
    //if (dir == v) {
    //    cout << "same" << '\n';
    //}
    for (int k : dir) {
        //print(d);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                d[i][j].second = false;
            }
        }
        bool ok = false;
        while (true) { 
            ok = false;
            if (k==0) { // Right
                for (int i=0; i<n; i++) {
                    for (int j=n-2; j>=0; j--) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j+1].first == 0) {
                            ok = true;
                            d[i][j+1].first = d[i][j].first;
                            d[i][j+1].second = d[i][j].second;
                            d[i][j].first = 0;
                        } else if (d[i][j+1].first == d[i][j].first) {
                            if (d[i][j+1].second == false && d[i][j].second == false) {
                                ok = true;
                                d[i][j+1].first = d[i][j].first *2;
                                d[i][j+1].second = true;
                                d[i][j].first = 0;
                            }
                        } 
                    }
                }
            } else if (k==1) { // Left
                for (int i=0; i<n; i++) {
                    for (int j=1; j<n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j-1].first == 0) {
                            ok = true;
                            d[i][j-1].first = d[i][j].first;
                            d[i][j-1].second = d[i][j].second;
                            d[i][j].first = 0;
                        } else if (d[i][j-1].first == d[i][j].first) {
                            if (d[i][j-1].second == false && d[i][j].second == false) {
                                ok = true;
                                d[i][j-1].first = d[i][j].first *2;
                                d[i][j-1].second = true;
                                d[i][j].first = 0;
                            }
                        } 
                    }
                }
            } else if (k==2) { // Down
                for (int i=n-2; i>=0; i--) {
                    for (int j=0; j<n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i+1][j].first == 0) {
                            ok = true;
                            d[i+1][j].first = d[i][j].first;
                            d[i+1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                        } else if (d[i+1][j].first == d[i][j].first) {
                            if (d[i+1][j].second == false && d[i][j].second == false) {
                                ok = true;
                                d[i+1][j].first = d[i][j].first *2;
                                d[i+1][j].second = true;
                                d[i][j].first = 0;
                            }
                        } 
                    }
                }
            } else if (k==3) { // Up
                for (int i=1; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i-1][j].first == 0) {
                            ok = true;
                            d[i-1][j].first = d[i][j].first;
                            d[i-1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                        } else if (d[i-1][j].first == d[i][j].first) {
                            if (d[i-1][j].second == false && d[i][j].second == false) {
                                ok = true;
                                d[i-1][j].first = d[i][j].first *2;
                                d[i-1][j].second = true;
                                d[i][j].first = 0;
                            }
                        } 
                    }
                }
            }
            if (ok == false) {
                break;
            }
        }
    }    
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ans < d[i][j].first) {
                ans = d[i][j].first;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int k=0; k<(1<<(2*LIMIT)); k++) {
        vector<int> dir = gen(k);
        int cur = check(a, dir);
        if (ans < cur) {
            ans = cur;
        }
    }
    cout << ans << '\n';
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b

using namespace std;
typedef long long ll;

int n;
ll ans;

// board에서 최대 값 구하는 함수
ll getMax(vector<vector<ll>> board)
{
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res = max(res, board[i][j]);
        }
    }
    return res;
}

// 오른쪽 이동
vector<vector<ll>> right(vector<vector<ll>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (board[i][k] == board[i][k - 1] && !check[i][k])
                {
                    board[i][k] *= 2;
                    board[i][k - 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}

// 왼쪽 이동
vector<vector<ll>> left(vector<vector<ll>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (board[i][k] == board[i][k + 1] && !check[i][k])
                {
                    board[i][k] *= 2;
                    board[i][k + 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}

// 아래 이동
vector<vector<ll>> down(vector<vector<ll>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[j][i] == 0)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (board[k][i] == board[k - 1][i] && !check[k][i])
                {
                    board[k][i] *= 2;
                    board[k - 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[k - 1][i];
                    board[k - 1][i] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}

// 위로 이동
vector<vector<ll>> up(vector<vector<ll>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[j][i] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (board[k][i] == board[k + 1][i] && !check[k][i])
                {
                    board[k][i] *= 2;
                    board[k + 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[k + 1][i];
                    board[k + 1][i] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}
void print(vector<vector<ll>> board) {
    int n = board.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
void dfs(int L, vector<vector<ll>> board, string s)
{
    //print(board);
    ans = max(ans, getMax(board));
    if (getMax(board) == 128) {
        print(board);    
        cout << s << '\n';
    }
    if (L == 5)
        return;
    dfs(L + 1, right(board), s+"R");
    dfs(L + 1, left(board), s+"L");
    dfs(L + 1, up(board), s+"U");
    dfs(L + 1, down(board), s+"D");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;
    vector<vector<ll>> board(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    // dfs 실행
    dfs(0, board,"");
    cout << ans << '\n';

    return 0;
}
#endif