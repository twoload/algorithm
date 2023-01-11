#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// t (1<= <100)
// n : num of all movie (0<= <=100'000)
// m : num of movie to watch (0<= <=100'000)
// 1) array element location is changed
// 2) need to count the order
// -> segment tree

// case1: if i use array,
// 1) remove : O(n)
// 2) put the front : O(1)
// -> O(nm) : tc: m

// case2: let removed on be empty
//   (0)     (0)    (0)
//   (0)     (0)   2(1)
//   (0)    4(1)   4(1)
//  1(1)    1(1)   1(1)
//  2(1)    2(1) -> (0)
//  3(1)    3(1)   3(1)
//  4(1) ->  (0)    (0)
//  5(1)    5(1)   5(1)  
//  O(nm) : remove=O(1), count=O(n)
//  mlog(n+m)
//  ex.
//  n=5, m=3
//  i: 1 2 3 4 5 6 7 8
//  a:()()() 1 2 3 4 5 -> 4
//  a:()() 4 1 2 3() 5 -> 5
//  a:() 5 4 1 2 3()()
//  tree size: n+m
//  sum : log(n+m)
//  edit: 2*log(n+m)
//  -> total: log(n+m) x m(tc) = mlog(n+m)

#include <cstdio>
#include <vector>
using namespace std;
int l = 0;
void update(vector<int> &tree, int i, int diff) {
    while (i <= l) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<int> tree(n+m+1); //1~n+m
        vector<int> position(n+1);
        l = n+m;
        for (int i=1; i<=n; i++) {
            update(tree, m+i, 1); // 0 0 0 1 1 1 1 1 : m+i
            position[i] = m+i; // p[1]=4,p[2]=5,p[3]=6,p[4]=7,p[5]=8
        }
        for (int i=m; i>=1; i--) {
            int x;
            scanf("%d", &x);
            // ex. x=4, p[4]=7, [1~6] sum = 3
            printf("%d ", sum(tree, position[x]-1));
            // pos:  ()()() 1 2 3 4 5
            // tree:  0 0 0 1 1 1 1 1
            //        0 0 0 1 1 1 0 1
            update(tree, position[x], -1);
            // p[4]=3
            // pos:  ()() 4 1 2 3() 5
            // tree:  0 0 1 1 1 1 0 1
            position[x] = i;
            update(tree, position[x], 1);
        }
    }
    return 0;
}