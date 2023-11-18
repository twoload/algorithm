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
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;
    int root = postorder[post_end];
    cout << root << ' ';
    int p = position[root];
    // inorder: in_start p in_end
    // postorder : post_start, post_end
    // left : p - in_start
    // right : in_end - p
    int left = p-in_start;
    solve(in_start, p-1, post_start, post_start+left-1);
    solve(p+1, in_end, post_start+left, post_end-1);
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
    for (int i=0; i<n; i++) {
        position[inorder[i]]=i;
    }
    solve(0, n-1, 0, n-1);
    return 0;
}