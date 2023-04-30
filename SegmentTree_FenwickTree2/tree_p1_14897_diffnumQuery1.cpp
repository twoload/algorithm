#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// all num -> array
//            0, 1...
// too big : 1'000'000'000
// so n : 1'000'000
// compression is needed

// sum segment

// teacher
// A is not changed

// query sort


#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node]; // why +lazy[node]? (right-left+1)? -> leaf node's value is only important.!!!! (so it can be ignored)
        //printf("lazy: tree[%d] += %d => %d\n", node, lazy[node], tree[node]);
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node]; 
            //printf("lazy: lazy[%d] += %d => %d\n", node*2, lazy[node], lazy[node*2]);
            //printf("lazy: lazy[%d] += %d => %d\n", node*2+1, lazy[node], lazy[node*2+1]);
        }
        lazy[node] = 0;
    }
}
void update_range(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right, int val) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] += val;
        //printf("update: tree[%d] += %d => %d\n", node, val, tree[node]);
        if (start != end) {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
            //printf("update: lazy[%d] += %d => %d\n", node*2, val, lazy[node*2]);
            //printf("update: lazy[%d] += %d => %d\n", node*2+1, val, lazy[node*2+1]);
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, val);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, val);
    tree[node] = tree[node*2] + tree[node*2+1];
    //printf("update: tree[%d] = %d + %d => %d\n", node, tree[node*2], tree[node*2+1], tree[node]);
}
int query(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int index) {
    update_lazy(tree, lazy, node, start, end);
    if (start == end) {
        return tree[node];
    }
    int mid = (start+end)/2;
    if (index <= mid) {
        return query(tree, lazy, node*2, start, mid, index);
    } else {
        return query(tree, lazy, node*2+1, mid+1, end, index);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i=0; i<n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    vector<int> last(b.size(), -1);
    int m;
    cin >> m;
    vector<tuple<int,int,int>> q(m); // r l index
    vector<int> ans(m);
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        l -= 1; r -= 1;
        q[i] = make_tuple(r, l, i);
    }
    sort(q.begin(), q.end());
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    vector<int> lazy(tree_size);
    int j = 0;
    for (int i=0; i<m; i++) {
        int l, r, index;
        tie(r, l, index) = q[i];
        while (j <= r) {
            update_range(tree, lazy, 1, 0, n-1, last[a[j]]+1, j, 1);
            last[a[j]] = j;
            j += 1;
        }
        ans[index] = query(tree, lazy, 1, 0, n-1, l); // why l ? OK r: match(fixed). l is needed to find
    }
    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
