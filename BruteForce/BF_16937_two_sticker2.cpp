#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <tuple>
#include <cstring>
using namespace std;

int h, w;
int n;

int main() {
    cin >> h >> w;
    cin >> n;
    vector<pair<int,int>> a;
    for (int i=0; i<n; i++) {
        int r, c;
        cin >> r >> c;
        a.push_back(make_pair(r, c));
    }
    int ans = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (i==j) continue;
            int r1,r2,c1,c2;
            tie(r1,c1) = a[i];
            tie(r2,c2) = a[j];
            vector<pair<int,int>> aa;
            vector<pair<int,int>> bb;
            aa.push_back(make_pair(r1,c1));
            aa.push_back(make_pair(c1,r1));
            bb.push_back(make_pair(r2,c2));
            bb.push_back(make_pair(c2,r2));
            for (int k=0; k<2; k++) {
                for (int l=0; l<2; l++) {
                    int rr1,cc1,rr2,cc2;
                    tie(rr1,cc1) = aa[k];
                    tie(rr2,cc2) = bb[l];
                    if ((rr1<=h && rr2<=h && cc1+cc2<=w) ||
                        (cc1<=w && cc2<=w && rr1+rr2<=h)) {
                            if (ans < rr1*cc1+rr2*cc2) {
                                ans = rr1*cc1+rr2*cc2;
                            }
                        }    
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}