#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

bool isPrime[10000];
bool check[10000];
int d[10000];

int main() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for (int n=2; n*n<10000; n++) {
        if (isPrime[n]==true) {
            for (int m=n*2; m<10000; m=m+n) {
                isPrime[m] = false;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x,y;
        cin >> x >> y;
        memset(d, -1, sizeof(d));
        queue<int> q;
        q.push(x);
        d[x] = 0;
        while (!q.empty()) {
            x = q.front(); q.pop();
            int nx;
            //1000
            for (int i=1; i<=9; i++) {
                int a = (x % 10000) / 1000; 
                int aa = (a+i)%10;
                int nx = x - (a*1000);
                nx = nx + (aa*1000);
                if (nx < 1000) continue; 
                if (isPrime[nx]) {
                    if (d[nx] == -1) {
                        d[nx] = d[x]+1;
                        q.push(nx);
                    }
                }
            }
            //100
            for (int i=1; i<=9; i++) {
                int a = (x % 1000) / 100; 
                int aa = (a+i)%10;
                int nx = x - (a*100);
                nx = nx + (aa*100);
                if (nx < 1000) continue;
                if (isPrime[nx]) {
                    if (d[nx] == -1) {
                        d[nx] = d[x]+1;
                        q.push(nx);
                    }
                }
            }
            //10
            for (int i=1; i<=9; i++) {
                int a = (x % 100) / 10; 
                int aa = (a+i)%10;
                int nx = x - (a*10);
                nx = nx + (aa*10);
                if (nx < 1000) continue;
                if (isPrime[nx]) {
                    if (d[nx] == -1) {
                        d[nx] = d[x]+1;
                        q.push(nx);
                    }
                }
            }
            //1
            for (int i=1; i<=9; i++) {
                int a = (x % 10) / 1; 
                int aa = (a+i)%10;
                int nx = x - (a*1);
                nx = nx + (aa*1);
                if (nx < 1000) continue;
                if (isPrime[nx]) {
                    if (d[nx] == -1) {
                        d[nx] = d[x]+1;
                        q.push(nx);
                    }
                }
            }
        }
        if (d[y] == -1) {
            cout << "Impossible" << '\n';
        } else {
            cout << d[y] << '\n';
        }
    }
    return 0;
}