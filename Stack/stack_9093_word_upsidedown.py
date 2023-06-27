#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    s = input()
    stack = []
    for ch in s:
        if ch == ' ' or ch == '\n':
            print(''.join(stack[::-1]), end='')
            stack.clear()
            print(ch, end='')
        else:
            stack.append(ch) 