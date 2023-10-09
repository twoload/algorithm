#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

// domino!!!
// domino (1,9) only can be used once

int a[9][10] = {0};
bool c[9][10] = {0}; // row
bool c2[9][10] = {0}; // column
bool c3[9][10] = {0}; // squre
int dx[] = {0,1};
int dy[] = {1,0};
bool domino[10][10] = {0};

pair<int,int> convert(const string& s) {
    int a, b;
    return make_pair(s[0]-'A', s[1]-'1');
}
// square: 0,1,2,3,4,5,6,7,8
int square(int x, int y) {
    return (x/3)*3+(y/3);
}
// not used num in row,col,square
int can(int x, int y, int num) {
    return !c[x][num] && !c2[y][num] && !c3[square(x,y)][num];
}
// what : True/False
//        update num in row, col, square 
void check(int x, int y, int num, bool what) {
    c[x][num] = what;
    c2[y][num] = what;
    c3[square(x,y)][num] = what;
}
// check out of range
bool check_range(int x, int y) {
    return 0<=x && x<9 && 0<=y && y<9;
}

void print() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

// go(0) -> go(81) : visit in order
bool go(int z) {
    //printf("index: %d\n", z);
    //print();
    if (z >= 81) {
        return true;
    }

    int x = z / 9;
    int y = z % 9;
    if (a[x][y]) {
        return go(z+1);
    }
    for (int k=0; k<2; k++) {
        int x2 = x + dx[k];
        int y2 = y + dy[k];     

        if (!check_range(x2, y2)) continue;
        if (a[x2][y2]) continue;
        for (int i=1;i<=9;i++) {
            for (int j=1;j<=9;j++) {
                if (i == j) continue;
                if (domino[i][j]) continue;
                if (can(x,y,i) && can(x2,y2,j)) {
                    check(x,y,i,true);
                    check(x2,y2,j,true);
                    a[x][y] = i;
                    a[x2][y2] = j;
                    domino[i][j] = true;
                    domino[j][i] = true;
                    if (go(z+1)) return true;
                    check(x,y,i,false);
                    check(x2,y2,j,false);
                    a[x][y] = 0;
                    a[x2][y2] = 0;
                    domino[i][j] = false;
                    domino[j][i] = false;
                }
            }
        }
    }
    return false;
}


int main() {
    int cnt = 0;
    while (true) {
        int m;
        cin >> m;
        if (m == 0) {
            break;
        }
        memset(c, 0, sizeof(c));
        memset(c2, 0, sizeof(c2));
        memset(c3, 0, sizeof(c3));
        memset(a, 0, sizeof(a));
        memset(domino, false, sizeof(domino));
        for (int i=0; i<m; i++) {
            int n1, n2;
            string s1, s2;
            cin >> n1 >> s1 >> n2 >> s2;
            int x1, y1, x2, y2;
            tie(x1,y1) = convert(s1);
            tie(x2,y2) = convert(s2);
            a[x1][y1] = n1;
            a[x2][y2] = n2;
            check(x1,y1,n1,true);
            check(x2,y2,n2,true);
            domino[n1][n2] = domino[n2][n1] = true;
        }
        for (int i=1; i<=9; i++) {
            int x, y;
            string s;
            cin >> s;
            tie(x,y) = convert(s);
            a[x][y] = i;
            check(x,y,i,true);
        }
        //print();
        go(0);
        cout << "Puzzle " << ++cnt << '\n';
        print();
    }
    return 0;
}