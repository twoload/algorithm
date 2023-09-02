#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// create graph 
// a[n][m] : n<2000, m<2000
// A-C : A->C, C->A

// 0->1
// 1->2
// 2->3
// ...

// dfs
// check
//   0->1
//   1->2
//   ...

// O(n) * O(dfs(n) = nm)
// 8000000000

// teacher

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool a[2000][2000];  // adjcent matrix
vector<int> g[2000]; // adjacent linked list
vector<pair<int,int>> edges; // edge linked list
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        edges.push_back({from, to});
        edges.push_back({to, from});
        g[from].push_back(to);
        g[to].push_back(from);
        a[from][to] = a[to][from] = true;
    }
    m *= 2;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            // A -> B
            int A = edges[i].first;
            int B = edges[i].second;

            // C -> D
            int C = edges[j].first;
            int D = edges[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            // B->C
            if (!a[B][C]) {
                continue;
            }
            // D->E
            for (int E : g[D]) {
                if (A == E || B == E || C == E || D == E) {
                    continue;
                }
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
} 