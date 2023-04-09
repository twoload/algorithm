#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
// a: 배열 a
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        if (lazy[node] & 1) {
            tree[node] = (end-start+1) - tree[node]; // ex. 11000 (2) ---(reverse)---> 00111 (3) = (5-2)
        }
        // leaf가 아니면
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
        if (diff & 1) {
            tree[node] = (end-start+1)-tree[node]; // ex. 11000 (2) ---(reverse)---> 00111 (3) = (5-2)
        }
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
int sum(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, lazy, node*2, start, (start+end)/2, left, right) + sum(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}
int main() {
    int n, m, k;
    scanf("%d %d",&n,&m);
    vector<int> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size); // sum
    vector<int> lazy(tree_size); // reverse count
    //init(a, tree, 1, 0, n-1);
    while (m--) {
        int what;
        scanf("%d",&what);
        if (what == 0) {
            int start, end;
            scanf("%d %d",&start,&end);
            update_range(tree, lazy, 1, 0, n-1, start-1, end-1, 1);
        } else if (what == 1) {
            int start, end;
            scanf("%d %d",&start,&end);
            printf("%d\n",sum(tree, lazy, 1, 0, n-1, start-1, end-1));
        }
    }
    return 0;
}
