// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct Student{
    int kor;
    int eng;
    int math;
    string name;
};

bool cmp(const Student& u, const Student& v) {
    return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
}

int main() {
    int n;
    cin >> n;
    vector<Student> a(n);
    for (int i=0; i<n; i++) {
        string s;
        int k, e, m;
        cin >> s >> k >> e >> m;
        a[i] = {k,e,m,s};
    }
    sort(a.begin(), a.end(), cmp);
    for (Student& p : a) {
        cout << p.name << '\n';
    }

    return 0;
}