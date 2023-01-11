#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// n ( 2<= n <= 200'000)
// O(n^2)
//  1-th tree
//  2-th tree (1-2)
//  3-th tree (1-3) (2-3)
// sum of distance to all trees from self
// cnt[i] = num of trees which is planted in index i
// dist[i] = cnt[i]*i (sum of coordincates which is planted in i)
// x5
// x1~x4 < x5
// (x5-x1) + (x5-x2) + (x5-x3) + (x5-x4) 
// 4*x5 - (x1+x2+x3+x4) = O(logN) => nlogn
// ----   -------------
// cnt     dist
// |xi - xj|
//  xi > xj => xi - xj
//  xi < xj => xj - xi
// ( L ) xi ( R )
// CL = sum(cnt, 1, x[i]-1)
// CL x x[i] - sum(all x0) 
//    = CL x x[i] - sum(dist, 1, x[i]-1)
//    = x[i] * sum(cnt, 1, x[i]-1) - sum(dist, 1, x[i]-1)
//      ----   ------------------    --------------------
//      index      count=order       sum of diff of distance
//       x5   *        4           - (x1+x2+x3+x4)
// CR = sum(cnt, x[i]+1, L)
//    = sum(dist,x[i]+1,L) - CR x x[i]
//    = -x[i] * sum(cnt, x[i]+1, L) + sum(dist,x[i]+1,L) 
//    = opposite sign only

// x[i] x (sum(cnt,1,x[i]-1) - sum(cnt,x[i]+1,L))
// + sum(dist, x[i]+1, L) - sum(dist,1,x[i]-1)

#include <cstdio>
#include <vector>
using namespace std;
long long mod = 1000000007LL;
int l = 200000; // 2 <= n <= 200'000
void update(vector<long long> &a, int i, long long diff) {
    while (i <= l) {
        a[i] += diff;
        i += (i & -i);
    }
}
long long sum(vector<long long> &a, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += a[i];
        i -= (i & -i);
    }
    return ans;
}
long long sum(vector<long long> &a, int l, int r) {
    if (l > r) return 0;
    return sum(a, r) - sum(a, l-1);
}
int main() {
    vector<long long> cnt(l+1);  // tree1
    vector<long long> dist(l+1); // tree2
    int n;
    scanf("%d",&n);
    long long ans = 1; // multiply identity
    for (int i=0; i<n; i++) {
        long long x;
        scanf("%lld",&x); // 0 <= x <= 200'000 (index)
        x += 1; // 1 <= x <= 200'001
        if (i != 0) {
            long long price = x*(sum(cnt, 1, x-1) - sum(cnt, x+1, l)) - sum(dist,1, x-1) + sum(dist, x+1, l);
            price = price % mod;
            ans = (ans * price) % mod;
        }
        update(cnt, x, 1); // for count
        update(dist, x, x);// for sum of distance 
    }
    printf("%lld\n",ans);
    return 0;
}