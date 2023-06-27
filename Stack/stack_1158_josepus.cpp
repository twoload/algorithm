#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    queue<int> q;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    printf("<");
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            q.push(q.front());
            q.pop();
        }
        printf("%d, ",q.front());
        q.pop();
    }
    printf("%d>\n", q.front());
    return 0;
}
