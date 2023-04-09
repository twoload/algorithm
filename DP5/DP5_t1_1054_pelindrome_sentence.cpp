#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// like 1254 problem ?
// but duplicate is not allowed

// d[state][str][dir] ??? 

// teacher
// d[used][index][len][lr] 
// state = used (bitmask) OK
// string which is not penlindrome in the mid : len from end of index-th word
// if string which is not penlindrome is left : lr = 0
//                                       right : lr = 1

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
string a[13];
string ar[13];
int n;
// d[used][index][len][lr] 
long long d[1<<13][13][14][2];
bool palin(string s) {
    for (int i=0; i<s.length()/2; i++) {
        if (s[i] != s[s.length()-i-1]) return false;
    }
    return true;
}
long long go(int used, int index, int len, int lr) { // long long
    long long &ans = d[used][index][len][lr]; // memoization
    if (ans != -1) return ans; 
    ans = 0;
    int start = a[index].length() - len;     
    string suffix = a[index].substr(start);
    if (lr == 1) {
        suffix = ar[index].substr(start);    
    }
    if (palin(suffix)) {
        ans += 1;
    }
    //printf("used:");
    //cout << bitset<10>(used) << "\n";
    for (int i=0; i<n; i++) {
        if ((used & (1<<i)) == 0) { // not used : first visit
            int plen = min(len, (int)a[i].length()); // new one
            //printf("i=%d, plen:%d (len:%d, a[%d].len:%d)\n", i, plen, len, i, (int)a[i].length());
            if (lr == 0) { //if string is on the left that is not penlindrome, 
                // ???abc...de???        ???abc...defg???
                //    ---   --              ---   ----
                //    len   plen            len   
                //                         plen
                //printf("lr=0, a[%d:%d]:%s == ar[%d:%d]:%s ?\n", start, plen, a[index].substr(start, plen).c_str(), 0, plen, ar[i].substr(0, plen).c_str());
                if (a[index].substr(start, plen) == ar[i].substr(0, plen)) { // if same : a
                    if (len > plen) {
                        //printf("len:%d > plen:%d : go(", len, plen);
                        //cout << bitset<10>(used| (1<<i));
                        //printf("), %d, %d, 0\n", index, len-plen);
                        ans += go((used | (1<<i)), index, len-plen, 0);
                    } else {
                        //printf("len:%d <= plen:%d : go(", len, plen);
                        //cout << bitset<10>(used| (1<<i));
                        //printf("), %d, %d, 1\n", i, ar[i].length()-plen);
                        ans += go((used | (1<<i)), i, ar[i].length()-plen, 1);
                    }
                }
            } else { //if string is on the right that is not penlindrome, 
                // ???de....abc???        ???defg...abc???
                //    --    ---              ----   ---
                //   plen   len                     len   
                //                                  plen
                //printf("lr=1, a[%d:%d]:%s == ar[%d:%d]:%s ?\n", start, plen, ar[index].substr(start, plen).c_str(), 0, plen, a[i].substr(0, plen).c_str());
                if (ar[index].substr(start, plen) == a[i].substr(0, plen)) { // if same
                    if (len > plen) {
                        //printf("len:%d > plen:%d : go(", len, plen);
                        //cout << bitset<10>(used| (1<<i));
                        //printf("), %d, %d, 1\n", index, len-plen);
                        ans += go((used | (1<<i)), index, len-plen, 1);
                    } else {
                        //printf("len:%d <= plen:%d : go(", len, plen);
                        //cout << bitset<10>(used| (1<<i));
                        //printf("), %d, %d, 0\n", i, a[i].length()-plen);
                        ans += go((used | (1<<i)), i, a[i].length()-plen, 0);
                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ar[i] = a[i];
        reverse(ar[i].begin(), ar[i].end());
        // a[i]: a, ab
        // ar[i]: a, ba
    }
    memset(d,-1,sizeof(d));
    //printf("go(");
    //cout << bitset<10>(0);
    //printf("), 0, 0, 0, 0)\n");
    cout << (go(0, 0, 0, 0) - 1) << '\n';
}