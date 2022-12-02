# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# a[1],a[2],a[3],,,
# b[1],b[2],b[3],,,
# T = total sum
# about a, two pointer, partial sum : O(n)
# about b, O(n)
# T : O(n^2)
#
# >
# about a, b : O(n) or O(n^2)
# with Counter : O(n)
# find sum : numbering num of T (a+b) : O(n)
# (O(n) or O(n^2)) + O(n) + O(n)

from collections import Counter
t = int(input())
n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
x = []
y = []
# a's all partial sum : O(n^2)
for i in range(n):
    sum = 0
    for j in range(i,n):
        sum += a[j] # accumulate
        x.append(sum)
# b's all partial sum : O(n^2)
for i in range(m):
    sum = 0
    for j in range(i,m):
        sum += b[j]
        y.append(sum)
x.sort()
y.sort()
c = Counter(y) # ({1:1,2:1,3:1,4:1,5:1,6:1})
#print(x, y, c, type(c))
ans = 0
for num in x: # t = 5
    ans += c[t-num] # num: x's partial sum, how many t-num exists in b ?
print(ans)