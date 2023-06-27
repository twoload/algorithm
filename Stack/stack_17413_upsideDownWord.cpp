#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <queue>
using namespace std;

// if '<'
//    '<' + print + '>'
// else
//     stack push
//     ' ' or '\n'
//     stack pop & print

void print(stack<char>& s)
{
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

int main()
{
    string str;
    getline(cin, str);
    bool tag = false;
    stack<char> s;
    for (char ch : str) {
        if (ch == '<') {
            print(s);
            tag = true;
            cout << ch;
        } else if (ch == '>') {
            tag = false;
            cout << ch;
        } else if (tag) {
            cout << ch;
        } else {
            if (ch == ' ') {
                print(s);
                cout << ch;
            } else {
                s.push(ch);
            }
        }
    }
    print(s);
    cout << '\n';
    return 0;
}
