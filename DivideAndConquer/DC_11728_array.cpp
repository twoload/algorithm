// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> merge(vector<int>& a, vector<int>&b) {
    int i=0;
    int j=0; 
    vector<int> c;
    int n = a.size();
    int m = b.size();
    while (i<n && j<m) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    while (i<n) {
        c.push_back(a[i]);
        i++;
    }
    while (j<m) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}
vector<int> merge_sort(vector<int>& v, int start, int end) {
    if (start == end) {
        vector<int> c;
        c.push_back(v[start]);
        return c;
    }
    int mid = (start+end)/2;
    vector<int> a = merge_sort(v, start, mid);
    vector<int> b = merge_sort(v, mid+1, end);
    return merge(a, b);
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n+m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
        c[i+n] = b[i];
    }

    vector<int> d = merge_sort(c, 0, c.size()-1);   
    
    for (int i: d) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}