# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

BLANK = ' '
STAR = '*'

# ex. n= 3
# go(a, 0, 2, 3, STAR)
#    if n!=1:
#       m = n//2 = 1
#       go(a,0,2,1,STAR) : do nothing
#       go(a,1,1,1,STAR) : do nothing
#       go(a,1,3,1,STAR) : do nothing
#       if n == 3
#          go(a,1,2,1,BLANK) : m = 1, a[1][2] = ''
# ******
# ** ***
# ******

# ex. n= 6
# go(a,0,5,6,STAR)
#    if n!=1:
#       m = n//2 = 3
#       go(a,0,5,3,STAR)
#       go(a,3,2,3,STAR)
#       go(a,3,8,3,STAR)
#       go(a,3,3,3,BLANK)
#    
#      (0,5) n=6
#      * (0,5) n=3
#     * *
#    *****
#   *(3,2)*(3,8) n=3
#  * *   * *
# ***** *****
def go(a, x, y, n, color):
    if color == BLANK:
        # ex. 3,3,3
        m = 2*n-1 # m = 5
        for i in range(x,x+n): # n = 3
            for j in range(m): # m = 5
                # a[3][3] ~ a[3][7] = ''
                # a[4][4] ~ a[4][6] = ''
                # a[5][5] ~ a[5][5] = ''
                a[i][j+i-x+y] = BLANK 
            m -= 2
    elif color == STAR:
        if n != 1:
            m = n//2
            go(a, x, y, m, STAR)
            go(a, x+m, y-m, m, STAR)
            go(a, x+m, y+m, m, STAR)
            if n == 3:
                go(a, x+1, y, 1, BLANK)
            else:
                go(a, x+m, y-m+1, m, BLANK)

n = int(input())
a = [[STAR] * (2*n) for _ in range(n)] # row*2-1 = col
go(a, 0, n-1, n, STAR)

#for row in a:
#    print(''.join(row))
# ex. n = 3
# a
# ******
# ******
# ******
#
# i = 0, j = 0 (j = n-i-1 = 2)
# a[0][0] = ''
# a[0][4] = ''
# i = 0, j = 1
# a[0][1] = ''
# a[0][3] = ''
# a[0][5] = ''
# i = 1, j = 0 (j = n-i-1 = 1)
# a[1][0] = ''
# a[1][4] = ''
# a[1][5] = ''
# i = 2, j = 0 (j = n-i-1 = 0)
# a[2][5] = ''
#   *   
#  ***
# *****
for i in range(n): # row index
    for j in range(n-i-1):
        a[i][j] = BLANK
        a[i][2*n-j-2] = BLANK
    a[i][2*n-1] = BLANK
    
for row in a:
    print(''.join(row))

