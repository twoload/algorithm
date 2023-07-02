#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

// j, i

// d[i] : max len at i-th
//      = max(d[j] + 1),  j < i, a[j] > a[i]

#include <cstdio>
int a[1001];
int d[1001];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=1; i<=n; i++) {
        d[i] = 1;
        for (int j=1; j<i; j++) {
            if (a[j] > a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
    }
    int ans = d[1];
    for (int i=2; i<=n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}