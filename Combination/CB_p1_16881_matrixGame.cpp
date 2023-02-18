#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// each element -> grundy number
// if all numbers are 0 in a row, grundy number is 0
// if there is one number which is not 0, == rock stach is 0
//    grundy number is the number
// if there is two numbers which are not 0,
// ---- Ai ---- Aj ----
// ---- 1  ---- Aj ---- (1,Aj) = 0 -> (0,Aj) = Aj
// (2,Aj) -> (0,Aj)=Aj or (1,Aj)=0 => 1
// (3,Aj) -> (0,Aj)=Aj, (1,Aj)=0, (2,Aj)=1 => 2
// (Ai,Aj) = Ai-1
// 
// (0, Aj) = Aj
// (1~Aj, Aj) = 0~Aj-1
// (Aj+1, Aj) = Aj+1
// (Ai, Aj) = Ai  , Ai >= Aj+1

#include <iostream>
using namespace std;
int a[1001][1001];
int main() {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        int val = a[i][m-1]; 
        for (int j=m-2; j>=0; j--) { // for same row
            if (a[i][j] > val) {     // from the right,,,
                val = a[i][j];
            } else {
                val = a[i][j]-1;
            }
        }
        ans ^= val;
    }
    if (ans > 0) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}
