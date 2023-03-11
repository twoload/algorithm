#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// max(str, int)
// plus my value when i finish the quest
// ...

// d[n][str][int] : max num of quest which I can finish when str, int are given
//                  n : order
// sort in advance

// teacher
// (1,1) -> 6 point -> (7(+6),1),(6,2),(5,3),...
//       -> 6 point -> 2 point.... 4point later...

// d[s][i] : s, i = is it possible?
// remaining point
// FreePoint[s][i] = remaining point when we finish all quests with s, i
// strength up     (s-1, i) -> now (s,i)
//   1) d[s-1][i] = true
//   2) FreePoint[s-1][i] > 0
//   3) s-1 >= 1  because init condition = (1,1)
// ingelligence up (s, i-1) -> now (s,i)
//   1) d[s][i-1] = true
//   2) FreePoint[s][i-1] > 0
//   3) i-1 >= 1

#include <iostream>
#include <vector>
using namespace std;
struct Quest {
    int s,i,p;
};
 
// STR,INT,PNT <= 1000
bool d[1001][1001]; // is it possible with str, int
int p[1001][1001]; // remaining stat with str, int
int main() {
    int n;
    cin >> n;
    vector<Quest> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].s >> a[i].i >> a[i].p;
    }
    int ans = 0;
    for (int s=1; s<=1000; s++) {
        for (int i=1; i<=1000; i++) {
            int cnt = 0;
            p[s][i] = 2-s-i; // remining stat : 1,1 = 2 - s - i
            for (int k=0; k<n; k++) {
                if (a[k].s <= s || a[k].i <= i) { // can quest
                    p[s][i] += a[k].p;
                    cnt += 1;
                }
            }
            if (s == 1 && i == 1) { // init
                d[s][i] = true;
            } else if (s > 1 && d[s-1][i] && p[s-1][i] > 0) {
                d[s][i] = true; // strength
            } else if (i > 1 && d[s][i-1] && p[s][i-1] > 0) {
                d[s][i] = true; // intelligence
            }
            if (d[s][i]) { // only when true
                ans = max(ans, cnt); // update
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

