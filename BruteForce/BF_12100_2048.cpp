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

bool valid(vector<int> dir) {
    for (int i=0; i+1 < dir.size(); i++) {
        if (dir[i] == 0 && dir[i+1] == 1) return false;
        if (dir[i] == 1 && dir[i+1] == 0) return false;
        if (dir[i] == 2 && dir[i+1] == 3) return false;
        if (dir[i] == 3 && dir[i+1] == 2) return false;
        if (dir[i] == dir[i+1]) return false;
    }
    return true;
}

void simulate(vector<vector<int>>& a, int k) {
    int n = a.size();
    if (k==0) { // right
       for (int i=0; i<n; i++) {
           queue<int> q;
           for (int j=n-1; j>=0; j--) {
               if (a[i][j] != 0) {
                   q.push(a[i][j]);
                   a[i][j] = 0;
               }
           }
           int index = n-1;
           while (!q.empty()) {
               int cur = q.front();
               q.pop();
               if (a[i][index] == 0) {
                   a[i][index] = cur;
               } else if (a[i][index] == cur) {
                   a[i][index] *= 2;
                   index -= 1;
               } else {
                   index -= 1;
                   a[i][index] = cur;
               }
           }
       } 
    } else if (k==1) { // left
        for (int i=0; i<n; i++) {
           queue<int> q;
           for (int j=0; j<n; j++) {
               if (a[i][j] != 0) {
                   q.push(a[i][j]);
                   a[i][j] = 0;
               }
           }
           int index = 0;
           while (!q.empty()) {
               int cur = q.front();
               q.pop();
               if (a[i][index] == 0) {
                   a[i][index] = cur;
               } else if (a[i][index] == cur) {
                   a[i][index] *= 2;
                   index += 1;
               } else {
                   index += 1;
                   a[i][index] = cur;
               }
           }
       } 
    } else if (k==2) { // up
        for (int j=0; j<n; j++) {
           queue<int> q;
           for (int i=0; i<n; i++) {
               if (a[i][j] != 0) {
                   q.push(a[i][j]);
                   a[i][j] = 0;
               }
           }
           int index = 0;
           while (!q.empty()) {
               int cur = q.front();
               q.pop();
               if (a[index][j] == 0) {
                   a[index][j] = cur;
               } else if (a[index][j] == cur) {
                   a[index][j] *= 2;
                   index += 1;
               } else {
                   index += 1;
                   a[index][j] = cur;
               }
           }
       } 
    } else if (k==3) { // down
        for (int j=n-1; j>=0; j--) {
           queue<int> q;
           for (int i=n-1; i>=0; i--) {
               if (a[i][j] != 0) {
                   q.push(a[i][j]);
                   a[i][j] = 0;
               }
           }
           int index = n-1;
           while (!q.empty()) {
               int cur = q.front();
               q.pop();
               if (a[index][j] == 0) {
                   a[index][j] = cur;
               } else if (a[index][j] == cur) {
                   a[index][j] *= 2;
                   index -= 1;
               } else {
                   index -= 1;
                   a[index][j] = cur;
               }
           }
       } 
    }
}

void print(vector<vector<int>> a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isSame(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int check(vector<vector<int>> a, vector<int> dir) {
    int n = a.size();
    int ans = 0;
    //vector<int> v = {1,3,1,2,0};
    //if (dir == v) {
    //    cout << "same" << '\n';
    //}
    for (int k : dir) {
        vector<vector<int>> b = a;
        //cout << "before > " << k  << '\n';
        //print(a);
        simulate(a, k);
        //cout << "after > " << k << '\n';
        //print(a);   

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (ans < a[i][j]) {
                    ans = a[i][j]; 
                }
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
    int ans = -1;
    for (int k=0; k<(1<<(2*LIMIT)); k++) {
        vector<int> dir = gen(k);
        //if (!valid(dir)) continue;
        //print(a);
        int cur = check(a, dir);
        if (ans == -1 || ans < cur) {
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