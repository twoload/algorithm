/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/11780
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define next _next
constexpr int MAX = 101;
constexpr int inf = 987654321; //1000000000

int n, m;
int a[MAX][MAX];
int next[MAX][MAX]; // added

void path(int x, int y)
{
    if (next[x][y] == -1){
        printf("0\n");
        return;
    }
    queue<int> q;
    q.push(x);
    while (x != y) {
        x = next[x][y];
        q.push(x);
    }
    printf("%d ", q.size());
    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop();
    }
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i == j){
                a[i][j] = 0;
            }
            else{
                a[i][j] = inf;
            }
            next[i][j] = -1; //init
        }
    }
    for (int i=0; i<m; ++i){
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        if (a[from][to] > cost){
            a[from][to] = cost;
            next[from][to] = to; // point out
        } 
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                    next[i][j] = next[i][k]; // next[i][j] is not k but next[i][k]
                    // a[i][j]'s value is continually changed
                    // next[i][j] : who did i->j originally point out to ? recording
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (a[i][j] == inf) a[i][j] = 0;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i == j) {
                printf("0\n");
            } else if (a[i][j] == inf) {
                printf("0\n");
            } else {
                path(i, j);
            } 
        }
    }
    return 0;
}