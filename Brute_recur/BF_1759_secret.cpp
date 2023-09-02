#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// teacher
// go(n, alpha, password, i)
// a c i s t w : c = 2^c
// O
// X
//1) find the solution
//2) impossible case
//   i >= size of alpha
//3) next case
//   i use:   
//     go(n, alpha, password+alpha[i], i+1)
//   i no use: 
//     go(n, alpha, password, i+1)

bool check(string &password) {
    int ja = 0;
    int mo = 0;
    for (char x : password) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            mo += 1;
        } else {
            ja += 1;
        }
    }
    return ja >= 2 && mo >= 1;
}

void go(int n, vector<char> &alpha, string password, int i) {
    if (password.length() == n) {
        if (check(password)) {
            cout << password << '\n';
        }
        return;
    }
    if (i == alpha.size()) return;
    go(n, alpha, password+alpha[i], i+1);
    go(n, alpha, password, i+1);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<char> a(m);
    for (int i=0; i<m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    go(n, a, "", 0);
    return 0;
}

#if 0
int l, c;
int a[16];
int b[16];

void go(int n, int moeum, int jaeum) {
    if (n >= c) {
        if (moeum >= 1 && jaeum >= 2){
            //print
            return;
        }
        return;
    }
        
    
}

int main()
{
    
    cin >> l >> c;
    for (int i=0; i<c; i++) {
        cin >> a[i];
    }
    sort(a, a+c);
    go(0, 1, 2);
    return 0;
}
#endif