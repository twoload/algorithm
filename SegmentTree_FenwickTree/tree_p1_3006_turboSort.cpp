#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// tree  : 1 1 1 1 1 1 1
//         -------        4
// input : 5 4 3 7(1)2 6
// output:(1)5 4 3 7 2 6
// tree  : 1 1 1 1 0 1 1
//                   ---  2
// input : 5 4 3(7)  2 6
// output: 1 5 4 3 2 6(7)
// tree  : 1 1 1 0 0 1 1
//         -----          3
// input : 5 4 3  (2)6 
// output: 1(2)5 4 3 6 7
// tree  : 1 1 1 0 0 0 1

#include <cstdio>
#include <vector>
using namespace std;
int sum(vector<int> &tree, int x) {
    int ans = 0;
    for (int i=x; i>0; i -= i&-i) {
        ans += tree[i];
    }
    return ans;
}
void update(vector<int> &tree, int x, int diff) {
    for (int i=x; i<tree.size(); i += i&-i) {
        tree[i] += diff;
    }
}
int sum(vector<int> &tree, int x, int y) {
    return sum(tree, y) - sum(tree, x-1);
}
int main() {
    int n, m, k;
    scanf("%d",&n);
    vector<int> a(n+1);
    vector<int> tree(n+1);
    vector<int> position(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        position[a[i]] = i; // range compression
        update(tree, i, 1); // tree: 1 1 1 1 1 1 1
    }
    int left = 1;
    int right = n;
    for (int i=1; i<=n; i++) {
        if (i%2 == 1) { // odd : from front
            update(tree, position[left], -1);
            printf("%d\n",sum(tree, 1, position[left]));
            left += 1; // 1->2->3...
        } else { // even : from back
            update(tree, position[right], -1);
            printf("%d\n",sum(tree, position[right], n));
            right -= 1; // 7->6->5...
        }
    }
    return 0;
}