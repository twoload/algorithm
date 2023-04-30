#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// left1, right1
// left2, right2
// left3, right3
// ...

// left1 < left2 < right1 : +1
// right1 < right2 < right1 : +1
// ...

// teacher
// A[x] : how many flowers can be blossomed in x ?
//     -----
//     |   |
// --------------
//     L   R
// A[L] + A[R] : numbers of flowers which blossom newly : ??? not segment
// A[L] = A[R] = 0 (flowers will not be blossomed any more)
// [L+1, R-1] -> A[x]+=1 : update in segment

// update segment . but query is not segment


// A[L] = A[R] = 0 ???
// B[x] : numbers of flowers which blossom in x
// B[x] += A[x]

// A[x] - B[x] : numbers of flowers which blossom newly in x
// A[L] + A[R] - B[L] - B[R] : numbers of flowers which blossom newly
// B[L] += A[L], B[R] += A[R]


#include <iostream>
#include <vector>
using namespace std;
const int max_x = 100000;
int sum(vector<int> &tree, int x) {
    int ans = 0;
    for (int i=x; i>0; i -= i&-i) {
        ans += tree[i];
    }
    return ans;
}
void update(vector<int> &tree, int x, int diff) {
    for (int i=x; i<tree.size(); i += i&-i) {
        tree[i] += diff;
    }
}
// update segment [x,y]
void update(vector<int> &tree, int x, int y, int diff) {
    update(tree, x, diff);
    update(tree, y+1, -diff);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(max_x+1); // A[L] = A[R] = 0 , B[x] += A[x]
    vector<int> tree(max_x+2); // fenwick tree
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        int cnt_l = sum(tree, l) - b[l]; // num of flowers
        int cnt_r = sum(tree, r) - b[r];
        cout << cnt_l + cnt_r << '\n';
        b[l] += cnt_l;                   // A[L] = 0
        b[r] += cnt_r;                   // A[R] = 0
        update(tree, l+1, r-1, 1);       // update +1 in [L+1, R-1] 
    }
    return 0;
}



