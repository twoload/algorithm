# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# even x even
# w > b > w > b ... > w
# w,b > w,b > w ? -> impossible

# row: even, col: odd
# |  |--|  |--|
# |  |  |  |  |
# |--|  |--|  |

# row: odd, col: odd
# row: odd, col: event
# ----|
# |---|
# |---|
# |---|
# |----

# row: even, col: even
# impossible 
# 1 point -> no visit : black
# find one point which we won't visit
# 

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

s = ''
# row: odd, col: odd
# row: odd, col: event
# ----|
# |---|
# |---|
# |---|
# |----

if n % 2 == 1: # row:odd
    for i in range(n):
        if i % 2 == 0: # row 0,2,4,
            s += 'R' * (m-1)
            if i != n-1:
                s += 'D'
        else: # row 1,3,5
            s += 'L' * (m-1)
            s += 'D'
# row: even, col: odd
# |  |--|  |--|
# |  |  |  |  |
# |--|  |--|  |
elif m % 2 == 1: # row:even, col: odd
    for j in range(m):
        if j%2 == 0: # col:0,2,4,
            s += 'D' * (n-1)
            if j != m-1:
                s += 'R'
        else: # col:1,3,5
            s += 'U' * (n-1)
            s += 'R'
else:
    x = 0
    y = 1 # first black
    for i in range(n):
        for j in range(m):
            if (i+j) % 2 == 1: # black
                if a[x][y] > a[i][j]: # minimum
                    x,y = i,j 
    # x,y = no visit : black
    x1 = 0
    y1 = 0
    x2 = n-1
    y2 = m-1
    s2 = ''
    # if 2 series row line doesn't have no-visit-black
    while x2 - x1 > 1:
        # ------|
        # |------     
        if x1//2 < x//2: # start point
            s += 'R' * (m-1)
            s += 'D'
            s += 'L' * (m-1)
            s += 'D'
            x1 += 2    
        #       |
        # |------
        #  ------
        if x//2 < x2//2: # end point
            s2 += 'R' * (m-1)
            s2 += 'D'
            s2 += 'L' * (m-1)
            s2 += 'D'
            x2 -= 2
    
    while y2 - y1 > 1:
        # | |-
        # ---
        if y1//2 < y//2: # start point
            s += 'DRUR'
            y1 += 2
        # --- 
        # | |- 
        if y//2 < y2//2: # end point
            s2 += 'DRUR'
            y2 -= 2
    # s 
    # b e
    if y == y1:
        s += 'RD'
    # s b
    #   e
    else:
        s += 'DR'
    s += s2[::-1] # s2's reverse
print(s) 