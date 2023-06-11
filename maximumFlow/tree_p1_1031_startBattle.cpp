#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

/**
 * 
 *             Jimin        Hansu
 * src --(A1)--> 1 ----(1)----> 1 --(B1)--> sink
 *                             (1,2,3,4,...,m)
 *     --(A2)--> 2 ----(1)----> 2 --(B2)--> sink
 *     ..                      (1,2,3,4,...,m)  
 *     --(An)--> n ----(1)----> m --(Bm)--> sink
 *                             (1,2,3,4,...,m)
 * 
 * maximum flow = sum of (A1+A2,...) = sum of (B1+B2,...)
 * <=> all people can play the games
 * 
 */
// who played who ???
// if there is, edge (Hansu -> Jimin), we can guess two played
//    because if flew, direction was changed
//                     (Jimin -> Hansu) => (Hansu -> Jimin)

// 1--x-->1
// 1--x-->2
// as we remove one by one,
// check if max flow is the same as sum of (A1+A2+...)

// time complexity
// O(nm) * O(n^2*m^2) = O(n^3*m*3) ???

// 50        50
// 0~n-1     n~n+m-1
// source: 100
// sink :  101

// i         --> n+j
// (jimin i) --> (Hansu j)

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int a[102][102];
int n;
int source=100 , sink=101;
bool check[102];
int dfs(int x) {
    if (check[x]) return 0;
    check[x] = true;
    if (x == sink) {
        return true;
    }
    // 50        50
    // 0~n-1     n~n+m-1
    // source: 100
    // sink :  101
    for (int i=0; i<=sink; i++) {
        if (a[x][i] > 0) {
            if (dfs(i)) {
                a[x][i] -= 1; // ori edge
                a[i][x] += 1; // rev edge
                return true;
            }
        }
    }
    return false;
}
int flow() {
    int ans = 0;
    while (true) {
        memset(check,false,sizeof(check));
        if (!dfs(source)) {
            break;
        }
        ans += 1;
    }
    return ans;
}
int main() {
    int n,m;
    cin >> n >> m;
    int s1=0,s2=0;
    // source -> Jimin 
    // num of games which Jimin should play
    for (int i=0; i<n; i++) {
        cin >> a[source][i];
        s1 += a[source][i];
    }
    // Hansu -> sink
    // num of games which Hansu should play
    for (int i=0; i<m; i++) {
        cin >> a[n+i][sink];
        s2 += a[n+i][sink];
    }
    if (s1 != s2) { // two numbers should be same
        printf("-1\n");
        return 0;
    }
    // Jimin, Hansu are connected each other
    // flow = 1 (chance = 1)
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            a[i][n+j] = 1;
        }
    }
    int ans = flow(); // flow
    // Jinim's all team people should play
    //         = maximum flow
    if (s1 != ans) { // they should be the same
        printf("-1\n");
        return 0;
    }
    // by order
    // check if it is perfect important edge
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            bool ans = false;
            // 50        50
            // 0~n-1     n~n+m-1
            // source: 100
            // sink :  101
            if (a[i][n+j] == 0) {
                a[source][i] += 1; // check if there is another way
                a[n+j][sink] += 1;
                memset(check,false,sizeof(check));
                // check if there is a way (from i to n+j)
                if (!dfs(source)) { // if there is no,,, perfect important edge (5651)
                    ans = true;
                    a[source][i] -= 1; // revert
                    a[n+j][sink] -= 1;
                }
            }
            a[i][n+j] = 0; // revert if changed
            if (ans) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
        cout << '\n';
    }
    return 0;
}


// way1.
// remove edge by order and find max-flow
// if we cannot find answer, remove it
// O(nm) * O(n^2*m^2) = O(n^3*m^3)  
// -----
// all edges for removing
//         ----------
//         flow = O(DFS) = O(V+E) = O(n+m+nm) ???

// way2 (perfect important edge)  
// O(nm) x O(DFS) = O(nm) x O(V+E) = O(nm) x O(n+m + nm) = O(n^2 x m^2)

