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

int n, k;
int d[100001];
bool check[100001];


int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    check[n] = true;
    d[n] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            printf("%d\n", d[x]);
            return 0;
        }
        int nx = x -1;
        if (0<= nx && nx <=100000) {
            if (check[nx] == false) {
                q.push(nx);
                check[nx] = true;
                d[nx] = d[x] + 1;
            }
        }
        nx = x +1;
        if (0<= nx && nx <=100000) {
            if (check[nx] == false) {
                q.push(nx);
                check[nx] = true;
                d[nx] = d[x] + 1;
            }
        }
        nx = 2*x;
        if (0<= nx && nx <=100000) {
            if (check[nx] == false) {
                q.push(nx);
                check[nx] = true;
                d[nx] = d[x] + 1;
            }
        }
    }
    return 0;
}