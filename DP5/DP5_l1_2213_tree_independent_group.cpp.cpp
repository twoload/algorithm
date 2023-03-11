#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// tree : n node <= 10,000
// brute force
//   2^10,000 : too big!!!
// DP
// D[n] : max value until n node
//        uncolor adjacent ones if D[n] is colored

// teacher : graph's independent set = can't solve
//           tree's independent set = can solve with DP

// if one vertex is included in an indepedent set,
//    it's children should not be included in the set.

//       1*
//      /
//     2
//    / \
//   3*  6
//  /     \
// 4       7*
//5*

// d[v][0] : max value when virtex v isn't included in the independent set
// d[v][1] : max value when virtex v is included in the independent set
//   v = root 's subtree

//      v
//   /  |  \
// o,x o,x o,x

// wi = v's children
// d[v][0] = sum (max (D[wi][0], D[wi][1]))
// d[v][1] = sum (D[wi][0]) + A[v]
// v= root, sub tree's independent set

// w[i] : vertex i

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n; // <= 10,000
int w[10001];
int d[10001][2];
vector<int> a[10001];
vector<int> ans;
void go(int now, int parent){
    for (int i=0; i<(int)a[now].size(); i++) {
        if (parent == a[now][i]) {
            continue;
        }
        go(a[now][i],now); // to children : recursive
    }
    d[now][1] = w[now]; // include
    d[now][0] = 0;      // no include
    for (int i=0; i<(int)a[now].size(); i++) {
        if (parent == a[now][i]) {
            continue;
        }
        d[now][1] += d[a[now][i]][0]; // children: no include
        d[now][0] += max(d[a[now][i]][0],d[a[now][i]][1]); // children : max(include, no include)
    }
}
// x: vertex, y: include O/X, 
void gogo(int x,int y, int parent){
   if (y==0) { 
       // x: no include X
       for (int i=0; i<(int)a[x].size(); i++) {
           if (parent == a[x][i]) {
               continue;
           }
           // a[x][i] : children
           if (d[a[x][i]][0] < d[a[x][i]][1]) { // already calculated in go(x,y)
               gogo(a[x][i],1,x);
           }
           else {
               gogo(a[x][i],0,x);
           }
       }
   } else if (y == 1) {
        // x: include O
        ans.push_back(x); // added
        for (int i=0; i<(int)a[x].size(); i++) {
            if (parent == a[x][i]) {
                continue;
            }
            gogo(a[x][i],0,x);
        }
   }
}
int main() {
    scanf("%d\n",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d ",&w[i]); //10,30,40,10,20,20,70
    }
    for (int i=0; i<n-1; i++) {
        int t1,t2;
        scanf("%d %d\n",&t1,&t2); //a: tree 
        a[t1].push_back(t2);
        a[t2].push_back(t1);
    }
    go(1,0); // max : 1=root, 0=parent of root
    printf("%d\n",max(d[1][0],d[1][1]));
    if (d[1][0] < d[1][1]) {
        gogo(1,1,0); // 1: include
    } else {
        gogo(1,0,0); // 0: no include
    }
    sort(ans.begin(),ans.end());
    for (int i=0; i<(int)ans.size(); i++) {
        printf("%d ",ans[i]);
    }
    return 0;
}
