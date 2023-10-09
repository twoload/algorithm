#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

const long long limit = 1000000000LL;
int main() {
    long long s, t;
    cin >> s >> t;
    set<long long> check;
    queue<pair<long long, string>> q;
    q.push(make_pair(s, ""));
    check.insert(s);
    while (!q.empty()) {
        long long x;
        string str;
        tie(x, str) = q.front(); q.pop();
        if (x==t) {
            if (str.length() == 0) {
                str = "0";
            }
            cout << str << '\n';
            return 0;
        }
        if (0<= x*x && x*x <= limit && check.count(x*x) == 0) {
            q.push(make_pair(x*x, str+'*'));
            check.insert(x*x);
        }
        if (0<= x+x && x+x <= limit && check.count(x+x) == 0) {
            q.push(make_pair(x+x, str+'+'));
            check.insert(x+x);
        }
        if (0<= x-x && x-x <= limit && check.count(x-x) == 0) {
            q.push(make_pair(x-x, str+'-'));
            check.insert(x-x);
        }
        if (x!=0 && 0<= x/x && x/x <= limit && check.count(x/x) == 0) {
            q.push(make_pair(x/x, str+'/'));
            check.insert(x/x);
        }
    }
    cout << -1 << '\n';
    return 0;
}


#if 0
bool check[1000000001];

long long calc(long long i, char op) {
    if (op == '+') return i+i;
    if (op == '-') return 0;
    if (op == '*') return i*i;
    if (op == '/') {
        if (i == 0) {
            return -1;
        } else {
            return 0;
        }
    }
    return -1;
}

int main() {
    long long s, t;
    cin >> s >> t;
    queue<pair<long long, string>> q;
    q.push(make_pair(s, ""));
    check[s] = true;
    string ans = "";
    while (!q.empty()) {
        long long now = q.front().first;
        string opcodes = q.front().second;
        q.pop();
        if (now == t) {
            ans = opcodes;
            break;
        }
        char op = '+';
        long long next = calc(now, op);
        string opcodes_next = opcodes + op;
        if (check[next] == false) {
            check[next]=true;
            q.push(make_pair(next, opcodes_next));
        }
        op = '-';
        next = calc(now, op);
        opcodes_next = opcodes + op;
        if (check[next] == false) {
            check[next]=true;
            q.push(make_pair(next, opcodes_next));
        }
        op = '*';
        next = calc(now, op);
        opcodes_next = opcodes + op;
        if (check[next] == false) {
            check[next]=true;
            q.push(make_pair(next, opcodes_next));
        }
        op = '/';
        next = calc(now, op);
        opcodes_next = opcodes + op;
        if (next!= -1 && check[next] == false) {
            check[next]=true;
            q.push(make_pair(next, opcodes_next));
        }
    }
    if (s == t) {
        cout << 0 << '\n';
    } else if (ans == "") {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}
#endif