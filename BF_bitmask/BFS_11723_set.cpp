//# I've attended the code.plus class (https://code.plus/)
//# And I've referred it's codes
//# And core parts can be come fully from the class.

// add: | (1 << x)
// remove: S & ~(S & (1 << x))
// check: & (1 << x)
// all : 2^21 - 1 : (1<<N)-1
// empty : 0
// toggle : ^1

// A << B : A*2^B
// A >> B : A/(2^B)

// 2^N : (1<<N)

// bitmask : integer : time/space
// int: 32bit : 2^32
// N : 0 ~(N-1)

#include <cstdio>
#include <cstring>
using namespace std;
char b[111];
int main() {
    int n = 20;
    int m;
    scanf("%d", &m);
    int s = 0;
    int x;
    while (m--) {
        scanf("%s", b);
        if (!strcmp(b, "add")) {
            scanf("%d", &x); x--;
            s = (s | (1 << x));
        } else if (!strcmp(b, "remove")) {
            scanf("%d", &x); x--;
            s = ( s & ~(1 << x));
        } else if (!strcmp(b, "check")) {
            scanf("%d", &x); x--;
            int res = (s & (1 << x));
            if (res) {
                puts("1");
            } else {
                puts("0");
            }
        } else if (!strcmp(b, "toggle")) {
            scanf("%d", &x); x--;
            s = (s ^ (1<<x));
        } else if (!strcmp(b, "all")) {
            s = (1<<n) - 1;
        } else if (!strcmp(b, "empty")) {
            s = 0;
        }
    }
    return 0;
}