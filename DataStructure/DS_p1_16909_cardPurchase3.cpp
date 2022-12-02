#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N : card num ( 1 <= N <= 1000000 )
# A : ability ( 1 <= A <= 1000000 )

# num of way to purchase 
#    O(N + N-1 + N-2 + .... 1) = O(N*(N-1)/2) = O(N^2)
# sum : O(N)
# total : O(N^2) * O(N)

# (A[i]==max)sect num*A[i] - (A[i]==min)sect num*A[i]
#
#       <-------->     [1,4] : 4*(4+1)/2 = 10
# i    : 1 2  3  4 5 6
# A[i] : 3 1 (4) 2 5 1
#        <-->          [1,2] : 2*(2+1)/2 = 3
#               <->    [4,4] : 1*(1+1)/2 = 1
# loc where 3 is max : 1~4-th nums
# section nums : [1,4] - [1,3] - [4,4] = 10-3-1=6
# (1,1) : [3] = 0
# (1,2) : [3,1] = 2
# (1,3) : [3,1,4] = 3
# (1,4) : [3,1,4,2] = 3
# (1,5) : [3,1,4,2,5] = 4
# (1,6) : [3,1,4,2,5,1] = 4
# (2,2) : [1] = 0
# (2,3) : [1,4] = 3
# (2,4) : [1,4,2] = 3
# (2,5) : [1,4,2,5] = 4 
# (2,6) : [1,4,2,5,1] = 4
# (3,3) : [4] = 0
# (3,4) : [4,2] = 2
# (3,5) : [4,2,5] = 3
# (3,6) : [4,2,5,1] = 4
# (4,4) : [2] = 0
# (4,5) : [2,5] = 3
# (4,6) : [2,5,1] = 4
# (5,5) : [5] = 0
# (5,6) : [5,1] = 4
# (6,6) : [1] = 0   (total:50)
# i    : 1 2  3  4 5 6
# A[i] : 3 1 (4) 2 5 1
# A[1] : Max(3)*2 - Min(3) = 3
# A[2] : Max(1)*1 - Min(1)*[1~5]-[1~1]-[3~5]
#        1 - 1*(5*6/2-1-3*4/2) = 1-22
# A[3] : Max(4)*[1~4]-[1~2]-[4~4] - Min(4)*1
#        4*(4*5/2-2*3/2-1) -4 = 4*(6-1)
# A[4] : Max(2)*[1~1]-Min(2)*[3~5] = 2*(1-4)
# A[5] : Max(5)*[1~6]-Min(5)*[1] = 5*(21-10-1-1)
# A[6] : Max(1)*1 - Min(1)*[3~6]=1*(1-10-6)
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
long long calc(long long n) { // case num [1~n]
    return n*(n+1)/2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n; // num of card
    vector<int> a(n+1); // ability
    vector<int> lg(n+1, 0); // left greater
    vector<int> rg(n+1, n+1); // right greater
    vector<int> ls(n+1, 0); // left smaller
    vector<int> rs(n+1, n+1); // right smaller
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    { // --->
        stack<pair<int,int>> sg, ss; // stack greater, smaller
        sg.push(make_pair(1, a[1])); // first: index, second: value
        ss.push(make_pair(1, a[1]));
        for (int i=2; i<=n; i++) {
            //printf("i: %d (size:%d, a[%d]:%d >= %d)\n", i, sg.size(), i, a[i], sg.top().second);
            while (!sg.empty() && a[i] >= sg.top().second) {
                //printf(" > rg[%d] = %d\n", sg.top().first, i);
                rg[sg.top().first] = i;
                sg.pop();
                //printf(" > sg.pop()\n");
            }
            sg.push(make_pair(i, a[i]));
            //printf(" >> sg.push(%d, %d) \n", i, a[i]);

            //printf("i: %d (size:%d, a[%d]:%d >= %d)\n", i, sg.size(), i, a[i], sg.top().second);
            while (!ss.empty() && a[i] <= ss.top().second) {
                //printf(" > rs[%d] = %d\n", ss.top().first, i);
                rs[ss.top().first] = i;
                ss.pop();
                //printf(" > ss.pop()\n");
            }
            ss.push(make_pair(i, a[i]));
            //printf(" >> ss.push(%d, %d) \n", i, a[i]);
        }
    }
    {
        // <---
        stack<pair<int,int>> sg, ss; // stack greater, smaller
        sg.push(make_pair(n, a[n]));
        ss.push(make_pair(n, a[n]));
        for (int i=n-1; i>=1; i--) {
            while (!sg.empty() && a[i] > sg.top().second) {
                lg[sg.top().first] = i;
                sg.pop();
            }
            sg.push(make_pair(i, a[i]));
            while (!ss.empty() && a[i] < ss.top().second) {
                ls[ss.top().first] = i;
                ss.pop();
            }
            ss.push(make_pair(i, a[i]));
        }
    }
    long long ans = 0;
    //    3 1 (4) 2 5 1
    //    <-------->  [1,4]
    //    <-->        [1,2]
    //            <-> [4]
    //lg: 0 1 (0) 3 0 5 -> l = 0+1 = 1
    //rg: 3 3 (5) 5 7 7 -> r = 5-1 = 4  
    //ls: 0 0 (2) 2 4 0 -> l = 2+1 = 3
    //rs: 2 6 (4) 6 6 7 -> r = 4-1 = 3
    for (int i=1; i<=n; i++) {
        int l = min(i, lg[i]+1); 
        int r = max(i, rg[i]-1);
        // [1,4] when i==3,
        //printf("[i:%d](+) [%d, %d]\n", i, l, r);
        long long len = r-l+1;
        ans += (calc(len) - calc(r-i) - calc(i-l)) * a[i];
    }
    for (int i=1; i<=n; i++) {
        int l = min(i, ls[i]+1);
        int r = max(i, rs[i]-1);
        // [3,3] when i==3,
        //printf("[i:%d](-) [%d, %d]\n", i, l, r);
        long long len = r-l+1;
        ans -= (calc(len) - calc(r-i) - calc(i-l)) * a[i];
    }
    cout << ans << '\n';
    return 0;
}
