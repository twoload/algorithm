#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// C44 : num of numbers (starting 4, ending 4)
// C47 : num of numbers (starting 4, ending 7)
// C74 : num of numbers (starting 7, ending 4)
// C77 : num of numbers (starting 7, ending 7)

// d44[n] : num of sequences len:n (starting 4, ending 4)
// d47[n] : num of sequences len:n (starting 4, ending 7)
// d74[n] : num of sequences len:n (starting 7, ending 4)
// d77[n] : num of sequences len:n (starting 7, ending 7)

// d44[n] = d44[n-1]*C44 + d47[n-1]*C74 = C44*d44[n-1] + C74*d47[n-1] 
// d47[n] = d47[n-1]*C77 + d44[n-1]*C47 = C77*d47[n-1] + C47*d44[n-1]
// d74[n] = d74[n-1]*C44 + d77[n-1]*C74 = C44*d74[n-1] + C74*d77[n-1]
// d77[n] = d77[n-1]*C77 + d74[n-1]*C47 = C77*d77[n-1] + C47*d74[n-1]

// but len of sequences : 1'000'000'000 = too big!!!
// A = (C44 C47)
//     (C74 C77)
// A^L -> sum of all numbers
// d44[n] = (c44 c74)* d44[n-1]  
// d47[n] = (C47 C77)  d47[n-1]
// d74[n] = (c44 c74)* d74[n-1]  
// d77[n] = (C47 C77)  d77[n-1]

// (d44[n] d74[n]) = (c44 c74) * (d44[n-1] d74[n-1])
// (d47[n] d77[n])   (c47 C77) * (d47[n-1] d77[n-1])

// (d44[1] d74[1]) = (c44 c74) * (d44[0] d74[0])
// (d47[1] d77[1])   (c47 C77) * (d47[0] d77[0])

// O(2^3logL) = O(logL)


#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1234567891LL;
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
// check if all numbers are 4, 7
bool check(int x) {
    if (x == 0) return true;
    if (x%10 == 4 || x%10 == 7) {
        return check(x/10);
    } else {
        return false;
    }
}
int main() {
    int n, l;
    cin >> n >> l;
    set<int> s;
    matrix ans = {{1, 0}, {0, 1}}; // identity matrix
    matrix a = {{0, 0}, {0, 0}};
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (s.count(x)) continue; // not allow duplicate
        s.insert(x);
        if (check(x)) { // 4, 7
            string temp = to_string(x);
            if (temp[0] == '4') {
                if (x%10 == 4) {
                    a[0][0] += 1; //c44
                } else { 
                    a[0][1] += 1; //c47
                }
            } else {
                if (x%10 == 4) {
                    a[1][0] += 1; //c74
                } else {
                    a[1][1] += 1; //c77
                }
            }
        }
    }
    while (l > 0) { // power of matrix
        if (l % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        l /= 2;
    }
    //
    // ex1
    // 3 3
    // 447, 74, 47
    //
    // d44[1] = C44 = 0 
    // d47[1] = c47 = 2
    // d74[1] = c74 = 1
    // d77[1] = c77 = 0
    //
    // (d44[2] d74[2]) = (c44 c74) * (d44[1] d74[1])
    // (d47[2] d77[2])   (c47 c77)   (d47[1] d77[1])
    //
    // (d44[3] d74[3]) = (c44 c74)^2 * (c44 c74) = (c44 c74)^3
    // (d47[3] d77[3])   (c47 c77)     (c47 c77)   (c47 c77)
    //
    // ans = d44[3] + d47[3] + d74[3] + d77[3]
    cout << (ans[0][0] + ans[0][1] + ans[1][0] + ans[1][1]) % mod << '\n';
    return 0;
}