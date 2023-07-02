#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// d[n] = min num when representing sum with squarenums

// d[n] = min(d[n], d[n-i^2] + 1) , 1<=i , 0<= n-i^2
// d[0] = 0

// teacher
// d[n] = min(d[n-i^2] + 1),  1^2 <= i^2 <= N

#include <iostream>
#include <vector>
using namespace std;
int d[100001];

int main()
{
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        d[i] = i;
        // n * O(root n)
        for (int j=1; j*j <= i; j++) {
            if (d[i] > d[i-j*j] + 1) {
                d[i] = d[i-j*j]+1;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
} 