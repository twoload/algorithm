#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// n, k (1<=k<=n<=100'000)
// (7,3)
//1,2,3,4,5,6,7 (remove:3)
//    -
//1,2,  4,5,6,7 (remove:3-1+3=5)
//          -
//1,2,  4,5,  7 (remove:5-1+3=7 % 5 = 2)
//  -
//                      (7)1 
//              /       [1,7]      \
//           (4)2 [1,4]            (3)3 [5,7]
//        /       \            /        \
//      (2)4       (2)5       (2)6       (1)7
//    /[1,2]\    /[3,4]\     /[5,6]\    /[7,7]\
// (1)8(1)9(1) 10(1)11(1) 12(1)13(1) 14(1)  15(0)
//  [1]   [2]   [3]  [4]   [5]  [6]   [7]  
//  turn1: pre = 0, index = 3, last = 3
//                      (6)1
//              /                  \
//           (3)2                  (3)3
//        /       \            /        \
//      (2)4      (1)5       (2)6       (1)7
//     / \        / \        / \        / \
// (1)8(1)9(1) 10(0)11(1) 12(1)13(1) 14(1)15(0)
//  [1]   [2]   [3]  [4]   [5]  [6]   [7]  [8]
//  turn1: pre = 2, index = 5, last = 6


// turn: n
// choose: 1
// array update: n
// n^2 
// but teacher: O(nk)

// array update: segment tree
// k-th
// nlogn

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
int sum(vector<int> &tree, int node, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return 0;
    }
    if (i <= start && end <= j) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, i, j) + sum(tree, node*2+1, (start+end)/2+1, end, i, j);
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
    int n,k;
    scanf("%d %d",&n,&k);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> ans(n+1);
    vector<int> tree(tree_size);
    init(tree, 1, 1, n); // init: 1 1 1 1 .... 1
    int last = 0;
    printf("<");
    for (int i=n; i>=1; i--) { // turn: n
        int pre = 0;
        if (last != 0) {
            pre = sum(tree, 1, 1, n, 1, last);
        }
        int index = (pre + k) % i; //0+3%7=3 (turn1), 2+3%6=5 (turn2), 4+3%5=2 (turn3)
        if (index == 0) {
            index = i;
        }
        last = kth(tree, 1, 1, n, index);
        printf("%d", last); // last: a[3] (turn1), a[5](turn2), a[2](turn3) 
        if (i != 1) {
            printf(", ");
        }
        update(tree, 1, 1, n, last, -1); // update 1->0
    }
    printf(">\n");
    return 0;
}