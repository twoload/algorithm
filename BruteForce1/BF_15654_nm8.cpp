#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int a[10];
int num[10];
bool c[10];
void go(int index, int start, int n, int m)
{
    if (index == m) {
        for(int i=0; i<m; i++) {
            cout << num[a[i]];
            if (i != m-1) cout << " ";
        }
        cout << '\n';
        return;
    }
    for (int i= start; i<n; i++) {
        //if (c[i]) continue;
        //c[i] = true;
        a[index] = i;
        go(index+1, i, n, m);
        //c[i] = false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m; 
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num, num+n);
    go(0,0,n,m);
    return 0;
}