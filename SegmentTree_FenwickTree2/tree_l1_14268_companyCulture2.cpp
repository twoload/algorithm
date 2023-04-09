#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
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
        tree[node] += (end-start+1)*diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int index) {
    update_lazy(tree, lazy, node, start, end);
    if (index > end || index < start) {
        return 0;
    }
    if (start == end && start == index) {
        return tree[node];
    }
    int mid = (start+end)/2;
    if (index <= mid) {
        return query(tree, lazy, node*2, start, mid, index);
    } else {
        return query(tree, lazy, node*2+1, mid+1, end, index);
    }
}
int timer = 0;
vector<int> g[100001];
int tin[100001];
int tout[100001];
void dfs(int x) {
    tin[x] = ++timer;
    for (int y : g[x]) {
        dfs(y);
    }
    tout[x] = ++timer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int p;
        cin >> p;
        if (p == -1) continue;
        g[p].push_back(i);
    }
    dfs(1);
    int h = (int)ceil(log2(timer));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    vector<int> lazy(tree_size);
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int index, val;
            cin >> index >> val;
            update_range(tree, lazy, 1, 1, timer, tin[index], tout[index], val);
        } else if (what == 2) {
            int index;
            cin >> index;
            cout << query(tree, lazy, 1, 1, timer, tin[index]) << '\n';
        }
    }
    return 0;
}