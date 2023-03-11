#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n : city (2<=n<=50)
// k : move

// d[x][e][k] = x: root, k node select, e children excluded
// e = 0

//          x
//   /   /  |
//  e=0    e=2


//   x
// / | \
// * * *
// e== x'children's num, k==1 > 1  (because we select x)
// e==3, k==1 > 1 (because we select x=1)

//   x
// / | \ \
// * * y *
// 0 1  <- e-th (2-th) child (select num of i)
// if num of node == i at e-th child(y)
//    = d[y][0][i]
// num of node which we should select from remaining e+1-th child 
//    = k-i
// d[x][e][k] = sum(d[y][0][i] * d[x][e+1][k-i])


#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const long long mod = 1000000007;
vector<int> g[51]; // 입력 그래프 // n<=50
vector<int> a[51]; // 트리
long long d[51][51][51];
// d[x][e][k] = x: root, k node select, e children excluded
void dfs(int x, int parent) {
    for (int y : g[x]) { // adjacent
        if (y == parent) continue; // parent
        a[x].push_back(y); // add child
        dfs(y, x); // recursive
    }
}
long long go(int x, int k, int e) {
    long long &ans = d[x][k][e];
    if (ans != -1) return ans;
    if (k == 0) { // all selected
        return 1;
    }
    if (e == a[x].size()) { // if e is same as number of children,
        if (k == 1) { // because root(one) is selected
            return 1;
        } else {
            return 0;
        }
    }
    ans = 0;
    // root: 1ea
    //       until k-1
    for (int i=0; i<k; i++) { // check with all possible i
        //   x
        // / | \
        //   y
        //  /|\

        long long t1 = go(a[x][e], i, 0); // y
        long long t2 = go(x, k-i, e+1); // remaining
        ans += t1*t2;
        ans %= mod;
    }
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        g[u].push_back(v);
        g[v].push_back(u); // graph
    }
    dfs(0, -1); // create tree : a[x] = vector<int> a[51]
    memset(d,-1,sizeof(d));
    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += go(i, k, 0); // i:first selected vertex number
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}