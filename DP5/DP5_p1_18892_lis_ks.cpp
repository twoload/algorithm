#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// find LIS
// sort by compare
// find k-th

// d[i][j] : num of lis at i-th index, last num=j
//   = max(d[i-1][k] + 1),  1<=k<j

// teacher
// d[i] = max(d[j]) + 1 , j<i
//                      A[j]<A[i]
// d[i] : length of LIS ending at A[i]

// d[i] = length of LIS starting from A[i]
// cnt[i] = num of LIS starting from A[i]
//
// i   j
// d[i] = max(d[j]) + 1
//       i < j
//      a[i] < a[j]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long limit = 1'000'000'000'000LL;
int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) { // input
        cin >> a[i];
    }
    // d[i] = length of LIS starting from A[i]
    // cnt[i] = num of LIS starting from A[i]
    vector<int> d(n+1);
    vector<long long> cnt(n+1);
    for (int i=n; i>=1; i--) { // from the end
        d[i] = 1; //init: 1
        cnt[i] = 1; //init: 1
        // i, ... j
        for (int j=i+1; j<=n; j++) {
            if (a[i] < a[j]) {
                if (d[i] == d[j]+1) {
                    cnt[i] += cnt[j]; // +1 : more candidates
                } else if (d[i] < d[j]+1) { // i, j
                    d[i] = d[j]+1; // update
                    cnt[i] = cnt[j]; // update
                }
                if (cnt[i] > limit) {
                    cnt[i] = limit;
                }
            }
        }
    }
    int len = *max_element(d.begin(), d.end()); // max
    int start = 0;
    vector<int> ans;
    while (len > 0) {
        long long sum = 0;
        int nstart = -1;
        vector<pair<int,int>> candi;
        for (int i=start+1; i<=n; i++) {
            // we need to check big/small relations
            if (a[start] < a[i] && d[i] == len) { // len is decreased at the next round from the bottom
                // 1. a[i], i
                candi.push_back(make_pair(a[i], i));
            }
        }
        // order by a[i] : small -> big
        // i: 1 2 3 4 5 6
        // a: 2 6 4 1 3 5
        // d: 3 1 2 3 2 1
        // c: 2 1 1 1 1 1

        // k = 1:[1,3,5] - 1 starting 1
        // k = 2:[2,3,5] \ 2 starting 2
        // k = 3:[2,4,5] /

        sort(candi.begin(), candi.end());
        for (auto &p : candi) {
            int i = p.second;
            sum += cnt[i];
            if (k <= sum) { // found
                ans.push_back(a[i]); // add
                nstart = i; // next start
                k -= (sum-cnt[i]); // k update
                break;
            }
        }
        if (nstart == -1) {
            cout << -1 << '\n';
            return 0;
        }
        start = nstart; //update start
        len -= 1; // len-1
    }
    for (int x : ans) { // print out
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
