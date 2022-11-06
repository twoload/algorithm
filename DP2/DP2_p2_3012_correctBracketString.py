# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# d[i][j] : num of correct bracket strings with i~j strings
# i.....k.....j
# (     ),?
# [     ],?
# {     },?
# ?     ),],},?
# inner : d[i+1][k-1]
# outer : d[k+1][j]
# d[i][j] = sum of inner*outer

n = int(input()) # 2<=n<=200
s = input()
start = "({["
end = ")}]"
d = [[-1]*201 for _ in range(201)]
mod = 100000

def go(i,j):
    if i > j:
        return 1
    ans = d[i][j]
    if ans != -1:
        return ans
    ans = 0
    d[i][j] = 0
    # i ..... k ..... j -> (i~k), (k+1,j)
    for k in range(i+1,j+1,2): # in pair
        for l in range(3):
            if s[i] == start[l] or s[i] == '?':
                if s[k] == end[l] or s[k] == '?': # match
                    temp = go(i+1,k-1) * go(k+1,j)
                    ans += temp
                    d[i][j] = ans
                    if ans >= mod:
                        ans = mod + ans % mod # to make ans over mod
                        d[i][j] = ans
    return ans

ans = go(0,n-1)
if ans >= mod:
    print(str(ans)[-5:]) #last 5 string
else:
    print(ans)


