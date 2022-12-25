#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// two-way
// one-way
// cycle -> no cycle 
// two-way -> DAG (Directed acyclic graph)

// if graphs doesn't have cycle with one-way lines -> YES
// if graphs have cycle with one-way lines  -> NO
//    two-way -> we need to select a direction not to make cycle

// two-way graph
// min(u,v) -> max(u,v) : no cycle
// 1 -> 2
// | X  |
// v    v
// 4 <- 3

// 1. if there is no one-way graphs
//    connect two-way lines as size order
// 2. if there is one-way graphs
//    one-way graphs -> Topology sort
//    connect two-way lines as topology sort order
// as a result, if there is no cycle, YES. if there is, NO.


// In short, Are one-way lines cycle ? no cycle? -> YES/NO

// Floyd algorithm
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool d[111][111];
int main() {
    int n;
    cin >> n; // 2<= N <= 50 (city = vertex)
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // one-way line
            if (a[i][j] == 'Y' && a[j][i] == 'N') {
                d[i][j] = true;
            }
        }
    }
    // Floyd algorithm : O(n^3)
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (d[i][k] && d[k][j]) {
                    d[i][j] = true;
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (d[i][i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}



