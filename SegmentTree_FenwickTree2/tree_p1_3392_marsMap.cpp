#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// update segment
// x,y <= 30'000
// x, y update
// in one direction, accumulate

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> xx,yy;
struct SegmentTree {
    struct Node {
        int len, cnt;
    };
    vector<Node> tree;
    int n;
    SegmentTree(int _n) {
        n = _n;
        int h = (int)ceil(log2(n+1));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size);
    }
    void update(int node, int start, int end, int i, int j, int val) {
        if (j < start || end < i) return; // out of range
        if (i <= start && end <= j) {
            tree[node].cnt += val;
        } else {
            int mid = (start+end)/2; // children
            update(node*2, start, mid, i, j, val);
            update(node*2+1, mid+1, end, i, j, val);
        }
        if (tree[node].cnt > 0) {
            tree[node].len = yy[end+1]-yy[start];
        } else {
            if (start == end) {
                tree[node].len = 0;
            } else {
                tree[node].len = tree[node*2].len + tree[node*2+1].len;
            }
        }
    }
    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }
    int query() {
        return tree[1].len;
    }
};
struct Rectangle {
    int x1, y1, x2, y2;
};
struct Event {
    int x, y1, y2, start;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
/**
 * 2
 * 10 10 20 20
 * 15 15 25 30
 * 
 * xx = 10,20,15,25 -> 10,15,20,25
 * yy = 10,20,15,30 -> 10,15,20,30
 * 
 * a[0]         [1]
 * x1 = 10->0  15->1
 * x2 = 20->2  25->3
 * y1 = 10->0  15->1
 * y2 = 20->2  30->3
 * 
 * e  [0] [1] [2] [3]            [0] [1] [2] [3]
 * x   0   2   1   3  sort by x   0   1   2   3
 * y1  0   0   1   1     =>       0   1   0   1
 * y2  2   2   3   3              2   3   2   3
 * s  +1  -1  +1  -1             +1  +1  -1  -1
 * 
 * 
 * 
 * ------- y index
 * |     ------- segment index 
 * |     |
 * v     v
 * 3 -----------------------
 *       2       |         |
 * 2 ------------------    -
 *       1  |    |    |    | 
 * 1 --------    -----------
 *       0  |         |
 * 0 ------------------
 * 
 *
 *       0-3
 *     /     \
 *    0-1    2-3
 *   /  \    /  \
 *  0    1  2    3
 * 
 * x,y1,y2,s = 0,0,2,1 = update(0,1,+1)
 *
 *       0-3
 *     (c:0,l:10)
 *     /     \
 *    0-1    2-3
 * (c:1,l:10)
 *   /  \    /  \
 *  0    1  2    3
 *  
 * size = xdiff * y(10)
 * x,y1,y2,s = 1,1,3,1 = update(1,2,+1)
 *
 *       0-3
 *    (c:0,l:20)
 *     /     \
 *    0-1    2-3
 *  (c:1,    (c:0,
 *   l:10)    l:10)
 *   /  \    /  \
 *  0    1  2    3
 *    (c:1,(c:1, 
 *     l:5) l:10
 * 
 * size = xdiff * y(20)
 * x,y1,y2,s = 2,0,2,-1 = update(0,1,-1)
 *
 *       0-3
 *    (c:0,l:15)
 *     /     \
 *    0-1    2-3
 *   (c:0,   (c:0,
 *    l:5)    l:10)
 *   /  \    /  \
 *  0    1  2    3
 *    (c:1,(c:1,
 *     l:5) l:10)
 *
 * size = xdiff * y(15)
 * x,y1,y2,s = 3,1,3,-1 = update(1,2,-1)
 *
 *
 *       0-3
 *    (c:0,l:0)
 *     /     \
 *    0-1    2-3
 *   (c:0,  (c:0,
 *    l:0)   l:0)
 *   /  \    /  \
 *  0    1  2    3
 *    (c:0,(c:0,
 *     l:0) l:0)
 *
 *  
 */ 
    vector<Rectangle> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        xx.push_back(a[i].x1);
        xx.push_back(a[i].x2);
        yy.push_back(a[i].y1);
        yy.push_back(a[i].y2);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.erase(unique(xx.begin(),xx.end()),xx.end());
    yy.erase(unique(yy.begin(),yy.end()),yy.end());
    vector<Event> e;
    // axis compression
    for (int i=0; i<n; i++) {
        a[i].x1 = lower_bound(xx.begin(),xx.end(),a[i].x1)-xx.begin();
        a[i].x2 = lower_bound(xx.begin(),xx.end(),a[i].x2)-xx.begin();
        a[i].y1 = lower_bound(yy.begin(),yy.end(),a[i].y1)-yy.begin();
        a[i].y2 = lower_bound(yy.begin(),yy.end(),a[i].y2)-yy.begin();
        e.push_back(Event({a[i].x1, a[i].y1, a[i].y2, 1}));
        e.push_back(Event({a[i].x2, a[i].y1, a[i].y2, -1}));
    }
    sort(e.begin(), e.end(), [](auto u, auto v ) {
        return u.x < v.x;
    });
    SegmentTree tree((int)yy.size());
    int ans = 0;
    // e.size = O(2N)
    for (int i=0; i<e.size(); i++) {
        // y2-1 : axis -> num of column : update:O(logN), query:O(logN) => O(2NlogN) = O(NlogN)
        tree.update(e[i].y1, e[i].y2-1, e[i].start);
        // to prevent duplicate
        if (i+1 < e.size() && e[i].x != e[i+1].x) {
            int width = xx[e[i+1].x]-xx[e[i].x];
            int height = tree.query();
            ans += width*height;
        }
    }
    cout << ans << '\n';
    return 0;
}