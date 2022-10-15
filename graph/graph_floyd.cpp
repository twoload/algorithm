/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/11404
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAX = 101;
constexpr int inf = 987654321; //1000000000

int n, m;
int a[MAX][MAX];

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
        }
    }
    for (int i=0; i<m; ++i){
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        if (a[from][to] > cost){
            a[from][to] = cost;
        } 
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
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
    return 0;
}