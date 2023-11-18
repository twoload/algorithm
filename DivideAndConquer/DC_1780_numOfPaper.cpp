// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int a[2200][2200];

tuple<int,int,int> go(int sx, int ex, int sy, int ey) {
    if (ex-sx > 3 && ey-sy > 3) {
        int dx = (ex+1-sx)/3;
        int dy = (ey+1-sy)/3;
        auto r0 = go(sx,sx+dx-1,sy,sy+dy-1);
        auto r1 = go(sx,sx+dx-1,sy+dy,sy+2*dy-1);
        auto r2 = go(sx,sx+dx-1,sy+2*dy,sy+3*dy-1);
        auto r3 = go(sx+dx,sx+2*dx-1,sy,sy+dy-1);
        auto r4 = go(sx+dx,sx+2*dx-1,sy+dy,sy+2*dy-1);
        auto r5 = go(sx+dx,sx+2*dx-1,sy+2*dy,sy+3*dy-1);
        auto r6 = go(sx+2*dx,sx+3*dx-1,sy,sy+dy-1);
        auto r7 = go(sx+2*dx,sx+3*dx-1,sy+dy,sy+2*dy-1);
        auto r8 = go(sx+2*dx,sx+3*dx-1,sy+2*dy,sy+3*dy-1);
        if ((get<0>(r0)==1 && get<1>(r0)==0 && get<2>(r0)==0) &&
            (get<0>(r1)==1 && get<1>(r1)==0 && get<2>(r1)==0) &&
            (get<0>(r2)==1 && get<1>(r2)==0 && get<2>(r2)==0) &&
            (get<0>(r3)==1 && get<1>(r3)==0 && get<2>(r3)==0) &&
            (get<0>(r4)==1 && get<1>(r4)==0 && get<2>(r4)==0) &&
            (get<0>(r5)==1 && get<1>(r5)==0 && get<2>(r5)==0) &&
            (get<0>(r6)==1 && get<1>(r6)==0 && get<2>(r6)==0) &&
            (get<0>(r7)==1 && get<1>(r7)==0 && get<2>(r7)==0) &&
            (get<0>(r8)==1 && get<1>(r8)==0 && get<2>(r8)==0)) {
                return make_tuple(1,0,0);
            }
        if ((get<0>(r0)==0 && get<1>(r0)==1 && get<2>(r0)==0) &&
            (get<0>(r1)==0 && get<1>(r1)==1 && get<2>(r1)==0) &&
            (get<0>(r2)==0 && get<1>(r2)==1 && get<2>(r2)==0) &&
            (get<0>(r3)==0 && get<1>(r3)==1 && get<2>(r3)==0) &&
            (get<0>(r4)==0 && get<1>(r4)==1 && get<2>(r4)==0) &&
            (get<0>(r5)==0 && get<1>(r5)==1 && get<2>(r5)==0) &&
            (get<0>(r6)==0 && get<1>(r6)==1 && get<2>(r6)==0) &&
            (get<0>(r7)==0 && get<1>(r7)==1 && get<2>(r7)==0) &&
            (get<0>(r8)==0 && get<1>(r8)==1 && get<2>(r8)==0)) {
                return make_tuple(0,1,0);
            }
        if ((get<0>(r0)==0 && get<1>(r0)==0 && get<2>(r0)==1) &&
            (get<0>(r1)==0 && get<1>(r1)==0 && get<2>(r1)==1) &&
            (get<0>(r2)==0 && get<1>(r2)==0 && get<2>(r2)==1) &&
            (get<0>(r3)==0 && get<1>(r3)==0 && get<2>(r3)==1) &&
            (get<0>(r4)==0 && get<1>(r4)==0 && get<2>(r4)==1) &&
            (get<0>(r5)==0 && get<1>(r5)==0 && get<2>(r5)==1) &&
            (get<0>(r6)==0 && get<1>(r6)==0 && get<2>(r6)==1) &&
            (get<0>(r7)==0 && get<1>(r7)==0 && get<2>(r7)==1) &&
            (get<0>(r8)==0 && get<1>(r8)==0 && get<2>(r8)==1)) {
                return make_tuple(0,0,1);
            }
        int l = 0;
        int m = 0;
        int k = 0;
        l = get<0>(r0)+get<0>(r1)+get<0>(r2)+get<0>(r3)+get<0>(r4)+get<0>(r5)+get<0>(r6)+get<0>(r7)+get<0>(r8);
        m = get<1>(r0)+get<1>(r1)+get<1>(r2)+get<1>(r3)+get<1>(r4)+get<1>(r5)+get<1>(r6)+get<1>(r7)+get<1>(r8);
        k = get<2>(r0)+get<2>(r1)+get<2>(r2)+get<2>(r3)+get<2>(r4)+get<2>(r5)+get<2>(r6)+get<2>(r7)+get<2>(r8);
        return make_tuple(l,m,k);
    }
    else {
        int m=0;
        int l=0;
        int k=0;
        for (int i=sx; i<=ex; i++) {
            for (int j=sy; j<=ey; j++) {
                if (a[i][j] == -1) {
                    m += 1;
                } else if (a[i][j] == 0) {
                    l += 1;
                } else {
                    k += 1;
                }
            }
        }
        if (m==9) {
            return make_tuple(1,0,0);
        } else if (l==9) {
            return make_tuple(0,1,0);
        } else if (k==9) {
            return make_tuple(0,0,1);
        } else {
            return make_tuple(m,l,k);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    auto r = go(0,n-1,0,n-1);
    cout << get<0>(r) << '\n';
    cout << get<1>(r) << '\n';
    cout << get<2>(r) << '\n';
    return 0;
}