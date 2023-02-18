#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// substr print
// O(n)
// sort O(nlogn) X
// sort O(n^2logn) : compare two strings : O(n)

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
string s;
bool cmp(const int &u, const int &v) { // O(n)
    return strcmp(s.c_str()+u, s.c_str()+v) < 0;
}
int main() {
    cin >> s; //baekjoon
    int n = s.length(); 
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        a[i] = i; //a[0]=0,a[1]=1,a[2]=2,.... : start index
    }
    sort(a.begin(), a.end(), cmp);// by start index
    for (int x : a) {
        cout << s.substr(x) << '\n';
    }
    return 0;
}