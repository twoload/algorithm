#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1: 1
// 2: 10
// 3: 100
// 4: 101
// 5: 1000
// 6: 1001
// 7: 1010

// prev one : 1, 0 check
//   if prev one is 1,
//      cur one should be 0
//   if prev one is 0,
//      cur one 0, 1

// d[n][2] : order at n len, cur 0,1
// d[n][1] = 
//           d[n-1][0]
//           0==(d[n-1][1]) 
// d[n][0] = d[n-1][0]
//           d[n-1][1]  

// teacher
// d[n] : pinary at len n
// d[n] = d[n-1] + d[n-2]
// last num is 0 : d[n-1] = 0/1 (n-1) - 0 (n)
// last num is 1 : d[n-2] = 0/1 (n-2) - 0 (n-1) - 1(n)

// s[i] = sum of d[j] (1<=j<=i)

// 1. 1       14. 100001
// 2. 10      15. 100010
// 3. 100     16. 100100
// 4. 101     17. 100101
// 5. 1000    18. 101000
// 6. 1001    19. 101001
// 7. 1010    20. 101010
// 8. 10000   21. 1000000
// 9. 10001   22. 1000001
// 10. 10010  23. 1000010
// 11. 10100  24. 1000100
// 12. 10101  25. 1000101
// 13. 100000 26. 1001000
 
// i  : 1 2 3 4 5 6 7
//d[i]: 1 1 2 3 5 8 13     //d[1]=1,d[2]=1,d[3]=2,d[4]=3,d[5]=5
//s[i]: 1 2 4 7 12 20 33

// d[1]= 1  1
// d[2]= 1  10
// d[3]= 2  100, 101
// d[4]= 3  1000, 1001, 1010
// d[5]= 5  10000, 10001, 10010, 10100, 10101
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m = 100;
    vector<long long> d(m+1);
    d[1] = 1;
    for (int i=2; i<=m; i++) {
        d[i] = d[i-1] + d[i-2]; // d
    }
    vector<long long> s(m+1);
    for (int i=1; i<=m; i++) {
        s[i] = s[i-1] + d[i];   // s
    }
    long long k; // order
    cin >> k;
    if (k == 1) {
        cout << "1" << '\n';  // exception
    } else {
// s[1]=1 d[1]= 1  1
// s[2]=2 d[2]= 1  10
// s[3]=4 d[3]= 2  100, 101
// s[4]=7 d[4]= 3  1000, 1001, 1010
// s[5]=12 d[5]= 5  10000, 10001, 10010, 10100, 10101

// ex0. n=6 d[6]=8
// pinary len:n = pinary len:n-2 extends to len:n
//     100/001
//     100/010
//     100/100
//     100/101
//   2-th num = 0's pinary   =   pinary (<= len n-3)
//     10/1000
//     10/1001
//     10/1010
//   2-th num = 1's pinary   =   pinary (<= len n-2)

// ex1. k=10
        cout << "10";
        int n = 0;
        for (int i=2; i<=m; i++) {
            if (k <= s[i]) {
                n = i;
                break;
            }
        }
        //             n d s
        // 1:      1   1 1 1
        // 2:     10   2 1 2
        // 3:    100   3 2 4
        // 4:    101
        // 5:   1000   4 3 7
        // 6:   1001
        // 7:   1010
        //---------------------
        // 8:  10/0/00   5 5 12
        //---------------------
        // 9:  10/0/01
        //10:  10/0/10 * k=2 == s[n-1]=s[2]=2
        //11:  10/10/0
        //12:  10/10/1

        k = k-s[n-1]-1; // k = 10-7 -1 = 3-1 = 2   added : 10/
        n = n-2;        // n = 5-2 = 3 (number of digits) 

        while (n > 0) {
            if (k > s[n-1]) { // n-1=2  (k=2 == s[n-1]=2)
                if (n >= 2) {
                    cout << "10"; 
                } else {
                    cout << "1";
                }
                k = k-s[n-1]-1;  
                n = n-2; 
            } else {
                cout << "0";
                n -= 1;  
            }
        }
        cout << '\n';
    }
    return 0;
}
