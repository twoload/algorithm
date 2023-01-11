#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// lis2 : O(NlogM)
//        N = 1'000'000
//        M = 1'000'000 -> 2'000'000'000
// It's important only number's size comparison
//       2, 50, 25, 20, 35, 60, 3, 8
// (sort)2, 3, 8, 20, 25, 35, 50, 60
// (numb)1, 2, 3, 4, 5, 6, 7, 8  (1~N)
// <- coordinate compression

// 1<=A[i]<=N

// lis3 : O(NlogN) with coordinate compression


#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int maximum(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    // left child : node * 2      [start, start+end/2]
    // right child : node * 2 + 1 [start+end/2, end]
    return max(maximum(tree, node*2, start, (start+end)/2, left, right), maximum(tree, node*2+1, (start+end)/2+1, end, left, right));
}
void update(vector<int> &tree, int node, int start, int end, int i, int value) {
    if (i > end || i < start) {
        return;
    }
    // if tree[node] > value, let it be (don't update it as value)
    tree[node] = max(tree[node], value); // ??? -> Ok
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, i, value);
        update(tree, node*2+1, (start+end)/2+1, end, i, value);
    }
}
const int MAX = 1000000;
int main() {
    int n;
    scanf("%d", &n);
    //-> changed
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end()); // erase duplicate
    map<int, int> d;
    //       a[i]:    2, 50, 25, 20, 35, 60, 3, 8
    // (sort)b[i]:    2, 3, 8, 20, 25, 35, 50, 60
    // (numb)d[b[i]]: 1, 2, 3, 4, 5, 6, 7, 8  (1~N)
    for (int i=0; i<b.size(); i++) {
        d[b[i]] = i+1;
    }
    for (int i=0; i<n; i++) {
        a[i] = d[a[i]]; //coordinate compression
    }
    //<- changed
    int h = (int)ceil(log2(MAX));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    int ans = 0;
    for (int i=0; i<n; i++) {
        int num = a[i];
        // max [1, num-1]
        //tree[i]: 0 0 0 0 0  // LIS length
        //             2     A[2]=3 >[1,2] max:1(len)+3 > 2 (len)
        int cur = maximum(tree, 1, 1, MAX, 1, num-1);
        if (ans < cur + 1) {
            ans = cur + 1;
        }
        update(tree, 1, 1, MAX, num, cur+1);
    }
    printf("%d\n", ans);
    return 0;
}