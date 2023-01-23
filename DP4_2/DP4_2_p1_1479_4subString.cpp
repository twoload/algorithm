#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// S : S'len <=2500
// a,b,c,d : len <=50
// a,b,c,d : max 50 ea
// all cases : 50^4 = 6'250'000
// string match : O(len*len*len*len)
//  -> total : 50^4*len^4 = 50^4*50^4 = 50^8 
// min, max
// abacaba
// ab
//  ba
// a  c  -> 4
// abac ba->6

// teacher
// which subString is used? 2^4 (state)
// d[index][covered][mask]
//   cur: index, 
//   covered: num of hided strings
//   used sub strings : mask

// foursubstrings
//  our
//  ^
//  |
//  index
//  *** (covered)
//  state = a
// d[1][3][0001]

// index
// 1. pass
//    index -> index+1
//    covered -> covered -1 >0
//    mask -> mask
// 2~5. a,b,c,d use
//    index -> index+1
//    covered
//    mask

// starts[i][j] : s's i-th~j-th subStrings match:1, not:0

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;
// d[index][covered][mask]
//   cur: index, 
//   covered: num of hided strings
//   used sub strings : mask
pair<int,int> d[2501][51][1<<4];
string a[4];
string str;
pair<int,int> go(int index, int covered, int mask) {
    //cout<<"index: "<< index << " covered: " << covered << " state: " << bitset<8>(mask) << '\n';
    if (mask == 0) { // end: success
        // a, b, c, d = a'len + b'len + c'len + d'len + (len at mask==0)
        // what is len at (mask == 0) ? 0 
        //    because a'len + b'len + c'len + d'len only consider (overlap is possible) 
        return make_pair(0, 0); // min, max
    }
    auto &ans = d[index][covered][mask]; // memoization
    if (ans.first != -1) {
        return ans;
    }
    ans = make_pair(1'000'000, -1'000'000); // init value (max: 2500) 
    if (index == str.size()) {
        return ans; // fail -> max, min 
    }
    // abacaba
    // go(0,0,1111)
    // 1.pass
    //   go(1,0,1111)
    //   1.pass
    //     go(2,0,1111)
    //     1.pass
    //       go(3,0,1111)
    //       1.pass
    //         go(i,0,1111)
    //     2.a,b,c,d
    //   2.a,b,c,d
    // 2.a,b,c,d
    //   a: (ab)
    //      nextc = 2
    //      go(0,2,1110)
    //         1.pass
    //           go(1,1,1110)
    //         2.b,c,d
    //           c=(a)
    //           go(0,2,1010)
    //           1.pass
    //             go(1,1,1010)
    //             1. pass
    //                go(2,0,1010)
    //             2. bcd
    //                b=(ba)
    //                 nextc = 2-1 = 1
    //                 temp=go(1,2,1000)
    //                 min(nextc+temp.first), max(nextc+temp.second)                 
    //           2.d
    //             continue
    ans = go(index+1, max(0, covered-1), mask); // pass
    for (int i=0; i<4; i++) { //a,b,c,d
        if (mask & (1<<i)) {
            if (str.substr(index, a[i].size()) == a[i]) { //if substr matches a[i] 
                int nextc = 0;
                if (a[i].size() > covered) { // compare to previous covered
                    nextc = (int)a[i].size() - covered; // if cur size is bigger, diff should be added when calc min,max len
                }
                // all mask hasn't been 0000 yet.
                // go until mask become 0000
                auto temp = go(index, max(covered, (int)a[i].size()), mask - (1<<i));
                // why index is index ? not index+1 ?
                //    because a,b,c,d can be same position (overlap)
                //    mask check is needed
                ans = make_pair(min(temp.first+nextc, ans.first), max(temp.second+nextc, ans.second));
                //cout << "min: " << min(temp.first+nextc, ans.first) << " max: " << max(temp.second+nextc, ans.second) << '\n';
            }
        }
    }
    return ans;
}
int main() {
    cin >> str;
    for (int i=0; i<4; i++) {
        cin >> a[i]; //a,b,c,d
    }
    sort(a,a+4);
    memset(d,-1,sizeof(d));

    // index, covered, mask (15=1111)
    auto ans = go(0, 0, 15);
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}

