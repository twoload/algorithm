#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# X % a^2 != 0 -> square ㄴㄴ num
# use eratostenes

# 10^12 :381x10000 MB : 4TB
# 10^8 : 381MB 

# min~max diff : 1000,000
# bool check[1000001]; // if min+i can be erased, true. if not, false

# ex. min = 20
# idx: 0  1  2  3  4  5  6  7  8  9  
#    :20 21 22 23 24 25 26 27 28 29 (0~3^2-1 = 0~8 repetition)
#                          (*)
# 3^2
# min%(i*i) = 20%(3^2) = 2
# i*i - min%(i*i) = 3*3 - 2 = 7
#endif

#include <cstdio>
bool check[1000001]; // min~ 
long long min,max;
int main(){
    scanf("%lld %lld",&min,&max);
    for (long long i=2; i*i<=max; i++){
        long long start = i*i-min%(i*i);
        if (start == i*i) {
            start = 0;
        }
        // remove +i*i like eratestenes 
        for (long long j = start; j <= max-min; j+= i*i) {
            check[j] = true;
        }
    }
    int ans = 0;
    for (int i=0; i<=max-min; i++) {
        if (check[i] == 0) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}