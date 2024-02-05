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

int m;
vector<int> a;
vector<char> op;
//vector<int> bracket; //0000, 0001, ...
int ans = 0;

void go(int idx, bool choose, vector<int>& bracket) {
    if (idx == m) {
        // calc
        for (int i=0; i<bracket.size(); i++) {
            cout << bracket[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (choose) {
        go(idx+1, false, bracket);
    } else {
        go(idx+1, false, bracket);
        bracket.push_back(idx+1);
        go(idx+1, true, bracket)
        bracket.pop_back;
    }
}
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<n; i+=2) {
        a.push_back(s[i]-'0');
        //cout << a.back() << ' ';
    }
    for (int i=1; i<n; i+=2) {
        op.push_back(s[i]);
        //cout << op.back() << ' ';
    }
    m = op.size();
    vector<int> bracket;
    bracket.clear();
    bracket.push_back(0);
    go(0,true, bracket);
    bracket.pop_back();
    go(0,false);

    return 0;
}