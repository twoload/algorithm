#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 9! = ok

// a[] = <(0),>(1)....
// check
// a[] : save the number
// go(n, i)
// if ok
//    i == n-1      
// if ng
//    i >= n  
// if next
//    for(int i=0; i<=9; i++)
//       visited[i] check
//       a[]
//       go(n, i+1)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
char a[20];
vector<string> ans;
bool check[10];
bool good(char x, char y, char op) {
    for (int i=0; i<n; i++) {
        if (op == '<') {
            if (x > y) return false;
        } else if (op == '>') {
            if (x < y) return false;
        }
    }
    return true;    
}
void go(int index, string num) {
    if (index == n+1) {
        ans.push_back(num);
        return;
    }
    for (int i=0; i<=9; i++) {
        if (check[i]) continue;
        if (index == 0 || good(num[index-1], i+'0', a[index-1])) {
            check[i] = true;
            go(index+1, num+to_string(i));
            check[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    go(0, "");
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
}

