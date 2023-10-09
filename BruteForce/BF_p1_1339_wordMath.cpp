#if 0
# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# GCF + ACDEB
# 783 + 98654
# = 99437
#
# alphabet <= 10
# max len <= 8
# O(10^8 = 100 000 000) 

# use cpp because of tight time limit
#endif




#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

char alpha[256];
int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
    int m = letters.size();
    int sum = 0;
    for (int i=0; i<m; i++) {
        alpha[letters[i]] = d[i];
    }
    for (string s : a) {
        int now = 0;
        for (char x : s) {
            now = now*10 + alpha[x];
        }
        sum += now;
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<char> letters;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (char x : a[i]) {
            letters.push_back(x);
        }
    }
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());
    int m = letters.size();
    vector<int> d;
    for (int i=9; i>9-m; i--) {
        d.push_back(i);
    }
    sort(d.begin(), d.end());
    int ans = 0;
    do {
        int now = calc(a, letters, d);
        if (ans < now) {
            ans = now;
        }
    } while (next_permutation(d.begin(), d.end()));
    cout << ans << '\n';
    return 0;
}

#if 0
char alpha[256];
int calc(vector<string>& a, vector<char>& letters, vector<int>& d)
{
    int m = letters.size();
    int sum = 0;
    for (int i=0; i<m; i++){
        alpha[letters[i]] = d[i];
        //printf("alpha[%d] = %d\n", letters[i], d[i]);
    }
    for (string s : a) {
        int now = 0;
        for (char x : s) {
            now = now * 10 + alpha[x];
        }
        sum += now;
        //printf("sum: %d, now: %d\n", sum, now);
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<char> letters;
    for (int i=0; i<n; i++){
        cin >> a[i];
        for (char x : a[i]) {
            letters.push_back(x);
        }
    }
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());
    int m = letters.size();
    vector<int> d;
    for (int i=9; i>9-m; i--) {
        d.push_back(i); // append from big numbers
    }
    sort(d.begin(), d.end());
    
    //printf("sorted d: ");
    //for(int i=0; i<d.size(); ++i){
    //    printf("%d ", d[i]);
    //}
    //printf("\n");

    int ans = 0;
    do {
        int now = calc(a, letters, d);
        if (ans < now) {
            ans = now;
        }
    } while (next_permutation(d.begin(), d.end()));
    cout << ans << '\n';
    return 0;
}
#endif