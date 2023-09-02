#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 2147483547;
int w[20][20];


int calculate(vector<int> &d) {
    int sum = 0;
    bool ok = true;
    int n = d.size();
    for (int i=0; i<n-1; i++) {
        if (w[d[i]][d[i+1]] == 0) {
            ok = false;
        } else {
            sum += w[d[i]][d[i+1]];
        }
    }
    if (ok && w[d[n-1]][d[0]] != 0) {
        sum += w[d[n-1]][d[0]];
        return sum;
    }
    else {
        return inf;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    vector<int> d(n);
    for (int i=0; i<n; i++) {
        d[i] = i;
    }

    int ans = inf;
    do {
        if (d[0] != 0) break; //*****
        int temp = calculate(d);
        ans = min(temp, ans);
    } while(next_permutation(d.begin()+1, d.end())); // *****

    cout << ans << "\n";
    return 0;
}