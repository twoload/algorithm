#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

set<int> ans;
int a[5][5];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<char> v;

void go(int idx, int x, int y) {
    if (idx == 6) {
        int num = 0;
        for (int i=0; i<6; i++) {
            num += v[i];
            if (i != 5) {
                num *= 10;
            }
        }
        ans.insert(num);
        return;
    }
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0<=nx && nx<5 && 0<=ny && ny<5) {
            v.push_back(a[nx][ny]);
            go(idx+1, nx, ny);
            v.pop_back();
        }
    }
}
int main() {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            v.push_back(a[i][j]);
            go(0,i,j);
            v.pop_back();
        }
    }
    
    cout << ans.size() << '\n';
    return 0;
}