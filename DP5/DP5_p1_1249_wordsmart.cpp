#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n ( 1 <= n <= 1'000'000'000)
// k ( 1 <= k <= 26)

// d[n][k] : num of strings at len n, penlindrome's len k
// = d[n-2][k-2]

//   B+A+B : left, right added at the same time

// teacher
// f[l][c] : num of strings at len:l, max c char
// g[l] : num of penlindrome at len:l, max k char
// s = g[1]+g[2]+,,,+g[n] ***

// ////\\\\ : even  (1/2 -> we can make penlindrome)
// <--> l/2
// ///()\\\ : odd    
// <--> (l-1)/2+1 = l/2+1

// even, len: l, penlindrome: l/2
// g[l] = f[l/2][k] 
// odd, len: l, penlindrome: l/2+1
// g[l] = f[l/2+1][k]

// f[l][c] = ff[l][1]+ff[l][2]+...+ff[l][c]
// <- ff[l][c]: num of strings at len l, num of char: c
// ff[l][c]
// 1. l-th char : existed before
//    ff[l-1][c]*c
// 2. l-th char : new one
//    ff[l-1][c-1]*(26-(c-1)) = ff[l-1][c-1]*(27-c)
// n<=1'000'000'000 : time is too big!!!

// v[l]= [ff[l][0], ff[l][1], ... ff[l][26]]
// v[l]= a * v[l-1]
//    [0 26 0 0 ... 0 0 0]
//    [0 1 25 0 ... 0 0 0]
//    [0 0 2 24 ... 0 0 0]
// a =[0 0 0  3 ... 0 0 0] 
//    [....]
//    [....]
//    [0 0 0 0 ... 24 2 0]
//    [0 0 0 0 ... 0 25 1]
//    [0 0 0 0 ... 0 0 26]
// ff[l][c] = c*ff[l-1][c] + (27-c)*ff[l-1][c-1]
// a[c-1][c] = 27-c
// a[c][c] = c

// v[l]= v[l-1]*a
// v[l]= (v[l-2]*a)*a
// ...
// v[l]= v[0]*A^L
// v[0]= [1 0 ... 0]
// A^L = O(27^3logL)  (matrix multiply:27^3 * logL)

// s =
// even n
// -> 2*(f[1][k]+f[2][k]+... f[n/2][k])
// odd n
// -> 2*(f[1][k]+f[2][k]+... f[n/2-1][k]+f[n/2+1][k])
// f[l][k] = sum of 1~k+1 of v[l]

