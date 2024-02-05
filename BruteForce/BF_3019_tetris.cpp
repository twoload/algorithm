#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int n, m;

vector<vector<vector<pair<int,int>>>> blocks = {
  { {{0,0},{1,0},{2,0},{3,0}},
    {{0,0},{0,1},{0,2},{0,3}},},
  { {{0,0},{1,0},{0,1},{1,1}} },
  { {{0,0},{0,1},{1,1},{1,2}},
    {{0,0},{1,-1},{1,0},{2,-1}} },
  { {{0,0},{1,-1},{1,0},{0,1}},
    {{0,0},{1,0},{1,1},{2,1}} },
  { {{0,0},{0,1},{0,2},{1,1}},
    {{0,0},{1,0},{1,1},{2,0}},
    {{0,0},{1,-1},{1,0},{1,1}},
    {{0,0},{1,-1},{1,0},{2,0}} },
  { {{0,0},{0,1},{0,2},{1,2}},
    {{0,0},{1,0},{2,0},{0,1}},
    {{0,0},{1,0},{1,1},{1,2}},
    {{0,0},{1,0},{2,0},{2,-1}} },
  { {{0,0},{0,1},{0,2},{1,0}},
    {{0,0},{1,0},{2,0},{2,1}},
    {{0,0},{1,-2},{1,-1},{1,0}},
    {{0,0},{0,1},{1,1},{2,1}} } 
};

int calc(int a[201][201]) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=200; j>=1; j--) {
            if (a[j][i]) {
                sum += j;
                break;
            }
        }
    }
    return sum;
}

void print(int a[201][201]) {
    for (int i=1; i<6; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m;
    int a[201][201];
    int height[201];
    int blocknum = 0;
    int expectedBlocknum = 0;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        for (int j=1; j<=tmp; j++) {
            a[j][i] = 1;
        }
        height[i] = tmp;
        blocknum += tmp;
    }
    expectedBlocknum = blocknum + 4;
    int ans = 0;
    vector<vector<pair<int,int>>> block = blocks[m-1];
    for (int i=0; i<block.size(); i++) {
        for (int j=0; j<n; j++) {
            int b[201][201];
            memcpy(b, a, sizeof(b));
            //print(b);
            bool ok = true;
            for (int k=0; k<4; k++) {
                int dx,dy;
                tie(dx,dy) = block[i][k];
                int x = height[j]+dx+1;
                int y = j+dy;
                //printf("x,y = (%d,%d)\n", x, y);
                if (0<=y && y<n && 1<=x && x<201) {
                    if (b[x][y]) {
                        ok = false;
                        break;
                    }
                    b[x][y] = 2;
                } else {
                    ok = false;
                    break;
                }
                //print(b);
            }
            if (!ok) continue;
            //print(b);
            //printf("expect:%d, calc:%d\n", expectedBlocknum, calc(b));
            if (expectedBlocknum == calc(b)) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}