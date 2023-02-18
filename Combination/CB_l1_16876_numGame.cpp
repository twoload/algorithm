#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 0<= n <= 10^4 = 10000
// 0<= m <= 100

// 0000 0

// n:integer, m:turn
// d[n][m] : who wins at n, m
// d[0][0] = 1 (0:koosaga, 1:cubelover)
// d[i][j] 
//         = d[i-1][j-1]
//         = d[i-10][j-1]
//         = d[i-100][j-1]
//         = d[i-1000][j-1]
// ...
// 1       if all are 0
// 0       if at least one is 1

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string original;
int total;
int d[10000][101];
// turn: 1~total
int go(string num, int turn) {
    if (turn == total+1) { // finished
        if (num > original) {
            return 1;
        } else {
            return 0;
        }
    }
    int x = stoi(num); //string 2 integer
    int &ans = d[x][turn]; // memoization
    if (ans != -1) {
        return ans;
    }
    // turn 1    2    3    4
    //      koo  cube koo  cube
    // init value
    if (turn % 2 == 0) { 
        ans = 1; // 1->0 (cube: purpose = make ans 0)
    } else {
        ans = 0; // 0->1 (koo: purpose = make ans 1)
    }
    for (int i=0; i<4; i++) { //all cases for 4 pos
        string temp = num;
        if (temp[i] == '9') {
            temp[i] = '0';
        } else {
            temp[i] += 1;
        }
        if (turn % 2 == 0) {
            // cube
            // If even there is one 0, cube wins.
            // If all are 1, koo wins
            ans &= go(temp, turn+1); 
        } else {
            // koo
            // If there is at least one 1, koo wins.
            // If all are 0, cube wins
            ans |= go(temp, turn+1);
        }
    }
    return ans;
}
int main() {
    cin >> original >> total;
    memset(d,-1,sizeof(d)); //init
    if (go(original, 1)/*turn=1*/ == 1) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}