// even n
// v[1]+v[2]+...v[n/2]
//   =v[0]*(A^1+A^2+...+A^(N/2))
// odd n
// v[1]+v[2]+...v[(n-1)/2]+v[(n+1)/2]
// = v[0]*(A^1+A^2+...+A^((N-1)/2))+v[0]*A^((n+1)/2)
// A^k = M^3logK = 27^3*log(billion) : too big
// <- sum of square of matrix fast!!!
// s = a^1+a^2+a^3+...a^b
// a^(2q) = (a^q)^2
// a^(2q+1) = a^2q * a
// a^1+a^2+...+a^2q = (E+a^q)*(a^1+a^2+...+a^q)
// a^1+a^2+...+a^(2q+1) = (a^1+a^2+...a^2q)+a^(2q+1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1234567891LL;
// matrix multiply
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
matrix operator + (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            c[i][j] %= mod;
        }
    }
    return c;
}
// E : identity = eigen vector
matrix init(int n) {
    matrix a(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        a[i][i] = 1;
    }
    return a;
}
// ref: BOJ:13246 sum of matrix fast!!!
// a^k 
// a^(2q)   = (a^q)^2
//    a^k   = (a^2)^(k/2)
// a^(2q+1) = (a^(2q))*a
//    a^k   = (a^(k-1))*a
//                ---
matrix matrix_pow(matrix a, long long k) {
    if (k == 0) {
        return init(a.size());
    } else if (k%2 == 0) {
        return matrix_pow(a*a, k/2);
    } else {
        return a * matrix_pow(a, k-1);
    }
}
// ref: BOJ:13246 sum of matrix fast!!!
// a^1 + a^2 + ... + a^k
// k = 0 -> (0, 0)
matrix matrix_sum(matrix a, long long k) {
    int n = a.size();
    if (k == 0) {
        matrix ans(n, vector<long long>(n));
        return ans;
    } else if (k%2 == 0) {
        // (E+A^(k/2))*(A1+...+A^(k/2))
        return (init(n) + matrix_pow(a, k/2)) * matrix_sum(a, k/2);
    } else {
        // A^1+...         + A^(k-1) + A^k
        // <---matrix_sum(a,k-1)-->    matrix_pow(a,k)
        return matrix_sum(a, k-1) + matrix_pow(a, k);
    }
}
void print(const matrix &a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
const int numOfchar=26; // 3
int main() {
    long long n, k;
    cin >> n >> k;
    matrix a(numOfchar+1, vector<long long>(numOfchar+1));
    // ff[l][c] = c*ff[l-1][c] + (27-c)*ff[l-1][c-1]
    // a[c-1][c] = 27-c
    // a[c][c] = c
    for (int i=0; i<numOfchar+1; i++) {
        a[i][i] = i;
        if (i+1 < numOfchar+1) {
            a[i][i+1] = numOfchar-i;
        }
    }
    //for(int i=0; i<a.size(); i++) {
    //    for(int j=0; j<a.size(); j++) {
    //        printf("%lld ", a[i][j]);
    //    }
    //    printf("\n");
    //}
    //printf("\n");
    // even n
    // v[1]+v[2]+...v[n/2]
    //   =v[0]*(A^1+A^2+...+A^(N/2))
    // odd n
    // v[1]+v[2]+...v[(n-1)/2]+v[(n+1)/2]
    // = v[0]*(A^1+A^2+...+A^((N-1)/2))+v[0]*A^((n+1)/2)
    matrix d;
    if (n % 2 == 0) {
        d = matrix_sum(a, n/2);
    } else {
        d = matrix_sum(a, (n-1)/2); // (n+1)/2 later
    }
    //for(int i=0; i<d.size(); i++) {
    //    for(int j=0; j<d.size(); j++) {
    //        printf("%lld ", d[i][j]);
    //    }
    //    printf("\n");
    //}
    long long ans = 0;
    // v[l]=v[l-1]*a
    // v[l]=v[0]*a^l
    // v[l]=[ff[l][0], ff[l][1], ff[l][2], ... ff[l][26]]
    // 
    // 2*(V[1]+V[2]+...+V[n/2]), n=even  
    // = 2*( V[0]*(a^1+a^2+...a^(n/2) )  
    // =           <----------------> d = matrix_sum(a, n/2) 
    for (int i=0; i<=k; i++) {
        ans = (ans + d[0][i]) % mod; // ?
        //printf("ans=%lld, %lld\n", ans, d[0][i]);
    }
    //s = g[1]+g[2]+g[3]+g[4], n=4
    //  = f[1][k] + f[1][k] + f[2][k] + f[2][k]
    //  = 2* (f[1][k] + f[n/2][k]), n/2=2
    // so,
    // n=even, 2x(f[1][k]+f[2][k] + ...+ f[n/2][k])
    // n=odd, 2x(f[1][k]+f[2][k] + ...+ f[n/2-1][k]) + f[n/2+1][k]
    ans = ans * 2LL;    
    ans %= mod;
    if (n % 2 == 1) {
        d = matrix_pow(a, (n+1)/2); // (n+1)/2 here for odd
        //printf("\n\n");       
        //for(int i=0; i<d.size(); i++) {
        //    for(int j=0; j<d.size(); j++) {
        //        printf("%lld ", d[i][j]);
        //    }
        //    printf("\n");
        //}
        for (int i=0; i<=k; i++) {
            ans = (ans + d[0][i]) % mod;
            //printf("ans2=%lld, %lld\n", ans, d[0][i]);
        }
    }
    cout << ans << '\n';
    return 0;
}
