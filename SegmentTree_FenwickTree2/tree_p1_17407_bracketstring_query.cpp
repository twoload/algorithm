#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// ( : +1
// ) : -1
// () = +1-1 = 0
// segment sum = 0
// update

// s : 100'000
// m : 100'000

// normal : O(s*m)
// segment query = nlog(n)

// lazy propagation
// query = log(n)

// teacher...
// corrent bracket string
// num of open bracket >= num of close bracket in all position i
// num of open bracket >= num of close bracket at last position
// open: +1, close: -1
// all sum : 0, accumulated sum should not be minus(-)
//              = minimum value

// -> sum segment tree
// -> min segment tree

// sum[node] = [start,end] sum
// min[node] = [start,end] min among accumulated sum

// ()()()()
// init
//              0-7
//           (s:0,m:0)
//      0-3            4-7
//     (s:0,
//      m:0)
//   0-1   2-3     4-5     6-7 
// (s:1,  (s:-1
//  m:1)   m:-1)

// update 2
// ((()()()
// init
//              0-7
//           (s:2,m:1)
//      0-3            4-7
//     (s:2,          (s:0
//      m:1)           m:0)
//   0-1   2-3     4-5     6-7
//  (2,1) (0,0)
//  0   1 2   3   4   5   6   7 
// (1, (1,
//  1)  1)

// update 7
// ((()()))
// init
//              0-7
//           (s:0,m:0) m = sum+min_sum = 2-2 = 0 : OK
//      0-3            4-7
//     (s:2,          (s:-2
//      m:1)           m:-2)
//   0-1   2-3     4-5     6-7 
//  (2,1) (0,0)   (0,0)  (-2,-2)
//  0   1 2   3   4   5   6   7 
// (1, (1,
//  1)  1)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct SegmentTree {
    struct Node {
        int sum, min_sum;
        void init(Node l, Node r) {
            sum = l.sum + r.sum;
            min_sum = min(l.min_sum, l.sum + r.min_sum);
        }
    };
    vector<Node> tree;
    int n;
    SegmentTree(string s) {
        n = (int)s.length();
        int h = (int)ceil(log2(n+1));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size);
        init(s);
    }
    void init(string &s, int node, int start, int end) {
        if (start == end) {
            if (s[start] == '(') {
                tree[node] = {1, 1};
            } else {
                tree[node] = {-1, -1};
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
    void update(int node, int start, int end, int index) {
        if (index < start || end < index) return;
        if (start == end) {
            tree[node].sum = -tree[node].sum;            // reverse
            tree[node].min_sum = -tree[node].min_sum;    // reverse
            return;
        }
        int mid = (start+end)/2;
        update(node*2, start, mid, index);
        update(node*2+1, mid+1, end, index);
        tree[node].init(tree[node*2], tree[node*2+1]);
    }
    int update(int index) {
        update(1, 0, n-1, index);
        if (tree[1].sum == 0 && tree[1].min_sum == 0) {
            return 1;
        } else {
            return 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    SegmentTree tree(s);
    int m;
    cin >> m;
    int ans = 0;
    while (m--) {
        int index;
        cin >> index;
        ans += tree.update(index-1);
    }
    cout << ans << '\n';
    return 0;
}




