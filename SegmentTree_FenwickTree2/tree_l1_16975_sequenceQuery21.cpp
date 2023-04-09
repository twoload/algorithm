#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
using namespace std;
long long sum(vector<long long> &tree, int x) {
    long long ans = 0;
    for (int i=x; i>0; i -= i&-i) {
        ans += tree[i];
    }
    return ans;
}
void update(vector<long long> &tree, int x, long long diff) {
    for (int i=x; i<tree.size(); i += i&-i) {
        tree[i] += diff;
    }
}
void update(vector<long long> &tree, int x, int y, long long diff) {
    update(tree, x, diff);
    update(tree, y+1, -diff);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n+1);
    vector<long long> tree(n+2);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int start, end;
            long long val;
            cin >> start >> end >> val;
            update(tree, start, end, val);
        } else {
            int index;
            cin >> index;
            long long diff = sum(tree, index);
            cout << a[index] + diff << '\n';
        }
    }
    return 0;
}
