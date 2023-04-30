#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// sum segment
// segment update

// +
// -

// teacher
// tree[node].lower = over lower
// tree[node].upper = under lower

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct SegmentTree {
    struct Node {
        int lower, upper;
        void update(Node parent) {
            if (lower < parent.lower) {
                lower = parent.lower;
            }
            if (upper < parent.lower) {
                upper = parent.lower;
            }
            if (lower > parent.upper) {
                lower = parent.upper;
            }
            if (upper > parent.upper) {
                upper = parent.upper;
            }
        }
    };
    vector<Node> tree;
    vector<int> ans;
    int n;
    SegmentTree(int _n) {
        n = _n;
        int h = (int)ceil(log2(n+1));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size);
    }
    void update_lazy(int node, int start, int end) {
        if (start != end) {
            tree[node*2].update(tree[node]);
            tree[node*2+1].update(tree[node]);
            tree[node] = {0, 100000}; // lower, upper
        }
    }
    void update(int node, int start, int end, int op, int left, int right, int height) {
        if (end < left || right < start) {
            return;
        }
        if (left <= start && end <= right) {
            if (op == 1) { // +
                tree[node].update({height, 100000}); // make lower to height, let upper be (max:100'000)
            } else { // -
                tree[node].update({0, height}); // let lower be, make upper to height (min:0)
            }
            return;
        }
        update_lazy(node, start, end);
        int mid = (start+end)/2;
        update(node*2, start, mid, op, left, right, height);
        update(node*2+1, mid+1, end, op, left, right, height);
    }
    void update(int op, int left, int right, int height) {
        update(1, 0, n-1, op, left, right, height);
    }
    void dfs(int node, int start, int end) {
        if (start == end) { // leaf
            ans[start] = tree[node].lower;
            return;
        }
        update_lazy(node, start, end);
        int mid = (start+end)/2;
        dfs(node*2, start, mid);
        dfs(node*2+1, mid+1, end);
    }
    vector<int> dfs() {
        ans.resize(n);
        dfs(1, 0, n-1);
        return ans;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    SegmentTree tree(n);
    while (m--) {
        int op, left, right, height;
        cin >> op >> left >> right >> height;
        tree.update(op, left, right, height);
    }
    auto ans = tree.dfs();
    for (int i=0; i<n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
