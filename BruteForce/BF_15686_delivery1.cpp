#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int a[51][51];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
vector<bool> choose(14, 0);
int ans = 987654321;

void calc () {
    int dist = 0;
    for (int i=0; i<house.size(); i++) {
        int d = 987654321;
        for (int j=0; j<chicken.size(); j++) {
            if (choose[j]) {
                int tmp = abs(house[i].first-chicken[j].first)+abs(house[i].second-chicken[j].second);
                if (d > tmp) {
                    d = tmp;
                }
            }
        }
        dist += d;
    }
    if (ans > dist) {
        ans = dist;
    }
}
void go(int idx, int count) {
    if (count == m) {
        calc();
        return;
    }

    for (int i=idx; i<chicken.size(); i++) {
        if (!choose[i]) {
            choose[i] = true;
            go(i, count+1);
            choose[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                house.push_back(make_pair(i,j));
            } else if (a[i][j] == 2) {
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    go(0, 0);
    cout << ans << '\n';
    return 0;
}