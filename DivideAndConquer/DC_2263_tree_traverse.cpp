// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int inorder[100001];
int postorder[100001];

void solve(int is, int ie, int ps, int pe) {
    if (is == ie) {
        cout << inorder[is] << ' ';
        return;
    }
    int root=-1;
    for (int i=is; i<=ie; i++) {
        if (inorder[i] == postorder[pe]) {
            root = i;
            break;
        }
    }
    if (root == -1) return;
    cout << inorder[root] << ' ';
    int len_left = root-1-is+1;
    int len_right = ie-(root+1)+1;
    solve(is, root-1, ps, ps+len_left-1);
    solve(root+1, ie, ps+len_left, ps+len_left+len_right-1);
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    for (int i=0; i<n; i++) {
        cin >> postorder[i];
    }
    solve(0, n-1, 0, n-1);
    return 0;
}