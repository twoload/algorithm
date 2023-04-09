#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// (s-e)
int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) ^ init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        int len = (end-start+1);
        if (len % 2 == 1) {
            tree[node] ^= lazy[node];
        }
        if (start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right, int diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        int len = (end-start+1);
        if (len % 2 == 1) {
            tree[node] ^= diff;
        }
        if (start != end) {
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}
int query(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return query(tree, lazy, node*2, start, (start+end)/2, left, right) ^ query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    vector<int> lazy(tree_size);
    int m;
    cin >> m;
    init(a, tree, 1, 0, n-1);
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int start, end, val;
            cin >> start >> end >> val;
            update_range(tree, lazy, 1, 0, n-1, start, end, val);
        } else if (what == 2) {
            int start, end;
            cin >> start>> end;
            cout << query(tree, lazy, 1, 0, n-1, start, end) << '\n';
        }
    }
    return 0;
}
