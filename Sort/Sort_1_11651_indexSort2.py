import sys
from collections import namedtuple
input = sys.stdin.readline

Pair = namedtuple('Pair',['x','y'])

n = int(input())
a = []
for _ in range(n):
    a.append(Pair(*map(int,input().split())))

a.sort(key=lambda p: (p.y, p.x))
#print(type(a))
for i in a:
    print(i.x, i.y)