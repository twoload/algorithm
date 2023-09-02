#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <algorithm>
using namespace std;


int num[10];
int a[10];
int cnt[10];
void go(int index, int selected, int n, int m)
{
    if (selected == m) {
        for (int i=0; i<n; i++) {
            for (int j=1; j<=cnt[i]; j++) {
                cout << num[i] << " ";
            }
        }
        cout << "\n";
        return;
    }

    
    if (index >= n) return;
    for (int i=m-selected; i>=1; i--) {
        cnt[index] = i;
        go(index+1, selected+i, n, m);
    }
    cnt[index] = 0;
    go(index+1, selected, n, m);
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