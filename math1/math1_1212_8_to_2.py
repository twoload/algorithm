#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#!/usr/bin/python3
eight = ["000","001","010","011","100","101","110","111"]
s = input()
start = True
ans = ''
if s == '0':
    ans = '0'
for ch in s:
    n = ord(ch)-ord('0')
    if start and n < 4:
        if n == 0:
            continue
        elif n == 1:
            ans += '1'
        elif n == 2:
            ans += '10'
        elif n == 3:
            ans += '11'
        start = False
    else:
        ans += eight[n]
        start = False
print(ans)
