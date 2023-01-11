#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// 1<= n <= 300'000
// 0<= h <= 1'000'000
// 1<= m <= 300'000

// simple
// m * n (update:O(1)*arrange:O(n))

// order : find order via tree
//   arrange x
//   h : tree size -> big -> ?

// x[h] : score when shooting at height h
//      = x1[h]+x2[h]+x3[h]+...+xn[h] // 300'000
//      = sum (xi[h]), 1<=i<=n
// xi[h] : score at height h in i-th column
// yi[h] = xi[h]-xi[h-1]
// xi[h] = sum(yi[j]), 1<=j<=h
// ex. x2[3]=y2[1]+y2[2]+y2[3]
//          =(x2[1]-x2[0])+(x2[2]-x2[1])+(x2[3]-x2[2])
//          = x2[3]-x2[0] = x2[3]-0 = x2[3]
// Y[h] = sum(Yi[j]) (1<=j<=h) : effective!
// Yi[h] change point
//       1, B[i]+1, B[i]+G[i]+1, B[i]+G[i]+W[i]+1
//        <->     <->          <->      
//         0       0            0 (no change)
// X[h]=sum(Xi[h]) (1<=i<=N) = sum(sum(yi[j])) (1<=i<=N, 1<=j<=h)
//     =sum(Y[j]) (1<=j<=h) = X[h-1] + Y[h]
// <- yi[h] = xi[h]-xi[h-1]
// X[h] = X[h-1] + Y[h]

// 0-(1)-B-(1)-G-(3)-W
// B-(4)-W
// 0-(2)-G
// 0-(5)-W

// i   : 1 2 3 4 5 6
//B[i] : 2 1 2 0 3 1
//G[i] : 1 2 2 2 2 0
//W[i] : 1 0 1 2 0 3

// h   : 1  2  3  4  5    //h    : 1  2  3  4  5  6
//X1[h]: 1  1  2  5       //y1[h]: 1  0  1  3 -5  0
//x2[h]: 1  2  2          //y2[h]: 1  1  0 -2  0  0
//x3[h]: 1  1  2  2  5    //y3[h]: 1  0  1  0  3 -5
//x4[h]: 2  2  5  5       //y4[h]: 2  0  3  0 -5  0
//x5[h]: 1  1  1  2  2    //y5[h]: 1  0  0  1  0 -2
//x6[h]: 1  5  5  5       //y6[h]: 1  4  0  0 -5  0
//X[h] : 7 12 17 19  7    //Y[h] : 7  5  5  2 -12 -7

// height => tree[i] : 1 (exist), 0 (no exist)
// key point : height : height change point : 4 
//    -> big number -> small change possible

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void init(vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    init(tree, node*2, start, (start+end)/2);
    init(tree, node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int kth(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end) {
        tree[node] = 0;
        return start;
    }
    int ans = 0;
    if (k <= tree[node*2]) {
        ans = kth(tree, node*2, start, (start+end)/2, k);
    } else {
        ans = kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
    }
    tree[node] = tree[node*2] + tree[node*2+1];
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(n), g(n), w(n); //black, gray, white : order is fixed
    for (int i=0; i<n; i++) { // in direction of columns
        cin >> b[i];
    }
    for (int i=0; i<n; i++) {
        cin >> g[i];
    }
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }
    int height = 0;  //ex. height = 6
    for (int i=0; i<n; i++) {
        if (height < b[i]+g[i]+w[i]+1) {
            height = b[i]+g[i]+w[i]+1;
        }
    }
    vector<int> y(height+1);
    // Y[h] = sum(Yi[j]) (1<=j<=h) : effective!
    // Yi[h] change point
    //       1, B[i]+1, B[i]+G[i]+1, B[i]+G[i]+W[i]+1
    //        <->     <->          <->      
    //         0       0            0 (no change)
    // X[h]=sum(Xi[h]) (1<=i<=N) = sum(sum(yi[j])) (1<=i<=N, 1<=j<=h)
    y[0] = 0;
    y[1] = n; // 0-(1)-B : : diff
    for (int i=0; i<n; i++) {
        y[b[i]+1] += 1; // B-(1)-G : diff
        y[b[i]+g[i]+1] += 3; // G-(3)-W : diff
        y[b[i]+g[i]+w[i]+1] -= 5; // W-(-5)-0 : diff
    }
    // Y[h] : sum of all column

    // X[h] = X[h-1] + Y[h]
    // X[h] : score when shooting at height h
    //      = x1[h]+x2[h]+x3[h]+...+xn[h] // 300'000
    //      = sum (xi[h]), 1<=i<=n
    vector<int> x(height+1);
    for (int i=1; i<=height; i++) { 
        x[i] = x[i-1] + y[i];
    }

    // segment tree for height 
    //   not to update array value every time
    int h = (int)ceil(log2(height));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    init(tree, 1, 1, height); // init as 1 (1:exist, 0: no exist)
    int m;
    cin >> m;
    while (m--) {
        int h;
        cin >> h;
        int k = kth(tree, 1, 1, height, h); // find h: height -> update 0 (shot) 
        cout << x[k] << '\n'; // answer
    }
    return 0;
}