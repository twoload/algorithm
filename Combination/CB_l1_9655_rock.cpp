#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// rock: n (1<= n <=1000)
// pick 1 or 3
// 1st turn: SK = 0
// 2nd turn: CY = 1

// ex. 5
// SK (1,3) > CY (1,3) > SK(1,3)....
// d[n] : person to win at n-th
//      = !d[n-1]
//      = !d[n-3]
//      = !d[n-2]

// O(n)

// teacher
// rock:1,2,3 -> A:win
// rock:4 -> B:win
// rock:5,6,7 -> A:win
// rock:8 -> B:win
// so, rock: 4xm -> lose, not -> win

// P location
//   = location which Previous Player win
//     location which just player having turn win
// N location
//   = location which Next Player wins
//     location which player to have turn win

// W/L
// W: person who has turn this time win
// L: person who has turn this time lose

// can get rock 1,2,3 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W W W L W W W L W  W  W  L  W  W  W  L  W
//       \-/
//       \--/
//       \----/
// can get rock 1,3,4 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W W W W L W L  W  W  W  W  L  W  L  W
// can get rock 1,3,4 (person loses when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  W L W L W W W W L W  L  W  W  W  W  L  W  L
// can get rock 1,3 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W L W L W L W  L  W  L  W  L  W  L  W

// can get rock 1,4^k (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W W L W L W W  L  W  L  W  W  L  W
//       --------- ---------  -------------
// d[i]%5 == 0, 2 -> Lose

// mask i
// 22ea


#if 0// 9656
#include <iostream>
using namespace std;
bool d[1001];
// can get rock 1,3 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W L W L W L W  L  W  L  W  L  W  L  W
int main() {
    d[0] = false;
    for (int i=1; i<=1000; i++) {
        d[i] = false;
        if (i-1 >= 0 && d[i-1] == false) {
            d[i] = true;
        }
        if (i-3 >= 0 && d[i-3] == false) {
            d[i] = true;
        }
    }
    int n;
    cin >> n;
    cout << (d[n] ? "SK" : "CY") << '\n';
    return 0;
}
#endif

#if 0// 9656
#include <iostream>
using namespace std;
bool d[1001];
// can get rock 1,3 (person loses when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  W L
int main() {
    d[0] = true;//false;
    for (int i=1; i<=1000; i++) {
        d[i] = false;
        if (i-1 >= 0 && d[i-1] == false) {
            d[i] = true;
        }
        if (i-3 >= 0 && d[i-3] == false) {
            d[i] = true;
        }
    }
    int n;
    cin >> n;
    cout << (d[n] ? "SK" : "CY") << '\n';
    return 0;
}
#endif

#if 0// 9657 // rock game3
#include <iostream>
using namespace std;
bool d[1001];
// can get rock 1,3,4 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W W W W L W L  W  W  W  W  L  W  L  W
int main() {
    d[0] = false;
    for (int i=1; i<=1000; i++) {
        d[i] = false;
        if (i-1 >= 0 && d[i-1] == false) {
            d[i] = true;
        }
        if (i-3 >= 0 && d[i-3] == false) {
            d[i] = true;
        }
        if (i-4 >= 0 && d[i-4] == false){
            d[i] = true;
        }
    }
    int n;
    cin >> n;
    cout << (d[n] ? "SK" : "CY") << '\n';
    return 0;
}
#endif

#if 0//9658 // rock game4
#include <iostream>
using namespace std;
bool d[1001];
// can get rock 1,3,4 (person loses when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  W
int main() {
    d[0] = true;//false;
    for (int i=1; i<=1000; i++) {
        d[i] = false;
        if (i-1 >= 0 && d[i-1] == false) {
            d[i] = true;
        }
        if (i-3 >= 0 && d[i-3] == false) {
            d[i] = true;
        }
        if (i-4 >= 0 && d[i-4] == false){
            d[i] = true;
        }
    }
    int n;
    cin >> n;
    cout << (d[n] ? "SK" : "CY") << '\n';
    return 0;
}
#endif

#if 0// 9659 // rock game5
#include <iostream>
using namespace std;
// can get rock 1,3 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W L W L W L W  L  W  L  W  L  W  L  W
int main() {
    long long n;
    cin >> n;
    cout << (n%2==1 ? "SK" : "CY") << '\n';
    return 0;
}
#endif

#if 0 // 9660 // rock game6
#include <iostream>
using namespace std;
// can get rock 1,3,4 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W W W W L W L  W  W  W  W  L  W  L  W
//       -------------
int main() {
    long long n;
    cin >> n;
    cout << ((n%7!=0 && n%7!=2) ? "SK" : "CY") << '\n';
    return 0;
}
#endif

#if 0// 9661 // rock game7
#include <iostream>
using namespace std;
// can get rock 1,4^k (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// d[i]  L W L W W L W L W W  L  W  L  W  W  L  W
//       --------- ---------  -------------
// d[i]%5 == 0, 2 -> Lose
int main() {
    long long n;
    cin >> n;
    cout << ((n%5!=0 && n%5!=2) ? "SK" : "CY") << '\n';
    return 0;
}
#endif

//9662
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
const int masklen = 22; //6 (easy one)
// n (1<=n<=10^9)
// k (1<=k<=22)
// ex.
// 10 = n
// 2  = k = m
// 1,3  = moves[0]
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> moves(m);
    for (int i=0; i<m; i++) {
        cin >> moves[i];
    }
// can get rock 3 (person wins when he get last one)
// i   : 0 1 2 3 4 5 6 7 8 9 10 
// d[i]  L W L W L W L W L W L  (SK:W)(SK:L=CY:W)  
// bit   0 1 0 1 0 1 0 1 0 1 0        (SK:0=CY:1)
//       -------
    int mask= (1<<masklen)-1;
    //cout << "mask: " << bitset<30>(mask) << '\n';
    int ans = -1;
    map<int,int> last;
    vector<int> r;
    for (int i=0; i<=n; i++) { //20
// mask =  111111 (i=0)
// <<1    1111110 (i=0)
        mask <<= 1; 
        //cout << "mask: " << bitset<30>(mask) << '\n';
        ans += 1; // 0:CY wins
        for (int j : moves) { //1,3
            if ((mask & (1 << j)) == 0) { //L -> now W
                mask += 1;
                //cout << "mask: " << bitset<30>(mask) << '\n';
                ans -= 1; // 1:SK wins
                break;
            }
        }
// ans = 0 (-1+1)
// mask = 1111110 (i=0)
// &=   =  111110 (i=0)
        mask &= (1 << masklen) - 1;
        //cout << "mask: " << bitset<30>(mask) << '\n';
        if (last.count(mask)) { // find repetitive period
            int pLength = i - last[mask]; //period length
            int cnt = (n-i)/pLength; // if n-i < pLength, cnt = 0
            i += cnt*pLength; // calc i fast
            ans += cnt*(ans-r[last[mask]]); // increased value during period * cnt
        }
// last[111110] = 0
        last[mask] = i;
        //cout<< "last[" << bitset<30>(mask) <<"] = " << i << '\n';
        r.push_back(ans);
        //cout <<"r: ";
        //for(int l=0; l<r.size(); l++) {
        //    cout << r[l] << " ";
        //}
        //cout << "\n";
    }
    cout << ans << '\n';
    return 0;
}