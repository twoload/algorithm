#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1 2 3 4 5 6 7 8
// O O x O O O     -> 3

// teacher : sum segment tree

/**
 *            (3)
 *        /        \
 *      (3)          0 
 *     /   \      /   \
 *    (2) (1)     0     0
 *   / \  / \   / \   / \
 *  1  2  3  4  5  6  7  8
 * (1)(1)(1)
 * 
 */ 

// end - start + 1 != tree[node]
// there might be empty tree subnode.

// axis compression

// answer: l-1, l, l+1, r-1, r, r+1, 1

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
// 1 (+), -1 (-1), 2 (toggle)
int calc_lazy(int cur, int val) {
    int ans = 0;
    if (val == 1 || val == -1) { // + or -
        ans = val;
    } else { // toggle
        if (cur == 1 || cur == -1) { // + or -
            ans = -cur;
        } else { // 2 -> 0, 0 -> 2
            ans = 2 - cur;
        }
    }
    return ans;
}
void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
    if (lazy[node] == 0) return; // do nothing
    if (lazy[node] == 1) { // +
        tree[node] = end - start + 1;
    } else if (lazy[node] == -1) { // -
        tree[node] = 0;
    } else { // toggle
        tree[node] = (end - start + 1) - tree[node];
    }
    // lazy propagation
    if (start != end) { // it's not leaf
        lazy[node*2] = calc_lazy(lazy[node*2], lazy[node]);
        lazy[node*2+1] = calc_lazy(lazy[node*2+1], lazy[node]);
    }
    lazy[node] = 0;
}
void update(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right, int val) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        lazy[node] = calc_lazy(lazy[node], val); 
        update_lazy(tree, lazy, node, start, end);
        return;
    }
    update(tree, lazy, node*2, start, (start+end)/2, left, right, val);
    update(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
    update_lazy(tree, lazy, node, start, end);
    if (start == end) {
        return start;
    }
    int mid = (start+end)/2;
    update_lazy(tree, lazy, node*2, start, mid);
    // **** important ****
    if (mid - start + 1 == tree[node*2]) { // all occupied
        return query(tree, lazy, node*2+1, mid+1, end);
    } else { // might be empty somewhere
        return query(tree, lazy, node*2, start, mid);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int,long long,long long>> queries(n);
    vector<long long> a;
    // all answers should be l-1,l,l+1,r,r-1,r+1,1
    for (int i=0; i<n; i++) {
        int q;
        long long l, r;
        cin >> q >> l >> r;
        queries[i] = make_tuple(q, l, r);
        // l-1, l, l+1, r-1, r, r+1
        for (int j=-1; j<=1; j++) {
            if (l+j >= 1) {
                a.push_back(l+j);
            }
            if (r+j >= 1) {
                a.push_back(r+j);
            }
        }
    }
    // 1
    a.push_back(1);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();
    int h = (int)ceil(log2(m));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    vector<int> lazy(tree_size);
    for (int i=0; i<n; i++) {
        int q;
        long long real_l, real_r;
        tie(q, real_l, real_r) = queries[i];
        int l = lower_bound(a.begin(), a.end(), real_l) - a.begin();
        int r = lower_bound(a.begin(), a.end(), real_r) - a.begin();
        if (q == 1) { // add
            update(tree, lazy, 1, 0, m-1, l, r, 1);
        } else if (q == 2) { // remove
            update(tree, lazy, 1, 0, m-1, l, r, -1);
        } else if (q == 3) { // toggle
            update(tree, lazy, 1, 0, m-1, l, r, 2);
        }
        cout << a[query(tree, lazy, 1, 0, m-1)] << '\n';
    }
    return 0;
}
