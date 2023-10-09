#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0: +, 1:-, 2:*, 3:/

int calc(int x, int y, int op) {
    if (op == 0) {
        return x + y;
    } else if (op == 1) {
        return x - y;
    } else if (op == 2) {
        return x * y;
    } else if (op == 3) {
        if ((x > 0 && y < 0) || (x < 0 && y > 0)){
            return (abs(x) / abs(y)) * (-1);
        } else {
            return (abs(x) / abs(y));
        }
    }
} 
int main() 
{
    int n;
    cin >> n;
    int a[101];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> op;
    for (int i=0; i<4; i++) {
        int num;
        cin >> num;
        for (int j=0; j<num; j++) {
            op.push_back(i);
        }
    }
    int minval = 1000000000;
    int maxval = -1000000000;
    do {
        // calc;
        int sum = a[0];
        for (int i=0; i<op.size(); i++) {
            sum = calc(sum, a[i+1], op[i]);
        }
        minval = min(minval, sum);
        maxval = max(maxval, sum);
    } while(next_permutation(op.begin(), op.end()));
    
    cout << maxval << '\n';
    cout << minval << '\n';
    return 0;
}