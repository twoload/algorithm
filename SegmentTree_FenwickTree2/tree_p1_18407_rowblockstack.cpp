#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// range : 1'000'000'000
// n = 100'000

// teacher
// block location = the highest colume's height + 1
//       segment    maximum

// 1 <= Wi, Di <= 1'000'000'000  : too big!!! (tree size??? impossible)
// but n is 100'000

// start   end  : 2n = 200'000 : tree size  (compression)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	} else {
		init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = max(tree[node*2], tree[node*2+1]);
	}
}
void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
        tree[node] = max(tree[node], lazy[node]);
		if (start != end) {
			lazy[node*2] = max(lazy[node*2], lazy[node]);
			lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
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
		tree[node] = max(tree[node], val);
		if (start != end) {
			lazy[node*2] = max(lazy[node*2], val);
			lazy[node*2+1] = max(lazy[node*2+1], val);
		}
		return;
	}
	update_range(tree, lazy, node*2, start, (start+end)/2, left, right, val);
	update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, val);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}
int query(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right) {
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int t1 = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    int t2 = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    return max(t1,t2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> b;
    for (int i=0; i<n; i++) {
        int l, p;
        cin >> l >> p;
        int st = p;     // start
        int ed = p+l-1; // end
        a[i] = make_pair(st,ed);
        b.push_back(st);
        b.push_back(ed);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    // compression
    for (int i=0; i<n; i++) {
        int x = lower_bound(b.begin(), b.end(), a[i].first) - b.begin();
        int y = lower_bound(b.begin(), b.end(), a[i].second) - b.begin();
        a[i] = make_pair(x,y);
    }
    int m = b.size();
    int h = (int)ceil(log2(m));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    vector<int> lazy(tree_size);
    for (int i=0; i<n; i++) {
        // find current max height
        int max_h = query(tree, lazy, 1, 0, m-1, a[i].first, a[i].second);
        // update height(cur max height+1) in range (st~ed)
        update_range(tree, lazy, 1, 0, m-1, a[i].first, a[i].second, max_h+1);
    }
    int ans = tree[1];
    cout << ans << '\n';
    return 0;
}

