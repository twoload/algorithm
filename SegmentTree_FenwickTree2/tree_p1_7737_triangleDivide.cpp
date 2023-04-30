#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// T[n] : num of triangle-division of n-gon
// T[n] = sum (T[i] * T[n-i+1])
// 2 <= i <= n-1
// T[0] = T[1] = 0
// T[2] = 1

// DP : T[n] ,  2<=i<=n-1  : n^2 dynamic

// Catalan number
// Cn+1 = sum(Ci*Cn-i) (0<=i<=n)

// T[n] = sum(T[i]*T[n-i+1]), (0<=i<=n) because T[0]=T[1]=0
// T[n-1] = sum(T[i]*T[n-i])
// Cn+1 = sum(Ci*Cn-i)
// ->
// T[n-1]=Cn+1
// T[n] = Cn+2
// Cn = (2n) - (2n) =  1/n+1 * (2n)
//      (n )   (n+1)           (n )
// Cn+1 = 2*(2n+1)/n+2 * Cn
// Cn+1/Cn = 1/(n+2)*(2n+2 n+1) / 1/(n+1)*(2n n)
//         = 1/(n+2)*(2n+2)!/(n+1)!*(n+1)!  /  1/(n+1)*2n!/n!*n!
//         = 2*(2n+1)/n+1

// Cn+1 = 2*(2n+1)/n+2 * Cn
// if n is given, T3+T4+T5+...+Tn % m
//    if m is a prime number, 
//       A/B mod C = (A*B^(C-2)) mod C
//    but m is not a prime number, so we cannot use this method.

// tree[i] : num of i-th prime number
// segment tree's multiply -> O(lgN) for multiply
// -> time complexity = O(nlogn)

/**
 *  n = 6
 * 
 *  idx    = 0,1,2,3,4,5
 *  primes = 2,3,5,7,11,13
 *             idx
 *  factors[2]  0
 *  factors[3]  1
 *  factors[4]  0
 *  factors[5]  2
 *  factors[6]  0,1
 *  factors[7]  3
 *  factors[8]  0
 *  factors[9]  1
 *  factors[10] 0,2
 *  factors[11] 4
 *  factors[12] 0,1
 *  factors[13] 5
 * 
 *           0-5 (1)
 *        /          \
 *      0-2(2)      3-5(3)
 *      /  \         /  \
 *  0-1(4) 2(5) 3-4(6) 5(7)
 *  / \         / \
 *  0  1       3   4
 * (8)(9)     (10)(11)
 * 
 * 2,1   factors[2]:0 > a[0]+=cnt*diff = 1 > 2^1 = 2     (8):2>(4):2>,,,
 * 1,1   
 * 2,-1  factors[2]:0 > a[0]+=cnt*diff = 1-1=0 > 2^0 = 1 (8):1>(4):1>,,,
 * 
 * 2,1   a[0]+=1 > 2^1 = 2
 * 3,1   a[1]+=1 > 3^1 = 3
 * 3,-1  a[1]+=-1> 3^0 = 1
 * 
 * C0 = 1
 * C1 = 2*(2n+1)/(n+2) = T3
 * C2 = 2*(2n+1)/(n+2) *C1 = T4
 * 
 */ 


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long mod;
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index > end || index < start) {
        return;
    }
    if (start == end) {
        tree[node] = diff;
        return;
    }
    update(tree, node*2, start, (start+end)/2, index, diff);
    update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    tree[node] = (tree[node*2] * tree[node*2+1]) % mod;
}
long long calc(int num, int y) { // num^y
    long long x = (long long)num;
    long long ans = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        y = y/2;
    }
    //cerr << "calc " << num << '^' << y << '=' <<  ans <<'\n';
    return ans;
}
void multiply(vector<int> &a, vector<long long> &tree, vector<int> &primes, vector<vector<int>> &factors, int num, int diff) {
    //cerr << "multply " << num << ' ' << diff << '\n';
    if (num == 1) return;
    int x = num;
    for (int index : factors[num]) {
        int p = primes[index];
        int cnt = 0;
        while (x >= p && x%p == 0) {
            cnt += 1;
            x /= p;
        }
        //cerr << ' ' << p << '^' << cnt << '\n';
        int pre = a[index];
        a[index] += cnt*diff;
        //printf("a[%d] = %d->%d (+=%d*%d)\n", index, pre, a[index], cnt, diff);
        long long val = calc(p, a[index]);
        //cerr << ' ' << p << '^' << cnt << '=' << val << '\n';
        //cerr << ' ' << p << '^' << a[index] << '=' << val << '\n';
        update(tree, 1, 0, (int)primes.size()-1, index, val);
        //printf("update %d at [%d]\n", val, index);
        //printf("tree[0-%d]: ", (int)primes.size()-1);
        //for(int i=1; i<primes.size()*2; i++)
        //    printf("[%d]=%d, ", i, tree[i]);
        //printf("\n");
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin >> mod;
    vector<bool> check(2*n+2);
    vector<int> primes;
    vector<vector<int>> factors(2*n+2);
    for (int i=2; i<=2*n+1; i++) { // 2*(2n+1)/n+2 -> the biggest num: 2n+1
        if (check[i] == false) { // prime
            primes.push_back(i);
            int prime_index = (int)primes.size()-1;
            factors[i].push_back(prime_index);
            for (int j=i+i; j<=2*n+1; j+=i) {
                check[j] = true;
                factors[j].push_back(prime_index);
            }
        }
    }
    int pn = primes.size();
    vector<int> a(pn);
    int h = (int)ceil(log2(pn));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size, 1);
    long long ans = 0;
    // c0 = 1
    for (int i=0; i<n-2; i++) {
        //cerr << "c" << i << '\n';
        // cn+1 = 2(2n+1)/(n+2)cn
        multiply(a, tree, primes, factors, 2, 1);
        multiply(a, tree, primes, factors, 2*i+1, 1);
        multiply(a, tree, primes, factors, i+2, -1);
        //cerr << "+=" << tree[1] << '\n';
        ans += tree[1]; // Ci = Ti+2
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}
