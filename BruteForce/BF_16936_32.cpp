#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i]; 
    }

    do {
        bool success = true;
        long long now = a[0];
        for (int i=1; i<n; i++) {
            long long next = a[i];
            if (next == now*2) {
                now = next;
            } else if (now%3==0 && next==now/3) {
                now = next;
            } else {
                success = false;
                break;
            }
        }
        if (success) {
            for (int i=0; i<n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
            break;
        }
#if 0
        for (int i=0; i<n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
#endif
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}