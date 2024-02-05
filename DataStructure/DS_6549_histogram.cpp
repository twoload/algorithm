#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int ans = 0;
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        stack<pair<int,int>> a;
        int len = 0;
        int sum = 0;
        int h = 0;
        for (int i=0; i<n; i++) {
            int now;
            cin >> now;
            if (a.empty()) { 
                a.push(make_pair(i,now));
            } else {
                if (a.top().second <= now) {
                    a.push(make_pair(i,now));
                } else {
                    int sum = a.top().second;
                    int h = a.top().second;
                    int start = i;
                    if (ans < sum) ans = sum;
                    a.pop();
                    while (!a.empty() && a.top().second <= h && a.top().second > now) {
                        h = a.top().second;
                        int end = a.top().first;
                        len = abs(end-start);
                        sum = h*len;
                        if (ans < sum) ans = sum;
                        a.pop();
                    }
                    a.push(make_pair(i,now));
                }
            }
        }
        int start = 0;
        while (!a.empty())
        {
            h = a.top().second;
            int end = a.top().first;
            len = end-start+1;
            sum = h * len;
            if (ans < sum) ans = sum;
            a.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}
