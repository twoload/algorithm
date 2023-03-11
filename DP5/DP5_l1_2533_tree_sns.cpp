#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n <= 1'000'000
// d[node][include] : min num of early adapter when node is included
//   include: 0 = not included
//   include: 1 = included

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int d[1000001][2]; //n <= 1'000'000
bool check[1000001];
vector<int> a[1000001];
int n;
int go(int index, int include) {
    int &ans = d[index][include]; // memoization
    if (ans != -1) { 
        return ans;
    }
    check[index] = true; // in
    ans = include;
    for (int next : a[index]) {
        if (check[next]) { // parent
            continue;
        }
        if (include == 0) {
            ans += go(next, 1); // next children, 1: include
        } else {
            // min (include o,x)
            ans += min(go(next, 0), go(next, 1));
        }
    }
    check[index] = false; // out
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(d,-1,sizeof(d));
    // 1: root, 0/1: include
    cout << min(go(1, 0), go(1, 1)) << '\n';
    return 0;
}