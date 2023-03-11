#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// d[n][m] : num of sequences when n(len), m(sum)
// = d[n-1][m-1]
// = d[n-1][m-2]
// = d[n-1][m-3]
// =
// = d[n-1][m-...]

// teacher
// d[n][m] : num of sequences when n(len), m(sum)
// d[n][m][l] : last number is l
// = sum (d[n-1][m-l][k]) (k<=l)

//        k
// A1,...An-1,An(=L)
// \----------/ sum = M
// \------/
// len=n-1, um = M-An(=L)
// last number: k

#include <iostream>
using namespace std;
long long d[11][221][221]; // len, sum, last
int n,m;
// cnt: order = 0,1,2,.... (s-1)
void go(int len, int sum, int last, long long cnt) {
    //printf("go(len:%d, sum:%d, last:%d, cnt:%d)\n", len, sum, last, cnt);
    if (len <= 0) {
        return;
    }
    long long acc = 0;
    for (int i=last; i<=m; i++) {
        if (cnt < acc+d[len][sum][i]) {
            //printf("%d < %d(%d+%d) (cnt<acc+d[%d][%d][%d])\n",
            //    cnt, acc+d[len][sum][i], acc, d[len][sum][i], len,sum,i);
            cout << i << ' ';
            go(len-1, sum-i, i, cnt-acc);
            break;
        }
        acc += d[len][sum][i];
        //printf("acc:%d (d[%d][%d][%d]=%d)\n", acc, len,sum,i,d[len][sum][i]);
        // d[n][m] : num of sequences when n(len), m(sum)
        // d[n][m][l] : last number is l
    }
}
int main() {
    long long s;
    cin >> n >> m >> s;
    for (int i=1; i<=m; i++) {
        d[1][i][i] = 1LL; //init (j==k) and (i==1)
    }
    for (int i=2; i<=n; i++) { //from i=2 because i==1, already d[1][i][i]=1LL
        for (int j=1; j<=m; j++) {
            for (int k=1; k<=j; k++) {
                for (int l=k; l<=j; l++) { 
                    if (j-k >= 1) { // skip:already j==k <- d[1][i][i] =1LL
                        // AN>..>A3>A2>A1 (upside down = it's ok)
                        // AN,...A3,A2(=l),A1(=k)
                        // \-------------/ sum = j , last=k
                        // \------/ sum = j-k, last=l
                        //printf("d[%d][%d][%d] = %d += (d[%d][%d][%d]=%d)\n",
                        //    i,j,k,d[i][j][k]+d[i-1][j-k][l],i-1,j-k,l,d[i-1][j-k][l]);
                        d[i][j][k] += d[i-1][j-k][l];
                    }
                }
            }
        }
    }
    go(n,m,1,s-1);
    cout << '\n';
    return 0;
}
#if 0
d[4][9][1] = 5
  d[3][8][1] = 3
    d[2][7][1] = 1
      d[1][6][6] = 1
    d[2][7][2] = 1
      d[1][5][5] = 1
    d[2][7][3] = 1
      d[1][4][4] = 1
  d[3][8][2] = 2
    d[2][6][2] = 1
      d[1][4][4] = 1
    d[2][6][3] = 1
      d[1][3][3] = 1
  d[3][8][3] = 0
#endif