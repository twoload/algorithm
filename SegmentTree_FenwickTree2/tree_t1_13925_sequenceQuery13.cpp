#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// sum segment
// update segment

// lazy propagation

// teacher
// add lazy
// muliply lazy

// mul, add
// Ai = mul x Ai + add
// if +v
//    Ai = (mul x Ai + add) + v 
//       = (mul x Ai) + (add + v)
// if *v
//    Ai = (mul * Ai + add) * v
//    Ai = (mul * v * Ai) + (add * v)

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const long long mod = 1000000007LL;
struct SegmentTree {
    vector<long long> tree;
    // two lazy
    vector<long long> lazy_add; 
    vector<long long> lazy_mul;
    int n;
    SegmentTree(int _n) {
        n = _n;
        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size);
        lazy_add.resize(tree_size, 0);
        lazy_mul.resize(tree_size, 1);
    }
    void init(vector<long long> &a) {
        init(a, 1, 0, n-1);
    }
    void init(vector<long long> &a, int node, int start, int end) {
        // sum segment tree
        if (start == end) {
            tree[node] = a[start] % mod;
            return;
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = (tree[node*2] + tree[node*2+1]) % mod;
        }
    }
    void update_lazy(int node, int start, int end) {
        if (lazy_add[node] == 0 && lazy_mul[node] == 1) return; // do nothing
        // update tree[node]
        tree[node] = (tree[node]*lazy_mul[node] + (end-start+1)*lazy_add[node]) % mod;
        if (start != end) { // not leaf node
            // Ai = mul x Ai + add
            // if +v
            //    Ai = (mul x Ai + add) + v 
            //       = (mul x Ai) + (add + v)
            // if *v
            //    Ai = (mul * Ai + add) * v
            //    Ai = (mul * v * Ai) + (add * v)                    
            lazy_mul[node*2] = (lazy_mul[node]*lazy_mul[node*2]) % mod;
            lazy_mul[node*2+1] = (lazy_mul[node]*lazy_mul[node*2+1]) % mod;
            lazy_add[node*2] = (lazy_mul[node]*lazy_add[node*2] + lazy_add[node]) % mod;
            lazy_add[node*2+1] = (lazy_mul[node]*lazy_add[node*2+1] + lazy_add[node]) % mod;
        }
        lazy_add[node] = 0;
        lazy_mul[node] = 1;
    }
    void update(int what, int i, int j, long long val) {
        update(1, 0, n-1, what, i, j, val);
    }
    void update(int node, int start, int end, int what, int i, int j, long long val) {
        update_lazy(node, start, end);
        if (i > end || j < start) {
            return;
        }
        if (i <= start && end <= j) {
            if (what == 1) {
                lazy_add[node] = val % mod;
            } else if (what == 2) {
                lazy_add[node] = 0;
                lazy_mul[node] = val % mod;
            } else if (what == 3) {
                lazy_add[node] = val % mod;
                lazy_mul[node] = 0;
            }
            update_lazy(node, start, end);
            return;
        }
        int mid = (start+end)/2;
        update(node*2, start, mid, what, i, j, val);
        update(node*2+1, mid+1, end, what, i, j, val);
        tree[node] = (tree[node*2] + tree[node*2+1]) % mod;
    }
    long long query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }
    long long query(int node, int start, int end, int i, int j) {
        update_lazy(node, start, end);
        if (i > end || j < start) return 0;
        if (i <= start && end <= j) {
            return tree[node];
        } 
        int mid = (start+end)/2;
        return (query(node*2, start, mid, i, j) + query(node*2+1, mid+1, end, i, j)) % mod;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    SegmentTree tree(n);
    tree.init(a);
    int m;
    cin >> m;
    while (m--) {
        int what;
        cin >> what;
        if (what <= 3) {
            int st, ed;
            long long val;
            cin >> st >> ed >> val;
            tree.update(what, st-1, ed-1, val);
        } else if (what == 4) {
            int st, ed;
            cin >> st >> ed;
            cout << tree.query(st-1, ed-1) << '\n';
        }
    }
    return 0;
}
