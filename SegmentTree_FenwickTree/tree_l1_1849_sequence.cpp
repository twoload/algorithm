#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// i  : 1 2 3 4 5 6 7 8
//A[i]: 5 0 1 2 1 2 0 0
//S   : 2 7 3 5 4 1 8 6
//A[1] = 5 : num that is bigger than 1
//A[2] = 0 : num that is bigger than 2
// brute force
//  n! (1<= n <= 100'000)
//  n^2 : put number after inserting blank
//      ex. _ _ _ _ _ _ _ _
//          _ _ _ _ _ 1 _ _ O(n) x n
//          2 _ _ _ _ 1 _ _
//          2 _ 3 _ _ 1 _ _
//          2 _ 3 _ 4 1 _ _
//          2 7 3 5 4 1 8 6
//  n x logn
//  segment tree k-th use
//    all 1 (1:empty, 0:occupancy) : num of empty is important
//    change to 0 after put number
//    fastest find order (k-th) way

#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
void init(vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    init(tree, node*2, start, (start+end)/2);
    init(tree, node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
}
void update(vector<int> &tree, int node, int start, int end, int i, int diff) {
    if (i > end || i < start) {
        return;
    }
    if (start == end) {
        tree[node] += diff;
        return;
    }
    update(tree, node*2, start, (start+end)/2, i, diff);
    update(tree, node*2+1, (start+end)/2+1, end, i, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int kth(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end) {
        return start;
    }
    if (k <= tree[node*2]) {
        return kth(tree, node*2, start, (start+end)/2, k);
    } else {
        return kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> a(n+1);
    vector<int> ans(n+1);
    vector<int> tree(tree_size);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    init(tree, 1, 1, n); // tree leaf node is init as 1
    for (int i=1; i<=n; i++) {
        int k = a[i]+1; // find loc which empty space + 1
        int w = kth(tree, 1, 1, n, k);
        ans[w] = i;
        update(tree, 1, 1, n, w, -1); // 1-1 = 0 (occupied)
    }
    for (int i=1; i<=n; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}