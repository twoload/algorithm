#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// check1. if find the answer, exit right away.
// plus1. 0~80 step => (improve) only blank 

int a[9][9];
bool found = false;
//vector<pair<int,int>> blank;
void print() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
bool valid(int x, int y, int val) {
    // row
    for (int i=0; i<9; i++) {
        if (a[x][i] == val) {
            return false;
        }
    }
    // colume
    for (int i=0; i<9; i++) {
        if (a[i][y] == val) {
            return false;
        }
    }
    // sub
    int sx = x / 3;
    int sy = y / 3;
    for (int i=sx*3; i<sx*3+3; i++) {
        for (int j=sy*3; j<sy*3+3; j++) {
            if (a[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}
void go(int index) {
    //printf("index: %d\n", index);
    if (index >= 81) {
        print();
        found = true;
        return;
    }
    int x = index / 9;
    int y = index % 9;
    bool ret = false;
    if (a[x][y] != 0) {
        go(index+1);
        if (found) {
            return;
        }
    } else {
        for (int i=1; i<=9; i++) {
            if (valid(x,y,i)) {
                a[x][y] = i;
                go(index+1);
                if (found) {
                    return;
                }
            }
        }
        a[x][y] = 0;
    }
}
int main() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> a[i][j];
        }
    }
    go(0);
    return 0;
}


