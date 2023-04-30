#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// segment tree : sum

// query : logn
// m query : mlogn

// laza propagation ???

// teacher
// DP : d[i] = max(d[i-1] + a[i], a[i])
//            O(m*n)

// segment tree
// 1.left side
// 2.right side
// 3.left---right side

// segment tree 4 
// 1.sum[node] = [start,end] sum
// 2.left[node] = [start, i] max sum
// 3.right[node] = [i, end] max sum
// 4.best[node] = [start,end] max continuous sum

// |       |       |
//  <-----> <----->
// sum[node] = [start,end] sum
// sum[node] = sum[node*2] + sum[node*2+1]

// |       |       |
//  <---> 
//  <---------->
// left[node] = [start, i] max sum
// left[node]= max(left[node*2], sum[node*2]+left[node*2+1])

// |       |       |
//            <---> 
//     <---------->
// right[node] = [i,end] max sum
// right[node]= max(right[node*2], sum[node*2+1]+right[node*2+1])

// |       |       |
//  <---> only left
//            <----> only right
//     <---|----> left---right
// best[node] = [start,end] max continuous sum
// best[node] = max(best[node*2], best[node*2+1], right[node*2]+left[node*2+1])
//                   only left       only right        left-----right



#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const long long inf = 1000000LL * 1000000LL;
struct SegmentTree {
    struct Node {
        long long sum, left, right, best;
        void init(Node l, Node r) {
            sum = l.sum + r.sum;
            left = max(l.left, l.sum + r.left);
            right = max(r.right, l.right + r.sum);
            best = max({l.best, r.best, l.right + r.left});
        }
    };
    vector<Node> tree;
    int n;
    SegmentTree(int _n) {
        n = _n;
        int h = (int)ceil(log2(n+1));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size);
    }
    void init(vector<int> &a, int node, int start, int end) {
        if (start == end) {
            tree[node] = {a[start], a[start], a[start], a[start]};
            return;
        }
        int mid = (start+end)/2;
        init(a, node*2, start, mid);
        init(a, node*2+1, mid+1, end);
        tree[node].init(tree[node*2], tree[node*2+1]);
    }
    void init(vector<int> &a) {
        init(a, 1, 0, n-1);
    }
    Node query(int node, int start, int end, int i, int j) {
        if (i > end || j < start) {
            // sum, left, right, best
            // (+, max, max, max) -> (0, -inf, -inf, -inf)
            return Node({0, -inf, -inf, -inf});
        }
        if (i <= start && end <= j) {
            return tree[node];
        }
        int mid = (start+end)/2;
        Node left = query(node*2, start, mid, i, j);
        Node right = query(node*2+1, mid+1, end, i, j);
        Node ans;
        ans.init(left, right);
        return ans;
    }
    long long query(int i, int j) {
        return query(1, 0, n-1, i, j).best;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    SegmentTree tree(n);
    tree.init(a);
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << tree.query(l-1, r-1) << '\n';
    }
    return 0;
}
