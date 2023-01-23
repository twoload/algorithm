#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// n : 1 ~ 100'000
// brute force : 2^n
// dp 
//    d[n][v] : last value=v, pos=n ascending sequence's maximum number
//      d[n+1][v'] = d[n][v], v'<=v
//      d[n+1][v'] = d[n][v] + 1, v' > v
//      1<= v' <= 100'000 (too big)

// teacher
// LIS
// d[i] = max(d[j])+1,    
//   j      i
// A[j] < A[i]

// d[i][j] : end=A[i], len=j, ascending subsequence's numbers
// d[i][1] = 1
// d[i][j] = sum( d[k][j-1] )  (k<i, A[k]<A[i])
// O(kn^2) = O(nk)(d[i][j]) x n(find all k) => too big!
//    j-1
// /--------\
// O, O, ...A[k]., A[i] (k<i, A[k]<A[i])
// \----------------/ 
//          j
//
// sum -> segment tree/fenwick tree ?
// tree[i] : IS's number finishing at i
// > tree[j][i] : length=j
//
// tree[j][i] = sum(d[k][j]) (k<=i) -> fenwick tree O(logn)
//                                     nk x n -> nk x logn = knlogn
// d[i][j] = sum(d[k][j-1]) (k<i, A[k]<A[i])
//         = tree[j-1][A[i]-1] 
//
//    j-1
// /--------\
// O, O, ...A[k]., A[i] (k<i, A[k]<A[i])
// \----------------/ 
//          j

#include <iostream>
#include <vector>
using namespace std;
const int mod = 5000000;
void update(vector<int> &tree, int i, int diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        tree[i] %= mod;
        i += (i & -i);
    }
}
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        ans %= mod;
        i -= (i & -i);
    }
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    // d[i][j] = sum( d[k][j-1] )  (k<i, A[k]<A[i])
    //           ----------------
    //             O(n) -> O(logn) : idea
    // tree[i] : IS's number finishing at i
    // > tree[j][i] : length=j
    // tree[j][i] = sum(d[k][j]) (k<=i) -> fenwick tree O(logn)
    //  > because we want to sum fast with tree
    // 
    // d[i][j] = sum(d[k][j-1]) (k<i, A[k]<A[i])
    //         = tree[j-1][i] (my idea)
    //         = tree[j-1][A[i]-1] (teacher)
    vector<vector<int>> d(n, vector<int>(k+1));
    vector<vector<int>> tree(k+1, vector<int>(100001));
// example 1
// 2 2 
// 9 10
// d[0][1] = 1 (a[0]=9)
// tree[1][9] = 1
// d[0][2] = 0 (tree[1], [1,8])
// tree[2][9] = 0
// d[1][1] = 1 (a[1]=10)
// tree[1][10] = 1
// d[1][2] = 1 (tree[1], [1,9])
// tree[2][10] = 1
// ans=1

// example 2
// 4 3
// 1 2 2 10
// d[0][1] = 1 (a[0]=1) -> turn1
//  pos len
// tree[1][1] = 1
//     len pos
// d[0][2] = 0 (tree[1], [1,0])
//  pos len
// tree[2][1] = 0
// d[0][3] = 0 (tree[2], [1,0])
// tree[3][1] = 0
// d[1][1] = 1 (a[1]=2) -> turn2
// tree[1][2] = 1
// d[1][2] = 1 (tree[1], [1,1])
// tree[2][2] = 1
// d[1][3] = 0 (tree[2], [1,1])
// tree[3][2] = 0
// d[2][1] = 1 (a[2]=2)
// tree[1][2] = 1
// d[2][2] = 1 (tree[1], [1,1])
// tree[2][2] = 1
// d[2][3] = 0 (tree[2], [1,1])
// tree[3][2] = 0
// d[3][1] = 1 (a[3]=10)
// tree[1][10] = 1
// d[3][2] = 3 (tree[1], [1,9])
// tree[2][10] = 3
// d[3][3] = 2 (tree[2], [1,9])
// tree[3][10] = 2
// 2
    for (int i=0; i<n; i++) {
        d[i][1] = 1;
        //printf("d[%d][%d] = 1 (a[%d]=%d)\n", i, 1,i,a[i]);
        update(tree[1], a[i], 1);
        //printf("tree[1][%d] = 1\n", a[i], 1);
        for (int j=2; j<=k; j++) {
            d[i][j] = sum(tree[j-1], a[i]-1);
            //printf("d[%d][%d] = %d (tree[%d], [1,%d])\n", i,j,d[i][j],j-1,a[i]-1);
            update(tree[j], a[i], d[i][j]);
            //printf("tree[%d][%d] = %d\n", j, a[i], d[i][j]);
        }
    }
    int ans = sum(tree[k], 100000);
    cout << ans << '\n';
    return 0;
}


