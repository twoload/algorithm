#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// brute force
// row : k (1<= <=7)
// box : l1,l2,...lk (7>=l1>=l2...>=1)
// 7^49
// diagram'shape was determined
// 1111111 1111112 1111122 .... 1111113 ... 1111117
// 1111122         1111123                  1111127
// 1111133                                  1111137
// 1111177
// 1111222
// 7777777
// ...
// there is no duplicate number in one column
// 2^7 bitmask : column, row's number in one column

// d[c][s] : c-th column, state: s -> num of cases
// d[c][s] = sum(d[c-1][ps])
// 1~N -> 0~N-1
// m : num of column
// b[c] : num of boxes at c-th column
// bit_count(s) : num of bit 1 in s
// convert(s) : change bitmask s to array

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
long long d[7][1<<7];
// count 1's number
int bit_count(int &s) {
    int cnt = 0;
    for (int i=0; i<7; i++) {
        if (s & (1<<i)) cnt += 1;
    }
    return cnt;
}
// ex. 011 -> [0,1,1]
//     101 -> [1,0,1]
vector<int> convert(int &s) {
    vector<int> ans;
    for (int i=0; i<7; i++) {
        if (s & (1 << i)) {
            ans.push_back(i);
        }
    }
    return ans;
}
int main() {
    int k;
    while (cin >> k) {
        vector<int> a(k);
        for (int i=0; i<k; i++) {
            cin >> a[i];
        }
        // ex. 2 2 1
        //     3
        //
        //     11 11 12 12 13 13 22 23
        //     2  3  2  3  2  3  3  3
        //     m = 2
        //     b[0]=2
        //     b[1]=1
        // m : column's number
        int m = a[0];
        // b[c] : num of boxes at c-th column
        vector<int> b(m);
        for (int i=0; i<k; i++) {
            for (int j=0; j<a[i]; j++) {
                b[j] += 1; 
            }
        }
        int n;
        cin >> n;
        memset(d, 0, sizeof(d));
        // s: state, bitmask
        // n (k<= n <=7) : 2^7
        // range: 0~ n-1
        // ex. n = 3
        //     s = 000 001 010 011 100 101 110 111 (2^3=8)
        // d[c][s] : c-th column, state: s -> num of cases
        // d[c][s] = sum(d[c-1][ps])
        //
        // 0-th column
        for (int s=0; s<(1<<n); s++) {
            // count 1's number in s
            int cnt = bit_count(s);
            // b[0] : 0-th column's box's number
            // check if cnt is the same as b[0]
            if (cnt != b[0]) continue;
            // increase num of cases with (col 0, state s)
            // d[0][011=3]=1, d[0][101=5]=1, d[0][110=6]=1
            // 011 = 1/2, 101 = 1/3, 110 = 2/3
            d[0][s] = 1;
        }
        // c-th column
        //      col's num = m (0~m-1) 
        //      - 0 is already done
        //      - range (1~m-1)
        for (int j=1; j<m; j++) {
            // s : 000, 001, 010, 011, 100, 101, 110, 111 (8)
            for (int s=0; s<(1<<n); s++) {
                int cnt = bit_count(s);
                // compare bit 1's number in cur pos : b[j]
                if (cnt != b[j]) continue;
                for (int ps=0; ps<(1<<n); ps++) {
                    int pcnt = bit_count(ps);
                    // compare bit 1's number in prev pos: b[j-1]
                    if (pcnt != b[j-1]) continue;
                    vector<int> v1 = convert(ps);
                    vector<int> v2 = convert(s);
                    bool ok = true;
                    for (int i=0; i<v2.size(); i++) {
                        // prev < cur 
                        // i : row's index
                        if (v1[i] > v2[i]) { // wrong
                            ok = false;
                        }
                    }
                    if (ok == false) continue;
                    // if ok, accumulate prev case numbers
                    //    about ps, s state
                    // ex. 11 11 12 12 13 13 22 23
                    //     2  3  2  3  2  2  3  3
                    // ex. 11 : d[1]['1'=001] += d[0]['12'=011]
                    //     2
                    // ex. 23 : d[1]['3'=100] += d[0]['23'=110]
                    //     3
                    d[j][s] += d[j-1][ps];
                }
            }
        }
        long long ans = 0;
        // d[1][001=1]=2 (11/2, 11/3)
        // d[1][010=2]=3 (12/2, 12/3, 22/3)
        // d[1][100=4]=3 (13/2, 13/3, 23/3)
        // total d[m-1][s] = 2+3+3=8
        for (int s=0; s<(1<<n); s++) {
            int cnt = bit_count(s);
            if (cnt != b[m-1]) continue;
            ans += d[m-1][s];
        }
        cout << ans << '\n';
    }
    return 0;
}