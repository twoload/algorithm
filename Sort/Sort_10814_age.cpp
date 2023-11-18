// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
struct Member {
    int age;
    string name;
};
bool cmp(const Member&u, const Member&v) {
    return u.age < v.age;
}

int main() {
    int n;
    cin >> n;
    vector<Member> a(n);
    for (int i=0; i<n; i++) {
        int x;
        string y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    stable_sort(a.begin(), a.end(), cmp);
    for (Member p: a) {
        cout << p.age << ' ' << p.name << '\n';
    }
    return 0;
}