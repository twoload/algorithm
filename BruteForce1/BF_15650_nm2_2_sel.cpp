#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
using namespace std;


int a[10];
bool c[10];
void go(int index, int selected, int n, int m)
{
    if (selected == m) {
        for(int i=0; i<m; i++) {
            cout << a[i];
            if (i != m-1) cout << " ";
        }
        cout << '\n';
        return;
    }
    
    if (index > n) return;
    a[selected] = index;
    go(index+1, selected+1, n, m);
    a[selected] = 0;
    go(index+1, selected, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    go(1,0,n,m);
    return 0;
}