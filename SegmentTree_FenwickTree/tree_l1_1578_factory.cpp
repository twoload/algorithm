#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
// ref. https://www.acmicpc.net/blog/view/21
// ref. https://yabmoons.tistory.com/438
#endif

// cross
//   A[i] : i's location at first row
//   B[i] : i's location at second row
//   A[i] < A[j]
//   B[i] > B[j]

// brute force : O(N^2) <- all i,j pairs
// but n = 500'000

// (i,j) -> standard
// based on j, how many i to satisfy the fomular.

// front!!!
//  A: 132 392 311 351 231
//      \ /    \ /    |
//      /  \  / \     |
//     /    / \  \    |
//  B: 392 351 132 311 231

//  i :   1   2   3   4   5
//B[i]: 392 351 132 311 231
//Tree:   0   0   0   0   0  
//Tree[i] = 1 if B[i] is executed  else 0

//A: 132 (?,132)
//   [4,5] after B:132
//   sum: 0
//Tree:   0   0   1   0   0

//A: 392 -> things (that is front of 392 in A) are in trees
//          count (sum of is back of 392 in B)
//   [2,5] after B:392
//   sum: 1
//Tree:   1   0   1   0   0

//A: 311 (because numbers front of 311 are already in tree)
//   [5,5] after B:311 
//   sum: 0 (?,311) -> there is no ?
//Tree:   1   0   1   1   0

//A: 351
//   [3,5]
//   sum: 2
//Tree:   1   1   1   1   0

//A: 231
//   [5,5]
//   sum: 0

// result = sum of sum (0+1+0+2+0=3)

// time complexity
// sum > edit               : O(N)*O(1) ---> O(N^2)
// sum > edit (segment tree): O(logN)*O(logN)---> O(NlogN)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int l;
void update(vector<int> &tree, int i, int diff) {
    // tree.size = n+1, i<n+1, i=1~n
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i); 
    }
}
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
int sum(vector<int> &tree, int l, int r) {
    if (l > r) return 0;
    return sum(tree, r) - sum(tree, l-1);
}
int main() {
    // n = 5
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    //  a: 132 392 311 351 231
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    map<int,int> position;
    //  B: 392 351 132 311 231
    // key  value
    // 392  1
    // 351  2
    // 132  3
    // 311  4
    // 231  5
    for (int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        position[num] = i+1;
    }
    long long ans = 0;
    vector<int> tree(n+1);
    l = n;
    // in order: from small to big
    //  A: 132 392 311 351 231
    //  B: 392 351 132 311 231
    //A: 132 (?,132)
    //   [4,5] after B:132
    //   sum: 0
    //Tree:   0   0   1   0   0

    //A: 392 -> things (that is front of 392 in A) are in trees
    //          count (sum of is back of 392 in B)
    //   [2,5] after B:392
    //   sum: 1
    //Tree:   1   0   1   0   0

    for (int i=0; i<n; i++) {
        ans += (long long)sum(tree, position[a[i]]+1, n);
        update(tree, position[a[i]], 1);
    }
    printf("%lld\n",ans);
    return 0;
}