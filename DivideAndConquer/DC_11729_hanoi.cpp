// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int mid, int to) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    // n-1 : (1)->(2)
    hanoi(n-1, from, to, mid);
    // 1(the lengest) : (1)->(3)
    cout << from << ' ' << to << '\n';
    // n-1 : (2)->(3)
    hanoi(n-1, mid, from, to);
}

int main() {
    int n;
    cin >> n;
    cout << (int)pow(2, n)-1 << '\n';
    hanoi(n, 1, 2, 3);
    return 0;
}