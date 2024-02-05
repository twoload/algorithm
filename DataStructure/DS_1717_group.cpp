#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

//https://ongveloper.tistory.com/94
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int parent[1000001];

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}
void findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for (int i=0; i<m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (!op) {
            unionParent(a,b);
        } else {
            findParent(a,b);
        }
    }

    return 0;
}