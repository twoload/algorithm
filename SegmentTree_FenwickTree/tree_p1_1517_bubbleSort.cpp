#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// 1<= n <= 500'000
// 0 <= A[i] <= 1'000'000'000
// my idea
//  bubble sort = O(n^2)
//  segment tree
//  range mirror

// = count the inversion of sequence
//   i < j
//   A[i] > A[j]
// = factory problem same solution
// 10 1 5 2 3
//   X ......  cross number
//  1 2 3 5 10

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int l;
void update(vector<int> &tree, int i, int diff) {
    while (i <= l) {
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
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    // sorted
    b.erase(unique(b.begin(), b.end()), b.end());
    map<int, int> d;
    for (int i=0; i<b.size(); i++) {
        d[b[i]] = i+1; // only size is important
    }
    for (int i=0; i<n; i++) {
        a[i] = d[a[i]];// a[i]: 0~1'000'000'000 -> 0~500'000
    }
    long long ans = 0;
    vector<int> tree(n+1);
    l = n;
    for (int i=0; i<n; i++) {
        // a[i]: 10 1 5 2 3
        // b[i]:  1 2 3 5 10
        // a[i]:  5 1 4 2 3 (range change)
        // b[i]:  1 2 3 4 5
        // tree:  0 0 0 0 0
        // a[i]: (5)1 4 2 3
        // tree:  0 0 0 0 1 -> sum =0
        // a[i]:   (1)4 2 3
        // tree:  1 0 0 0 1 -> sum = 1
        //                -
        // a[i]:     (4)2 3
        // tree:  1 0 0 1 1 -> sum = 1+1 2
        //              ---
        // a[i]:       (2)3
        // tree:  1 1 0 1 1 -> sum = 2+2 4
        // a[i]:         (3)
        // tree:  1 1 1 1 1 -> sum = 4+2 6
        //              ---
        ans += (long long)sum(tree, a[i]+1, n);
        update(tree, a[i], 1);
    }
    printf("%lld\n",ans);
    return 0;
}