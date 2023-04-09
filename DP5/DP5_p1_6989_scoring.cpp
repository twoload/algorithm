#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n : 1<= n <= 150
// k : 1<= k <= 2'000'000'000

// Si : score

// 1,2,3,.....n
// O,X,........
// O(2^n) = O(2^150)

// d[n] : at n

// teacher
// d[i][j] : can you get score j when you consider until i-th problems ?
// score(i,j) : score which you solve i~j continously

 // I didn't solve i-th
 //   = d[i-1][j]
 // I did solve i-th
 //           k      i  //if you didn't solve k-th (last one)
 //       *  | |<---->
 //       |       score(k+1,i)
 //       v
 //   = d[k-1][j- score(k+1,i)]
 //     if you solved even one, 1
 // or
 // score(1,i) == j -> 1      

 // d[151][1132501] -> 163MB
 // n : n<=150, score<=100
 // 100+200+...+150'00
 // 150x151/2 * 100 = 1132501

 // 128MB limit


// d[i][j] <= d[k-1][j- score(k+1,i)]  ,  (1<=k<=i)  
//            d[k'][j- score(k'+2,i)]
//            if you solved even one, 1
// d[i] |= d[k'] << score(k'+2,i)  ,  (0<=k'<i)      (1<=k<=i -> 0<=k-1=k'<i)
//         in bit operation, +, - are the same as left, right shift

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int MAX = 10;//30;//1132500;
const int MAX_N = 4;//150;
bitset<MAX+1> d[MAX_N+1];
int score[MAX_N+1][MAX_N+1];
int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i]; // score
    }
    int k;
    cin >> k;
    for (int i=1; i<=n; i++) {
        int sum = 0;
        int acc = 0;
        for (int j=i; j<=n; j++) {
            sum += a[j];
            acc += sum;
            score[i][j] = acc; // accumulate
        }
    }
    if (k > score[1][n]) {
        cout << k << '\n';
        return 0;
    }
    d[0].set(0, 1); // d[0][0] = 1 : true when value = 0 at n = 0
    //cout << "d[0]: " << d[0] << endl;
    for (int i=1; i<=n; i++) {
        d[i].set(score[1][i], 1); // d[i][score[1][i]]=1
        //cout << "d[" << i <<"][" << score[1][i] << "]=1" << endl; 
        //cout << "d[" << i << "]: " << d[i] << endl;
        for (int j=0; j<i; j++) {
            d[i] |= d[j] << score[j+2][i];
            //cout << "d[" << i <<"] |= d[" << j << "] << score[" << j+2 <<"][" << i << "](" << score[j+2][i] << ")" << endl;
            //cout << "d[" << i <<"]= " << d[i] << endl;   
        }
    }
    while (true) {
        // d[n][k] == 0
        if (d[n].test(k) == 0) { // check if bit is set
            cout << k << '\n';
            break;
        }
        k += 1;
    }
    return 0;
}

