#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 4
// 1+1+1+1
// 1+1+2
// 1+2+1
// 1+3
// 2+1+1
// 2+2
// 3+1

//d[n] : num of way which n is composed of 1,2,3
// 1+d[n-1]
// 1+d[n-2]
// 1+d[n-3]
// ???

// brute force : 3^7

// teacher
// d[n] = d[n-1] + d[n-2] + d[n-3]
// 1 + (n-1) = d[n-1] = num of sum starting 1
// 2 + (n-2) = d[n-2] = num of sum starting 2
// 3 + (n-3) = d[n-3] = num of sum starting 3

// starting 1 d[n-1]
// starting 2 d[n-2]
// starting 3 d[n-3]


#include <iostream>
#include <vector>
using namespace std;
long long d[11]; // n<11
vector<int> ans;
void print(int n, long long k) {
    if (n == 0) return;
    if (d[n-1] > k) {               // k < d[n-1]
        ans.push_back(1);
        print(n-1, k);
    } else if (d[n-2] > k-d[n-1]) { // k < d[n-1]+d[n-2]
        ans.push_back(2);
        print(n-2, k-d[n-1]);// k-d[n-1]
    } else {
        ans.push_back(3);
        print(n-3, k-d[n-1]-d[n-2]); //k-d[n-1]-d[n-2]
    }
}
int main() {
    d[0] = 1;
    d[1] = 1;
    d[2] = 2; //1+1, 2
    // d[3] = 4 (1+1+1, 1+2, 2+1, 3)
    for (int i=3; i<=10; i++) { // calcaulate in advance
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    int n;
    long long k;
    cin >> n >> k;
    if (d[n] < k) { // impossible
        cout << -1 << '\n';
    } else {
        print(n, k-1); // 0,1,2,...,k-1
        int m = ans.size();
        for (int i=0; i<m; i++) {
            cout << ans[i];
            if (i != m-1) {
                cout << "+";
            }
        }
        cout << '\n';
    }
    return 0;
}
