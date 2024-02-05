#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque> // push_front, push_back
#include <tuple>
#include <queue>
using namespace std;

bool check[200][200];
bool ans[200];
int a,b,c;

int main() {   
    cin >> a >> b >> c;
    check[0][0] = true;
    ans[c] = true;
    queue<pair<int,int>> q;
    int sum = c;
    q.push(make_pair(0,0));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int z = sum-x-y;
        // x->y
        int nx = x;
        int ny = y;
        int nz = z;
        ny += nx; nx = 0;
        if (ny >= b) {
            nx = ny-b;
            ny = b;
        } 
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }
        // x->z
        nx = x;
        ny = y;
        nz = z;
        nz += nx; nx = 0;
        if (nz >= c) {
            nx = nz-c;
            nz = c;
        } 
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }
        // y->x
        nx = x;
        ny = y;
        nz = z;
        nx += ny; ny = 0;
        if (nx >= a) {
            ny = nx-a;
            nx = a;
        } 
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }
        // y->z
        nx = x;
        ny = y;
        nz = z;
        nz += ny; ny = 0;
        if (nz >= c) {
            ny = nz-c;
            nz = c;
        } 
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }
        // z->x
        nx = x;
        ny = y;
        nz = z;
        nx += nz; nz = 0;
        if (nx >= a) {
            nz = nx-a;
            nx = a;
        } 
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }
        // z->y  
        nx = x;
        ny = y;
        nz = z;
        ny += nz; nz = 0;
        if (ny >= b) {
            nz = ny-b;
            ny = b;
        } 
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }
    }
    for (int i=0; i<=sum; i++) {
        if (ans[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}