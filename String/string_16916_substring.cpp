#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    
    if (strstr((char*)s.c_str(), (char*)p.c_str()) == NULL) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
    return 0;
}