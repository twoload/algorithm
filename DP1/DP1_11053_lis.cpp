#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// d[n] : max lis length of subsequence len n
//        max(d[i])+1

// d[i] = max(d[j])+1, j<i, A[j] < A[i]

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    for (int i=0; i<n; i++) {
        d[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
    return 0;
}

#if 0
#include <iostream>
using namespace std;

int a[1001];
int d[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    //for (int i=0; i<n; i++) {
    //    d[i] = 1;
    //}
    // O(n^2)
    for (int i=0; i<n; i++) {
        d[i] = 1;
        for (int j=0; j<i; j++) {
            if ((d[i] < d[j] + 1) && (a[j] < a[i])) {
                d[i] = d[j] + 1;
            }
        }
    }   
    int ret = 0; 
    for (int i=0; i<n; i++) {
        if (ret < d[i])
            ret = d[i];
    }
    cout << ret << '\n';
    return 0;
}
#endif