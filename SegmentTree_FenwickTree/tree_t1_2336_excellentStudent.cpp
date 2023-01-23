#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

//grade: 1 2 3 4 5 6 7 8 9 10
// A:    2 5 3 8 10 7 1 6 9 4
// B:    1 2 3 4 5 6 7 8 9 10 
// C:    3 8 7 10 5 4 1 2 6 9

// two students : i, j
// A[i] < A[j] : tree's location
// B[i] < B[j] : order to put
// C[i] < C[j] : tree's value
// all i, j -> i is a excellent student.

// sort by B grade
// 7 1 7
// 1 2 8
// 3 3 1
// 10 4 6
// 2 5 5
// 8 6 9
// 6 7 3
// 4 8 2
// 9 9 10
// 5 10 4

// tree[i] : grade in test C of a student who has i grade in test A
// tree[1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
//     11  11   11  11  11  11  11  11  11  11

// turn1: 7 1 7 (excellent)
// B : already updated
// A : [1,6] : students who has 1~6 grade in test A (higher than 7)
// C : 7 < minimum tree[1,6]=11
// update the tree : tree[7]=7
// tree[1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
//     11  11   11  11  11  11  7  11  11  11

// turn2: 1 2 8 (excellent)
// B : already considered (order to put)
// A : [1,0]
// C : 8 < 11
// update the tree : tree[1]=8
// tree[1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
//      8  11   11  11  11  11  7  11  11  11

// turn3: 3 3 1 (excellent)
// B : already considered (order to put)
// A : [1,2]
// C : 1 < 8
// update the tree : tree[3]=1
// tree[1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
//      8  11   1  11  11  11   7   11  11  11

// turn4: 10 4 6 (x)
// B : already considered (order to put)
// A : [1, 9]
// C : 6 < 1
// update the tree : tree[10]=6
// tree[1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
//      8  11   1  11  11  11   7   11  11  6

// turn5: 2 5 5 (excellent)
// B : already considered (order to put)
// A : [1,1]
// C : 5 < 8
// update the tree : tree[2]=5
// tree[1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
//      8   5   1  11  11   11  7  11   11  6

// ...

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 500001;
struct Exam {
    int first, second, third;
};
void init(vector<int> &tree, int node, int start, int end) {
    // all tree[node] = inf
    tree[node] = inf; // max n=500'000 + 1
    if (start != end) {
        init(tree, node*2, start, (start+end)/2);
        init(tree, node*2+1, (start+end)/2+1, end);
    }
}
int minimum(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return inf;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return min(minimum(tree, node*2, start, (start+end)/2, left, right), minimum(tree, node*2+1, (start+end)/2+1, end, left, right));
}
void update(vector<int> &tree, int node, int start, int end, int i, int value) {
    if (i > end || i < start) {
        return;
    }
    // update minimum
    tree[node] = min(tree[node], value);
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, i, value);
        update(tree, node*2+1, (start+end)/2+1, end, i, value);
    }
}
// sort by B grade (ascending order)
bool cmp (const Exam &u, const Exam &v) {
    return u.second < v.second;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<Exam> a(n+1);
    for (int i=1; i<=n; i++) {
        int t;
        scanf("%d",&t);
        a[t].first = i; //i:grade, t:student number
    }
    for (int i=1; i<=n; i++) {
        int t;
        scanf("%d",&t);
        a[t].second = i;
    }
    for (int i=1; i<=n; i++) {
        int t;
        scanf("%d",&t);
        a[t].third = i;
    }
    sort(a.begin(),a.end(),cmp); // soft by b grade 
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1)) - 1;
    vector<int> tree(tree_size);
    init(tree, 1, 1, n);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        //[1,a[i].first-1] but a[i].first is also okay. 
        // because a[i].first = inf at first
        int best = minimum(tree, 1, 1, n, 1, a[i].first); 
        if (best > a[i].third) {
            ans += 1;
        }
        update(tree, 1, 1, n, a[i].first, a[i].third);
    }
    printf("%d\n",ans);
    return 0;
}