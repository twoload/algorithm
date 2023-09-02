#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// divide team into two
// o/x ....> n/2 select
// all teams pairs
// calc ability
// find minimum

// go(n, i, selected)
// i : current index
// selected: 01... string
// 1) ok
//    i == n, selected '1' == n/2
// 2) ng
//    i > n
// 3) next
//    o: go(n, i+1, selected + '1')
//    x: go(n, i+1, selected + '0')

// teacher
// 2^n = 2^20 = 1028576

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[20][20];
int n;
int go(int index, vector<int>& first, vector<int>& second) {
    if (index == n) {
        if (first.size() == 0) return -1;
        if (second.size() == 0) return -1;
        int t1 = 0;
        int t2 = 0;
        for (int i=0; i<first.size(); i++) {
            for (int j=0; j<first.size(); j++) {
                if (i == j) continue;
                t1 += s[first[i]][first[j]];
            }
        }
        for (int i=0; i<second.size(); i++) {
            for (int j=0; j<second.size(); j++) {
                if (i == j) continue;
                t2 += s[second[i]][second[j]];
            }
        }
        int diff = t1 - t2;
        if (diff < 0) diff = -diff;
        return diff;
    }
    
    int ans = -1;
    first.push_back(index);
    int t1 = go(index+1, first, second);
    if (ans == -1 || (t1 != -1 && ans > t1)) {
        ans = t1;
    }
    first.pop_back();
    second.push_back(index);
    int t2 = go(index+1, first, second);
    if (ans == -1 || (t2 != -1 && ans > t2)) {
        ans = t2;
    }
    second.pop_back();
    return ans;
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> first,second;
    cout << go(0, first, second) << '\n';
    return 0;
}