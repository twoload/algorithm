#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// teacher
// segment 3ea

// s                 e
// |        |        |
//  <-left-> <-right->
//     (         )

// done = min(open[node*2], close[node*2+1])
//        num matching bracket
// ans[node] = [start,end] answer
//    = ans[node*2] + ans[node*2+1] + done*2
// open[node] = [start,end] not match open
//    = open[node*2] + open[node*2+1] - done
// close[node] = [start,end] not match close
//    = close[node*2] + close[node*2+1] - done


#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
struct SegmentTree {
    struct Node {
        int ans, open, close;
        void init(Node l, Node r) {
            int done = min(l.open, r.close);
            ans = l.ans + r.ans + 2*done;
            open = l.open + r.open - done;
            close = l.close + r.close - done;
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
    void init(string &s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {0, 0, 0};
            if (s[start] == '(') {
                tree[node].open = 1;
            } else {
                tree[node].close = 1;
            }
            return;
        }
        int mid = (start+end)/2;
        init(s, node*2, start, mid);
        init(s, node*2+1, mid+1, end);
        tree[node].init(tree[node*2], tree[node*2+1]);
    }
    void init(string &s) {
        init(s, 1, 0, n-1);
    }
    Node query(int node, int start, int end, int i, int j) {
        if (i > end || j < start) {
            return Node({-1, 0, 0});
        }
        if (i <= start && end <= j) {
            return tree[node];
        }
        int mid = (start+end)/2;
        Node left = query(node*2, start, mid, i, j);
        Node right = query(node*2+1, mid+1, end, i, j);
        if (left.ans == -1) return right;
        if (right.ans == -1) return left;
        Node ans;
        ans.init(left, right);
        return ans;
    }
    int query(int i, int j) {
        return query(1, 0, n-1, i, j).ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    SegmentTree tree(n);
    tree.init(s);
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << tree.query(l-1, r-1) << '\n';
    }
    return 0;
}
