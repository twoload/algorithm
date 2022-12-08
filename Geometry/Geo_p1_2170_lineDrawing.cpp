#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> a(2*n); //start,end
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        a[i] = make_pair(x,1); //start +1
        a[i+n] = make_pair(y,-1); //end -1
    }
    sort(a.begin(),a.end()); //y is first called than x
    int ans = 0;
    int cnt = 0;
    int last = 0; // start position
    for (auto &p : a) {
        if (p.second == 1 && cnt == 0) { // start
            last = p.first;
        }
        cnt += p.second;
        if (p.second == -1 && cnt == 0) { // end
            ans += p.first - last; // accumulate
        }
    }
    cout << ans << '\n';
    return 0;
}