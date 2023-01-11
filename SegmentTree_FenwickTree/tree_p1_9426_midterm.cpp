#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// midterm : sort > mid value
// sum of midterm : (n-k+1) * O(sort=nlogn)
// n^2logn 
// n (1<=n<=250,000)  
// k (1<=k<=5'000)

// sum : effective! segment tree k-th
// nlogn

// 1 5 2 7 3 4 1 6
// n = 8, k = 3
// (1 5 2) = 2
// (5 2 7) = 5
// (2 7 3) = 3
// (7 3 4) = 4
// (3 4 1) = 3
// (4 1 6) = 4

// O(NK)

// n=7, k=3
// a[1] a[2] a[3] a[4] a[5] a[6] a[7]
// --------------
//     tree : 2-th
//      -------------
//          tree :2-th
//           --------------
//              tree:2-th

// a[i] : tree in(logMax(65535)), out(logMax) one time
// k-th find : logMax
// n-k+1 = n
//-> n* (logM+logM+logM) = nlogM

#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 65536;
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
    int n,k;
    scanf("%d %d",&n,&k);
    int h = (int)ceil(log2(MAX));
    int tree_size = (1 << (h+1));
    vector<int> a(n);
    vector<int> tree(tree_size);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<k-1; i++) { // 0~k-2
        update(tree, 1, 0, MAX-1, a[i], 1); // 0<= a[i] <=65535
    }
    long long ans = 0;
    //(turn 1) i: 0,1,2,3,......k-2,(add:k-1) (num: k) -> (k+1/2 : mid term index)
    //(turn 1) i: 0(remove:i-k+1 = k-1-k+1=0),1,2,3,4.....,k-2,k-1
    //(turn 2) i: 1,2,3,4,......k-1,(add:k) (num: k) 
    // ...
    for (int i=k-1; i<n; i++) { 
        update(tree, 1, 0, MAX-1, a[i], 1); // add i
        ans += (long long)kth(tree, 1, 0, MAX-1, (k+1)/2);
        update(tree, 1, 0, MAX-1, a[i-k+1], -1); // remove i-k+1
    }
    printf("%lld\n",ans);
    return 0;
}



