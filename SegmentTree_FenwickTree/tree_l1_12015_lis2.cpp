#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// O(N^2) DP
//   D[i] = LIS length with A[i] is last
//        = max(D[j]) + 1
//          j < i, A[j] < A[i]
//   n = 1'000'000 => Too big!!!

// tree[i] : LIS length with i(the number) is last
// A[j]          A[i] 
// [1, A[i]-1]
//   1. be in front of = is in tree = order to solve
//   2. small number = section
//   3. LIS len max = make segment tree (LIS len max)

// i     : 1 2 3 4 5 6 7
//A[i]   : 1 3 2 4 3 4 2
// i     : 1 2 3 4 5
//tree[i]: 0 0 0 0 0  // LIS length
//         1         A[1]=1 >[1,0] max:0(len)   > 1 (len)
//             2     A[2]=3 >[1,2] max:1(len)+3 > 2 (len)
//           2       A[3]=2 >[1,1] max:1(len)+2 > 2 (len)
//               3   A[4]=4 >[1,3] max:2(len)+4 > 3 (len)
//             3     A[5]=3 >[1,2] max:2(len)+3 > 3 (len)
//               4   A[6]=4 >[1,3] max:3(len)+4 > 4 (len)
//                   A[7]=2 >[1,1] max:1(len)+1 > 2 (len)
// [ , ] section > segment tree
//       it's value is not index, but A[i]

// O(N log M) (tree has A[i] 0~1'000'000)
//   N : array length 
//   log M : find value during section

// segment tree
//   https://www.acmicpc.net/blog/view/9


#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
int maximum(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    // left child : node * 2      [start, start+end/2]
    // right child : node * 2 + 1 [start+end/2, end]
    return max(maximum(tree, node*2, start, (start+end)/2, left, right), maximum(tree, node*2+1, (start+end)/2+1, end, left, right));
}
void update(vector<int> &tree, int node, int start, int end, int i, int value) {
    if (i > end || i < start) {
        return;
    }
    // if tree[node] > value, let it be (don't update it as value)
    tree[node] = max(tree[node], value); // ??? -> Ok
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, i, value);
        update(tree, node*2+1, (start+end)/2+1, end, i, value);
    }
}
const int MAX = 1000000;
int main() {
    int n;
    scanf("%d", &n);
    int h = (int)ceil(log2(MAX));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    int ans = 0;
    for (int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        // max [1, num-1]
        //tree[i]: 0 0 0 0 0  // LIS length
        //             2     A[2]=3 >[1,2] max:1(len)+3 > 2 (len)
        int cur = maximum(tree, 1, 1, MAX, 1, num-1);
        if (ans < cur + 1) {
            ans = cur + 1;
        }
        update(tree, 1, 1, MAX, num, cur+1);
    }
    printf("%d\n", ans);
    return 0;
}