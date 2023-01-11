#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

//      2 1 2 4
//turn1:1 1 2 4
//      -
//turn2:1 0 2 4
//        -
//turn3:1 0 1 4
//          -
//turn4:1 0 1 3
//            -
//turn5:0 0 1 3
//      -
//turn6:0 0 0 3
//          -
//turn7:      2
//turn8:      1
//turn9:      0
//out  :5 2 6 9

//      2 1 2 4 (N) max = 1'000'000
//1     1(2)3 4
//2    (5) (6)7
//3           8
//4          (9)
//A[i]          max = 1'000'000'000
// O(1'000'000 x 1'000'000'000)
// O(nm) , n=1'000'000, m=1'000'000'000
//1     1(2)3 4  4-2 = 2
//-------------
//2    (5) (6)7  4+3*1 - 2, 4+3-1
//-------------
//3           8  7+1*2
//4          (9)
// O(n^2)
// -> Fenwich tree
// O(nlogn)

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
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
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> a(n+1);
    vector<int> tree(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i].first); //first: job amount
        a[i].second = i;         //secod: job index
        update(tree, i, 1);      //1 1 1 1
    }
    //  a: 2 1 2 4  //first:val, second:index
    //    (2,1),(1,2),(2,3),(4,4)
    //-> sorted (to solve in order to finish the job early)
    //    by based on value
    //    (1,2),(2,1),(2,3),(4,4)
    sort(a.begin()+1, a.end());
    long long total = 0;
    int last = 0;
    vector<long long> ans(n+1);
    int remain = n; // 4 : all job remains : not yet done
    for (int i=1; i<=n; i++) {
        // 1st round
        //   a[1].first = 1 
        //   last = 0 (init)
        //   it's done with turn 1.
        //   1 * 4 = 4 = total
        total += (long long)(a[i].first - last)*remain;
        //  remain = 4->3 (one is done)
        remain -= 1;
        //  last = a[1].first = 1 (turn 1)
        last = a[i].first;
        // ans[a[1].second=2] = 4 - 2(num of 1 in [3,4]) = 2
        ans[a[i].second] = total - (long long)sum(tree, a[i].second+1, n);
        // a[1].second=2 (origial index) - 1 = tree[] = 1->0
        update(tree, a[i].second, -1);
    }
    for (int i=1; i<=n; i++) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}