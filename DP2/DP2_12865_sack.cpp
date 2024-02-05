// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int s;
int m;
int v[52];
int d[52][1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    d[0][s] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) {
            if (d[i][j]) {
                if (j+v[i] <= m) {
                    d[i+1][j+v[i]] = 1;
                }
                if (j-v[i] >= 0) {
                    d[i+1][j-v[i]] = 1;
                }
            }
        }
    }
#if 0
    printf("0 1 2 3 4 5 6 7 8 9 10\n");
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=10; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
#endif
    int ans = -1;
    for (int j=1; j<=m; j++) {
        if (d[n][j]) {
            ans = j;
        }
    }
    cout << ans << '\n';
    return 0;
}