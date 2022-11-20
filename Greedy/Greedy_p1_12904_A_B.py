# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# S (1~999) -> T (2~1000)
# abc -> abcA (abcAAAAA...A)
# abc -> cbaB (BabcB > BcbaBB > BBabcBB > BBcbaBBB > BBBabcBBB)
#
# B (BA > ABB > ABBA)
# ABBA
#

s = input()
t = input()
while len(t) > len(s):
    if t[-1] == 'A':
        t = t[:-1]
    else: 
        t = t[:-1]
        t = t[::-1] # reverse with slicing (start,end,step)

if s == t:
    print(1)
else:
    print(0)