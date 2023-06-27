#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//-13
//11011
//=-32+16+4-2+1

void go(int n) {
    if(n==0) {
        return;
    }
    if (n%2 == 0) { //even
        go(-(n/2));
        printf("0");
    } else { // odd
        if (n > 0) {
            go(-(n/2));
        } else {
            go((-n+1)/2);
        }
        printf("1");
    }
}
int main(){
    int n;
    scanf("%d\n", &n);
    if (n==0) {
        printf("0\n");
    } else {
        go(n);
    }
    return 0;
}