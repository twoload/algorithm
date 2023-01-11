#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// n = 100'000
// m = 100'000
// O(nm) : too big

// multiply -> fenwick tree (x) (sum)
// basic idea : segment tree (1,-1,0)
// but fenwick tree is possible
//     0 -> inf
//     if num of minus == even  -> +
//     if num of minus == odd   -> -

#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 200000; // n <=100000 -> inf = 2*max(n)
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= i&-i;
    }
    return ans;
}
int sum(vector<int> &tree, int start, int end) {
    return sum(tree, end) - sum(tree, start-1);
}
void update(vector<int> &tree, int i, int diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += i&-i;
    }
}
int main() {
    int n,m;
    while (scanf("%d %d",&n,&m) == 2) {
        vector<int> a(n+1);
        vector<int> tree(n+1);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            if (a[i] < 0) {
                update(tree, i, 1); // minus => 1
            } else if (a[i] == 0) {
                update(tree, i, inf); // 0 => inf (100'000 x 2)
            }
        }
        while (m--) {
            char cmd;
            scanf(" %c",&cmd);
            if (cmd == 'C') {
                int index, value;
                scanf("%d %d",&index,&value);
                //-> revert to the origin
                if (a[index] < 0) {
                    update(tree, index, -1);
                } else if (a[index] == 0) {
                    update(tree, index, -inf);
                }
                //<- revert
                a[index] = value; // change
                //-> update again
                if (a[index] < 0) {
                    update(tree, index, 1);
                } else if (a[index] == 0) {
                    update(tree, index, inf);
                }
                //<- update
            } else if (cmd == 'P') {
                int start, end;
                scanf("%d %d",&start, &end);
                int cnt = sum(tree, start, end);
                if (cnt > n) { // inf
                    putchar('0');
                } else if (cnt % 2 == 0) { // num of minus
                    putchar('+');
                } else {
                    putchar('-');
                }
            }
        }
        puts("");
    }
    return 0;
}