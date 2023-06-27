#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

import sys
input = sys.stdin.readline
left = list(input().strip())
right = []
m = int(input())
for _ in range(m):
    line = input().strip().split()
    what = line[0]
    if what == 'L':
        if left:
            right.append(left.pop())
    elif what == 'D':
        if right:
            left.append(right.pop())
    elif what == 'P':
        left.append(line[1])
    elif what == 'B':
        if left:
            left.pop()
left += right[::-1]
print(''.join(left))

