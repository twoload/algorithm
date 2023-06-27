#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

MAX = 1000000
check = [0]*(MAX+1)
check[0] = check[1] = True
prime = []
for i in range(2, MAX+1):
    if not check[i]:
        prime.append(i)
        j = i+i
        while j <= MAX:
            check[j] = True
            j += i
prime = prime[1:] # prime[0]=2 (even) -> throw away
while True:
    n = int(input())
    if n == 0:
        break
    for p in prime:
        if check[n-p] == False: # prime
            print("{0} = {1} + {2}".format(n,p,n-p))
            break

