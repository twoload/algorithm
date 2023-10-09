#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> ans;
vector<int> a(101);
vector<int> op(4);

int calc(int x, int y, int op) 
{
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
    } else {
        return 0;
    }
}

// 0: +, 1:-, 2:*, 3:/
void go(int index, int sum) 
{
    if (index > n-2) {
        ans.push_back(sum);
        return;
    }
    for (int i=0; i<4; i++) {
        if (op[i] > 0) {
            --op[i];
            //printf("index:%d = %d, %d, %d\n", index, sum, a[index+1], i);
            go(index+1, calc(sum, a[index+1], i));
            ++op[i];
        }
    }   
    return;
}


int main() 
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<4; i++) {
        cin >> op[i];
    }
    int minval = 1000000000;
    int maxval = -1000000000;

    go(0, a[0]);
    maxval = *max_element(ans.begin(), ans.end());
    minval = *min_element(ans.begin(), ans.end());
    cout << maxval << '\n';
    cout << minval << '\n';
    return 0;
}