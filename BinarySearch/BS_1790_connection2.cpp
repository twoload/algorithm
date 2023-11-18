// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n, k;
int get_length(int n) {
    // 1~9 (9-1+1)*1
    // 10~99 (99-10+1)*2
    // 100~999 (999-100+1)*3
    int length = 0;
    for (int start=1, len=1; start<=n; start*=10, len++) {
        int end = start*10-1;
        if (end > n) {
            end = n;
        }
        length += ((end-start)+1)*len;
    }
    return length;
}
char go(int start, int end) {
    int pos;
    while (start <= end) {
        int mid = (start+end)/2;
        int length = get_length(mid);
        if (length < k) {
            start = mid + 1;
        } else {
            pos = mid;
            end = mid - 1;
        }
    }
    int c = get_length(pos);
    string str = to_string(pos);
    return str[str.size()-1-(c-k)];
}

int main() {
    cin >> n >> k;
    if (get_length(n) < k) {
        cout << -1 << '\n';
        return 0;
    }
    cout << go(1, n) << '\n';
    return 0;
}