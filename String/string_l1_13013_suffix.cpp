#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// m^n : brute force (m: min number)
//
// teacher
// 3: a
// 0: b
// 1: c
// 2: d
// -> s = "bcda"
// 3: a
// 0: bcda
// 1: cda
// 2: da
// -> s = "aaba" (2)
// 3: a
// 0: aaba
// 1: aba
// 2: ba

// SA = [3, 0, 1, 2]
//       a  a     a
//       _  _  _  _
//       0  1  2  3
//
// 3: a
// 0: a 1'suffix
// 1: a 2'suffix (1'suffix < 2'suffix)
// 2: a 3'suffix (3'suffix < 2'suffix) X
// 2: b 3'suffix (3'suffix < 2'suffix) O
//
// i          : 0 1 2 3 4 5 6 7 8 9
// suffixArray: 7 4 8 6 1 5 2 9 3 0
// string s   :   b c   a c b a a d 
//              d b c d a c b a a d   
// 7:a 8'suffix
// 4:? 5'suffix (8'suffix < 5'suffix)
// 8:? 9'suffix (5'suffix < 9'suffix)
// 6:b 7'suffix (9'suffix > 7'suffix) !!!
// 1:? 2'suffix (7'suffix < 2'suffix)
// 5:c 6'suffix (2'suffix > 6'suffix) !!!
// 2:? 3'suffix (6'suffix < 3'suffix)
// 9:d 10'suffix (10'suffix: the earliest one)
// 3:? 4'suffix (10'suffix < 4'suffix)
// 0:? 1'suffix (4'suffix < 1'suffix)


#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
// i          : 0 1 2 3 4 5 6 7 8 9
// suffixArray: 7 4 8 6 1 5 2 9 3 0
// string s   :   b c   a c b a a d 
    vector<int> sa(n); //suffix array
    vector<int> s(n+1);//order
    for (int i=0; i<n; i++) {
        cin >> sa[i];
        s[sa[i]] = i;
    }
    //n-1: last one
    s[n] = -1; // empty : the earliest

    // sa[i] < sa[i+1]
    // if sa[i] ch == sa[i+1] ch
    //    sa[i]+1'suffix < sa[i+1]+1'suffix
    int cnt = 1;
    for (int i=0; i<n-1; i++) {
        // i=0: s[sa[0]+1] < s[sa[1]+1]       ,if you want to put 1
        // i=1: s[sa[1]+1] < s[sa[2]+1]
        // ...
        // i=n-2: s[sa[n-2]+1] < s[sa[n-1]+1] ,if you want to put n-1
        if (s[sa[i] + 1] > s[sa[i+1]+1]) {
            cnt += 1;
        }
    }

    cout << cnt << '\n';
    return 0;
}