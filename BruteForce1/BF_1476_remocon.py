#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

# push number and push only +/- one of two

# target : smaller / bigger each find
# +++, ---
# no!

# target ++1 ...
 
# target --1 ...

# if all numbers are correct, OK! find answer

# O(n) = 500'000


n = int(input())
m = int(input())
broken = [False] * 10 #0,1,2,3,4,5,6,7,8,9
if m > 0:
    a = list(map(int,input().split()))
else:
    a = []
for x in a:
    broken[x] = True
def possible(c):
    if c == 0:
        if broken[0]:
            return 0
        else:
            return 1
    l = 0
    while c > 0:
        if broken[c%10]:
            return 0
        l += 1
        c //= 10
    return l
ans = abs(n-100) # o nly +/- push case
for i in range(0, 1000000+1): #+500000, -500000 -> 0~1000000
    c = i
    l = possible(c)
    if l > 0:
        press = abs(c-n)
        if ans > l + press: # compare number + +/- push
            ans = l + press
print(ans)

