#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// ai > aj > ak, i < j < k
// brute force
// n*(n-1)*(n-2)/3!

// i < j, A[i]>A[j]
// factory, bubble sort problem

// i < j, A[i]>A[j]
//   tree > A[k]

// tree1[j] : i<j, A[i]>A[j]
// tree2
// (i<j)<k
// (A[i]>A[j]) > A[k]
// tree2[k]

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long sum(vector<long long> &tree, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= i&-i;
    }
    return ans;
}
long long sum(vector<long long> &tree, int start, int end) {
    if (start > end) return 0;
    return sum(tree, end) - sum(tree, start-1);
}
void update(vector<long long> &tree, int i, long long diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += i&-i;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> a(n+1);
    vector<long long> tree1(n+1);
    vector<long long> tree2(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    long long ans = 0;
    //     i : 1 2 3 4
    //   a[i]: 3 3 2 1
    //      idx : 1 2(3)4
    //tree1[idx]:     1   -> sum1 : 0 (cross)
    //tree2[idx]:     0   -> sum2 : 0 (cross)
    //tree1[idx]:     2   -> sum1 : 0 (cross)
    //tree2[idx]:     0   -> sum2 : 0 (cross)
    //      idx : 1(2)3 4
    //tree1[idx]:   1 2   -> sum1 : 2 (cross)
    //tree2[idx]:   2 0   -> sum2 : 0 
    //      idx :(1)2 3 4
    //tree1[idx]: 1 1 2   -> sum1 : 5 (cross)
    //tree2[idx]: 5 2 0   -> sum2 : 2
    for (int i=1; i<=n; i++) {
        update(tree1, a[i], 1);
        update(tree2, a[i], sum(tree1, a[i]+1, n)); // chain
        ans += sum(tree2, a[i]+1, n); //chain
    }
    printf("%lld\n",ans);
    return 0;
}