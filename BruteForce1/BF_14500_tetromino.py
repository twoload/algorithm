#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

blocks = (
    ((0,1), (0,2), (0,3)),
    ((1,0), (2,0), (3,0)),
    ((1,0), (1,1), (1,2)),
    ((0,1), (1,0), (2,0)),
    ((0,1), (0,2), (1,2)),
    ((1,0), (2,0), (2,-1)),
    ((0,1), (0,2), (-1,2)),
    ((1,0), (2,0), (2,1)),
    ((0,1), (0,2), (1,0)),
    ((0,1), (1,1), (2,1)),
    ((0,1), (1,0), (1,1)),
    ((0,1), (-1,1), (-1,2)),
    ((1,0), (1,1), (2,1)),
    ((0,1), (1,1), (1,2)),
    ((1,0), (1,-1), (2,-1)),
    ((0,1), (0,2), (-1,1)),
    ((0,1), (0,2), (1,1)),
    ((1,0), (2,0), (1,1)),
    ((1,0), (2,0), (1,-1)),
)

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
#print(a)
ans = 0
for i in range(n):
    for j in range(m):
        for block in blocks:
            ok = True
            s = a[i][j]
            for dx,dy in block:
                x, y = i+dx, j+dy
                if 0 <= x < n and 0 <= y < m:
                    s += a[x][y]
                else:
                    ok = False
                    break
            if ok and ans < s:
                ans = s
print(ans)

