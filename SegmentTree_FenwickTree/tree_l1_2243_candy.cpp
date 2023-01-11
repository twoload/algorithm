#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// my idea
//   update: fenwick tree,
//   find order: binary search

// segment tree
//   k-th find

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 1'000'000;
int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, start+end); 
    }
}
void update(vector<int> &tree, int node, int start, int end, int i, int diff) {
    if ( i < start || i > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, i, diff);
        update(tree, node*2+1, (start+end)/2+1, end, i, diff);
    }
}
int kth(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end) {
        return start;
    } else {
        if (k <= tree[node*2]) {
            return kth(tree, node*2, start, (start+end)/2, k);
        } else {
            return kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
        }
    }
}
// O(m * log(MAX))
int main() {
    vector<int> a(MAX+1);
    int h = (int)ceil(log2(MAX+1));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    int m;
    scanf("%d", &m);
    while(m--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 2) {
            int box, diff;
            scanf("%d %d", &box, &diff);
            a[box] += diff;
            update(tree, 1, 1, MAX, box, diff);
        } else if (cmd == 1) {
            int k;
            scanf("%d", &k);
            int box = kth(tree, 1, 1, MAX, k);
            printf("%d\n", box);
            a[box] -= 1;
            update(tree, 1, 1, MAX, box, -1);
        }
    }
    return 0;
}
