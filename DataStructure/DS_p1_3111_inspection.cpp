#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.


# T : len 300,000
# A : len 25
# find once : O(T*A)
# fine T-th : = find Once = O(T*A) if find from removed one

# Use stack
# A = abc
# T = fabaabc bc abccd

# L = fababc > faba > fababc > fab > move to R > f > move to R
# R = dccba > dc > recv from L > dcba > d > df
# ans = fd
#endif

#include <cstdio>
#include <cstring>
using namespace std;
char l[300001];
char r[300001];
int ln = 0;
int rn = 0;
char a[31];
char ar[31];
char b[300001];
int n, m;
bool check(int where) {
    char *stack = l; // --->
    int len = ln;
    char *str = ar;
    if (where == 1) { // <---
        stack = r;
        len = rn;
        str = a;
    }
    if (len-n < 0){ // n: len of a, len should >= n
        return false;
    }
    // stack : when pop data, order is opposite
    // ex. stack = l = abc
    //     1st pop : c
    //     2nd pop : b
    //     3rd pop : a
    // so compare ar

    // where 0: ---> , l, ar
    // where 1: <--- , r, a
    for (int i=0; i<n; i++) {
        if (stack[len-i-1] != str[i]) {
            return false; // diff
        }
    }
    // remove len n from the stack
    if (where == 0) { // --->
        ln -= n;
    }
    else { // <---
        rn -= n;
    }
    return true;
}

int main() {
    scanf("%s",a);
    n = strlen(a);
    for (int i=0; i<n; i++) {
        // ar[0] = a[n-1]
        // ar[n-1] = a[0]
        ar[i] = a[n-i-1]; // reverse a
    }
    scanf("%s",b);
    m = strlen(b);
    int left = 0; // begin
    int right = m-1; // end
    int where = 0; //0: --> , 1: <--
    while (left <= right) {
        if (where == 0) {
            l[ln++] = b[left++];
        } else {
            r[rn++] = b[right--];
        }
        if (check(where)) {
            // if found, change direction to find
            where = 1-where; // 0->1, 1->0
        }
    }
    for (int i=ln-1; i>=0; i--) {
        r[rn++] = l[i]; // move from l to r
        check(1); // <---- inspection
    }
    for (int i=rn-1; i>=0; i--) {
        putchar(r[i]); // print from the end
    }
    printf("\n");
    return 0;
}