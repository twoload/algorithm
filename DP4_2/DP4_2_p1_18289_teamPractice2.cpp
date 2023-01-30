#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n (1<= n <=10^5)
// brute force
//   3^n

// dp
// d[n] : num of cases to solve the problem (0~n)
// d[n][a] : a = (num which A solve the problem % k)
// d[n][a][c] : c = 0, 1
// d[n][a][b][c] : b = 0, 1 (b:0->1, 1->0 at n+1)
//   n -> n+1
//   a -> O:(a+1%k), X:a  , 0<=k<=10
//   b(0) -> 1
//   b(1) -> 0
//   c -> O:1, X:c
// d[0][0][0][0] -> d[n-1][a'][b'][c']
//                   a' % k == 0
//                   c' >= 1
//                   b' is handled during process
// O(n*k*2*2)
// n : 10^5 -> 10^18
//     matrix
// d[n] = A*d[n-1] , d[n][a][b][c]...???
// 4 dim -> 1 dim

// ex. 2 dim -> 1 dim
// NM : a[i][j] -> b[i*M + j] 
// ex. 3 dim -> 1 dim
// NML : a[i][j][k] -> b[i*ML + jL + k]
// ex. 4 dim -> 1 dim
// d[n][a][b][c] = d2[n][state_map[a][b][c]]


#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;
using matrix = vector<vector<long long>>;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
int state_map[10][2][2]; //a,b,c : 3 dim -> 1dim
void print(const char* header, const matrix& a)
{
    printf("%s: \n", header);
    int n = a.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    long long n;
    int k;
    cin >> n >> k;
    int kk = max(k, 1); // in case of k == 0
    int state_num = 0;
    for (int a=0; a<kk; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                state_map[a][b][c] = state_num++; //a*M*L + b*L + c
            }
        }
    }
    int size = kk * 2 * 2;
    matrix ans(size, vector<long long>(size)); 
    matrix mat(size, vector<long long>(size));
    for (int i=0; i<size; i++) {
        ans[i][i] = 1; // identity matrix
    }
    // 2 1
    // n=2, k=1
    // mat[[0][0][0]=0][A:[0][0][0]=0] = mat[0][0] = 1 (0,0,0) (+a) > (0,0,0) [0][0]
    // mat[[0][0][0]=0][B:[0][1][0]=2] = mat[0][2] = 1 (0,0,0) (+b) > (0,1,0) [0][2]
    // mat[[0][0][0]=0][C:[0][0][1]=1] = mat[0][1] = 1 (0,0,0) (+c) > (0,0,1) [0][1]

    // mat[[0][0][1]=1][A:[0][0][1]=1] = mat[1][1] = 1 (0,0,1) (+a) > (0,0,1) [1][1]
    // mat[[0][0][1]=1][B:[0][1][1]=3] = mat[1][3] = 1 (0,0,1) (+b) > (0,1,1) [1][3]
    // mat[[0][0][1]=1][C:[0][0][1]=1] = mat[1][1] = 1 (0,0,1) (+c) > (0,0,1) [1][1]

    // mat[[0][1][0]=2][A:[0][0][0]=0] = mat[2][0] = 1 (0,1,0) (+a) > (0,0,0) [2][0]
    // mat[[0][1][0]=2][B:           ] = X 
    // mat[[0][1][0]=2][C:[0][0][1]=1] = mat[2][1] = 1 (0,1,0) (+c) > (0,0,1) [2][1]

    // mat[[0][1][1]=3][A:[0][0][1]=1] = mat[3][1] = 1 (0,1,1) (+a) > (0,0,1) [3][1] 
    // mat[[0][1][1]=3][B:           ] = X
    // mat[[0][1][1]=3][C:[0][0][1]=1] = mat[3][1] = 1 (0,1,1) (+c) > (0,0,1) [3][1]
  
    // (1 1 1 0)  
    // (0 2 0 1)
    // (1 1 0 0)
    // (0 2 0 0)
    // state: 0->0 = 1   ,  0->?->0 = 2 (mat^2)
    // state: 0->1 = 1   ,  0->?->1 = 4 
    // state: 0->2 = 1   ,  0->?->2 = 1 
    // state: 1->1 = 2   ,  0->?->3 = 1 
    // state: 1->3 = 1   ,  ... 
    // state: 2->0 = 1   ,  ... 
    // state: 2->1 = 1   ,  ... 
    // state: 3->1 = 2   ,  ... 
    // d[n][a][b][c] = d2[n][state_map[a][b][c]]
    // ans = (a%k==0, c>=1)
    // state: 0->...->(0,0,1) = ans[0][1] : state 0->...->1
    //                             --- ---
    //                             start end
    //        0->...->(0,1,1) = ans[0][3] : state 0->...->3
    // ans = ans[0][1] + ans[0][3]
    for (int a=0; a<kk; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                int state = state_map[a][b][c]; // 3dim -> 1dim
                //printf("a:%d, b:%d, c:%d -> state:%d\n", a, b, c, state);
                if (k > 0) {
                    mat[state][state_map[(a+1)%k][0][c]] += 1; // A solve
                    //printf("mat[%d][%d] = %d (+a)\n", state, state_map[(a+1)%k][0][c], mat[state][state_map[(a+1)%k][0][c]]);
                    // state -> next_state
                }
                if (b == 0) {
                    mat[state][state_map[a][1][c]] += 1; // B solve
                    //printf("mat[%d][%d] = %d (+b)\n", state, state_map[a][1][c], mat[state][state_map[a][1][c]]);
                    // state -> next_state
                } 
                mat[state][state_map[a][0][1]] += 1; // C solve
                // state -> next_state
                //printf("mat[%d][%d] = %d (+c)\n", state, state_map[a][0][1], mat[state][state_map[a][0][1]]);
            }
        }
    }
    //print("mat", mat);
    while (n > 0) { // power of matrix 
        if (n % 2 == 1) {
            ans = ans * mat;
            if (n == 1)
                break;
        }
        mat = mat * mat;
        n /= 2;
    }
    //print("ans", ans);
    long long sum = ans[0][state_map[0][0][1]] + ans[0][state_map[0][1][1]];
    //printf("sum = %lld (ans[0][%d] + ans[0][%d])\n", sum, state_map[0][0][1], state_map[0][1][1]);
    sum %= mod;
    cout << sum << '\n';
    return 0;
}
