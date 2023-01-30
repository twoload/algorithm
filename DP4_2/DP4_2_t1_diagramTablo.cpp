#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// num of row: k (1<=k<=7)
// l1,l2,l3,...lk : num of row's box
// N : box's num (k<= N <=7)

// brute force
//  order : 7
// 1-th row
// 2-th row
// 3-th row
// ...
// * * * * * * *
// * * * * * * *
// ...
// * * * * * * *
// 7x7 matrix
// NxN matrix
// n-1 row = state
// d[n][state] : case num at n-th row, s state.
//         = sum(d[n-1][pstate]), all pstate

// teacher
// integers should be bigger than upper integers
// -> there is no duplicate numbers in one column
// 2^7 bitmask -> column 
// d[c][s] : case num at c-th column, state=s
//         = sum(d[c-1][ps])
// m = num of columns
// b[c] = num of boxes at c-th column
// bit_count(s) = num of bit 1 at s -> bit_count(s) = b[c]
// convert(s) = change s into array

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
long long d[7][1<<7]; // col:7, state:2^7
int bit_count(int &s) {
    int cnt = 0;
    for (int i=0; i<7; i++) {
        if (s & (1<<i)) cnt += 1;
    }
    return cnt;
}
vector<int> convert(int &s) {
    vector<int> ans;
    for (int i=0; i<7; i++) {
        if (s & (1 << i)) {
            ans.push_back(i); // 1001 -> 0, 4
        }
    }
    return ans;
}
int main() {
    int k;
    while (cin >> k) { // wait for the input : k = num of row
        vector<int> a(k);
        for (int i=0; i<k; i++) {
            cin >> a[i];
        }
        int m = a[0]; // num of column
        // b[0] b[1] b[2] b[3]
        // =4   =3   =2   =1
        // 1    1    1    1   -> a[0]=4
        // 2    2    2
        // 3    3
        // 4

        vector<int> b(m); //b[c] = num of boxes at c-th column
        for (int i=0; i<k; i++) {
            for (int j=0; j<a[i]; j++) {
                b[j] += 1;
            }
        }
        int n;
        cin >> n; // 1~n (1~7)
        // each column's number is not the same -> bitmask
        // if they are the same, we don't use bitmask 
        memset(d,0,sizeof(d));
        // d[c][s] : case num at c-th column, state=s
        //         = sum(d[c-1][ps])
        for (int s=0; s<(1<<n); s++) {
            int cnt = bit_count(s);
            if (cnt != b[0]) continue;
            d[0][s] = 1; // case num at 0-th column (s:all possible cases)
        }
        for (int j=1; j<m; j++) { // j-th column : all states
            for (int s=0; s<(1<<n); s++) {
                int cnt = bit_count(s);
                if (cnt != b[j]) continue; // check the num
                for (int ps=0; ps<(1<<n); ps++) { // previous states
                    int pcnt = bit_count(ps); 
                    if (pcnt != b[j-1]) continue; // check the num
                    // ps s
                    // 1  1  1  1
                    // 2  2  2
                    // 3
                    // ps = 0000111 -> v1[] = 1 2 3
                    //  s = 0000011    v2[] = 1 2
                    vector<int> v1 = convert(ps); 
                    vector<int> v2 = convert(s);
                    bool ok = true;
                    for (int i=0; i<v2.size(); i++) {
                        if (v1[i] > v2[i]) { // expect: v1[i] <= v2[i]
                            ok = false;
                        }
                    }
                    if (ok == false) continue;
                    d[j][s] += d[j-1][ps];
                }
            }
        }
        // d[c][s] : case num at c-th column, state=s
        //         = sum(d[c-1][ps])
        // when c = m-1 (end)
        //          sum(d[m-1][s]) (s= b[m-1] is column's num in all states)
        long long ans = 0;
        for (int s=0; s<(1<<n); s++) {
            int cnt = bit_count(s);
            if (cnt != b[m-1]) continue; //check if state's 1's num == b[m-1] 
            ans += d[m-1][s];
        }
        cout << ans << '\n';
    }
    return 0;
}
