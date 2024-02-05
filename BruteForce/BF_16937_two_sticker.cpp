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
                    
                }
            }
            int r1,r2,c1,c2;
            



            if ((h>=r2 && w-c1>=c2) ||
                (h>=c2 && w-c1>=r2) ||
                (w>=r2 && h-r1>=c2) ||
                (w>=c2 && h-r1>=r2) ||
                (h>=r2 && w-r1>=c2) ||
                (h>=c2 && w-r1>=r2) ||
                (w>=r2 && h-c1>=c2) ||
                (w>=c2 && h-c1>=r2)) {
                int sum = r1*c1+r2*c2;
                if (ans < sum) {
                    ans = sum;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}