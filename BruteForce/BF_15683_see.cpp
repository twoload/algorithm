#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <tuple>
#include <cstring>
using namespace std;

int n,m;
int a[9][9];

struct _Point{
    int type;
    int x;
    int y;
} Point;

void print() {
    cout << '\n';
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            if (1<= a[i][j] && a[i][j] <=5) {

            }
        }
    }
    print();
    vector<vector<vector<pair<int,int>>>> dir(5, vector<vector<pair<int,int>>>());
    vector<vector<pair<int,int>>> t1(4, vector<pair<int,int>>());
    t1[0].push_back(make_pair(0,1));
    t1[1].push_back(make_pair(-1,0));
    t1[2].push_back(make_pair(0,-1));
    t1[3].push_back(make_pair(1,0));
    dir[0] = t1;
    vector<vector<pair<int,int>>> t2(2, vector<pair<int,int>>());
    t2[0].push_back(make_pair(0,1));
    t2[0].push_back(make_pair(0,-1));
    t2[1].push_back(make_pair(-1,0));
    t2[1].push_back(make_pair(1,0));
    dir[1] = t2;
    vector<vector<pair<int,int>>> t3(4, vector<pair<int,int>>());
    t3[0].push_back(make_pair(-1,0));
    t3[0].push_back(make_pair(0,1));
    t3[1].push_back(make_pair(0,1));
    t3[1].push_back(make_pair(1,0));
    t3[2].push_back(make_pair(1,0));
    t3[2].push_back(make_pair(0,-1));
    t3[3].push_back(make_pair(-1,0));
    t3[3].push_back(make_pair(0,-1));
    dir[2] = t3;
    vector<vector<pair<int,int>>> t4(4, vector<pair<int,int>>());
    t4[0].push_back(make_pair(-1,0));
    t4[0].push_back(make_pair(0,1));
    t4[0].push_back(make_pair(0,-1));
    t4[1].push_back(make_pair(1,0));
    t4[1].push_back(make_pair(-1,0));
    t4[1].push_back(make_pair(0,1));
    t4[2].push_back(make_pair(1,0));
    t4[2].push_back(make_pair(0,-1));
    t4[2].push_back(make_pair(0,1));
    t4[3].push_back(make_pair(1,0));
    t4[3].push_back(make_pair(-1,0));
    t4[3].push_back(make_pair(0,-1));
    dir[3] = t4;
    vector<vector<pair<int,int>>> t5(1, vector<pair<int,int>>());
    t5[0].push_back(make_pair(-1,0));
    t5[0].push_back(make_pair(1,0));
    t5[0].push_back(make_pair(0,1));
    t5[0].push_back(make_pair(0,-1));
    dir[4] = t5;

    
    return 0;
}