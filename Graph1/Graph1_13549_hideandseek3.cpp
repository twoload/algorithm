#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std; 

const int MAX = 200000; // important!!!
int d[MAX+1];
bool check[MAX+1];
int from[MAX+1];

void print(int n, int m) {
    if (n != m) {
        print(n, from[m]);
    }
    cout << m << ' ';
}
int main() {
    int n, m;
    cin >> n >> m;
    check[n] = true;
    d[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now-1 >= 0) {
            if (check[now-1] == false) {
                q.push(now-1);
                check[now-1] = true;
                d[now-1] = d[now] + 1;
                from[now-1] = now;
            }
        }
        if (now+1 < MAX) {
            if (check[now+1] == false) {
                q.push(now+1);
                check[now+1] = true;
                d[now+1] = d[now] + 1;
                from[now+1] = now;
            }
        }
        if (now*2 < MAX) {
            if (check[now*2] == false) {
                q.push(now*2);
                check[now*2] = true;
                d[now*2] = d[now];// + 1;
                from[now*2] = now;
            }
        }
    }
    cout << d[m] << '\n';
    //print(n, m);
    /* print with stack
    stack<int> ans;
    for (int i=m; i!=n; i=from[i]) {
        ans.push(i);
    }
    ans.push(n);
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    */
    //cout << '\n';
    return 0;
}