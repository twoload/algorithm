#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// (1,1) -> (n,m) : visiting k num places (c)
// n, m : 1~50
// c : 0~50 (visit places)
//     visit in increasing order

// brute force
//   ex. visit 1 : (1,1) -> (i,j) -> (n,m)
//   a = num of cases (1,1) -> (i,j)
//   b = num of cases (i,j) -> (n,m)
//   total = a*b
//       (1,1)->(i,j) : direction 2 (right, down): 2^(min(i,j))
//       O(nC1)
//   ex. visit 2 : (1,1) -> (i,j) -> (i2,j2) -> (n,m)
//       ... 
//       O(nC2)

// DP
// d[i][j][k] : path nums when cur pos (i,j), visited k num
//     k-1 visit O : d[]
//     k-1 visit x

//==========================================================

// (r,c) -> (nr, nc)
//  len  -> len+1
//  k    -> k or l  ,where  k : last visited place num

// d[i][j][k][len] = num of ways which (1,1) -> (i,j) after visiting len places
//                   last visited place num : k

// 1. (i,j) : game place (k) len
//    (i-1,j) -> (i,j)
//    (i,j-1) -> (i,j)
//    len-1
//    last visited place num ??? 0, 1, ... k-1
//    d[i-1][j][0][len-1]+d[i][j-1][0][len-1]+....
// <-> sigma(d[i-1][j][l][len-1]) + sigma(d[i][j-1][l][len-1])
//     , 0<= l < k
// 2. (i,j) : not game place
//    (i-1,j)
//    (i,j-1)
//    len
//    k
// <-> d[i-1][j][k][len] + d[i][j-1][k][len]

//============================================================
// another ref: https://blog.naver.com/PostView.nhn?blogId=jhc9639&logNo=221808566833&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
//              top-down : it seems easier


#include <iostream>
#include <cstring>
using namespace std;
int position[51][51];
int d[51][51][51][51];
int ans[51];
const int mod = 1000007;
int main() {
    int r, c, n;
    cin >> r >> c >> n;
    memset(position, -1, sizeof(position));
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        position[x][y] = i; //game place >= 0 (1,1 -> n,m)
    }
    // 0,0 -> 1,0 : cases num 1
    // we need to get d[1][1][0][0]
    //    d[1][1][0][0] can be got from d[1][0][0][0], d[0][1][0][0]
    //    either d[1][0][0][0] or d[0][1][0][0] need to be 1
    d[0][1][0][0] = 1; // init value : cases num : 1
    //d[1][0][0][0] = 1;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (position[i][j] == -1) { // not game place
                // d[i][j][k][len], set init value
                d[i][j][0][0] += d[i-1][j][0][0] + d[i][j-1][0][0];
                d[i][j][0][0] %= mod;
            }
            for (int l=1; l<=n; l++) {
                if (position[i][j] == -1) { // not game place (case2)
                    for (int k=0; k<n; k++) {
                        // k, l : no change
                        d[i][j][k][l] += d[i-1][j][k][l] + d[i][j-1][k][l];
                        d[i][j][k][l] %= mod;
                    }
                } else { // game place (case1)
                    int m = position[i][j]; // order
                    if (l == 1) { // first visit game place, set init value
                        // prev (k=0,l=0) -> cur
                        d[i][j][m][l] += d[i-1][j][0][0] + d[i][j-1][0][0];
                        d[i][j][m][l] %= mod;
                    } else { // case1 
// <-> sigma(d[i-1][j][k][len-1]) + sigma(d[i][j-1][k][len-1])
//     , 0<= k < m
                        for (int k=0; k<m; k++) {
                            d[i][j][m][l] += d[i-1][j][k][l-1] + d[i][j-1][k][l-1];
                            d[i][j][m][l] %= mod;
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<=n; i++) {
        for (int k=0; k<max(n,1); k++) {
            ans[i] += d[r][c][k][i];
            ans[i] %= mod;
        }
        printf("%d ", ans[i]);
    }
    return 0;
}


