// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
using namespace std;
int n, k;

int get_length(int n) {
    int len = 0;
    for(int start=1, pos=1; start<=n; start*=10, pos+=1) {
        int end = 10*start-1;
        if (end > n) {
            end = n;
        }
        len += (end-start+1)*pos;
    }
    return len;
}
char go(int start, int end) {
    int pos = 0;
    while (start <= end) {
        int mid = (start+end)/2;
        if (get_length(mid) < k) {
            start = mid+1;
        } else {
            pos = mid;
            end = mid-1;
        }
    }
    int c = get_length(pos);
    string str = to_string(pos);
    return str[str.size()-1-(c-k)];
}

int main() {
    cin >> n >> k;
    //cout << get_length(8) << '\n';
    //cout << get_length(12) << '\n';
    if (get_length(n) < k) {
        cout << -1 << '\n';
        return 0;
    }
    cout << go(1, n) << '\n';
    return 0;
}