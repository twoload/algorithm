#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1. array A is after array B in dictionary order
// 2. (i,j) : A[i] < A[j] (1<=i,j<=N)
// About the problem with several conditions,
//       consider only first condition 

// A[i] < A[j] : topology sort

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int disp(const char* name, vector<int>& a)
{
    printf("%s: ", name);
    for(int i=0; i<a.size(); i++)
        printf("%d ", a[i]);
    printf("\n");

}
vector<int> tsort(vector<vector<int>> &g) { // adjacent list
    int n = g.size();
    vector<int> ind(n);
    for (int i=0; i<n; i++) {
        for (int j : g[i]) {
            ind[j] += 1; // to find the points not to be called (start points)
        }
    }
    vector<int> order;
    queue<int> q;
    for (int i=0; i<n; i++) {
        if (ind[i] == 0) {
            q.push(i); // push start points
            order.push_back(i); // result
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : g[x]) {
            ind[y] -= 1;
            if (ind[y] == 0) { // if this point is not referred,
                q.push(y);
                order.push_back(y);
            }
        }
    }
    return order;
}
bool go(int k, vector<int>& b, vector<int> &order, vector<vector<int>> &g) {
    int n = b.size();
    vector<int> a(n);
    //disp("go order:", order);
    for (int x : order) { // from the end
        //printf("x:%d\n", x);
        a[x] = 2000000000;
        for (int y : g[x]) { // a[x] < a[y]
            //printf("y:%d\n", y);
            //printf("(x:%d) %d = min(a[%d]:%d, a[%d]-1:%d)\n",
            //    x, min(a[x], a[y]-1),x,a[x],y,a[y]-1);
            a[x] = min(a[x], a[y]-1);
            //disp("a min(a[x],a[y]-1)", a);
        }
        //disp("a after for", a);
        if (x < k) { // from cond 2
            if (b[x] > a[x]) {
                //disp("false a:", a); 
                //printf("(x:%d) b[%d]:%d > a[%d]:%d return false\n", x, x,b[x], x,a[x]);
                return false;
            }
            a[x] = b[x];
            //printf("(x:%d) %d = a[%d] = b[%d]\n", x, a[x], x, x);    
            //disp("a (x < k)", a);
        }
        if (a[x] <= 0) {
            //disp("false a:", a);
            //printf("a[%d]:%d<=0 return false\n", x, a[x]);
            return false;
        }
    }
    //disp("go a", a);
    //disp("go b", b);
    for (int i=0; i<n; i++) { // check if condition 2 met or not
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> gr(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        cin >> b[i]; // b input
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        g[u].push_back(v);  // forward
        gr[v].push_back(u); // reverse
    }

    vector<int> order;
    order = tsort(g); // topology sort : DAG 
    //disp("order", order);
    if (order.size() != n) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = 0;
    int left = 0;
    int right = n-1;
    reverse(order.begin(), order.end()); //?
    //printf("reverse order\n");
    //disp("order", order);
    // find k's location with topology sort
    while (left <= right) {
        int mid = (left + right) / 2;
        //printf("mid:%d\n", mid);
        if (go(mid, b, order, g)) { // k's location = mid
            left = mid + 1;
            ans = max(ans, mid);
            //printf("ans(%d) = max(ans,mid)(%d,%d)\n",ans,ans,mid);
        } else {
            right = mid - 1;
            //printf("right(%d) = mid(%d)-1\n",right,mid);
        }
    }
    //disp("order after go", order);
    reverse(order.begin(), order.end());//?
    //printf("reverse order\n");
    //disp("order", order);

    vector<int> a(n);
    for (int x : order) {
        //printf("x:%d (ans:%d)\n", x, ans);
        a[x] = 1;
        for (int y : gr[x]) { // a[x] > a[y]
            //printf("y:%d\n", y);
            a[x] = max(a[x], a[y]+1);
            //disp("a max(a[x],a[y]+1)", a);
        }
        if (x < ans) {
            a[x] = b[x]; //ans = k
            //printf("x < ans : %d < %d\n", x, ans);
            //disp("a (x<ans)", a);
        } else if (x == ans) { // ans = k
            //printf("x == ans : %d == %d\n", x, ans);
            a[x] = max(b[x]+1, a[x]);
            //disp("a (x==ans)", a);
        }
    }
    //disp("a", a);
    for (int i=0; i<n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}