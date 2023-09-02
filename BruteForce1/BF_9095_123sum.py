#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

t = int(input())
for _ in range(t):
    ans = 0
    n = int(input())
    for l1 in range(1, 4):
        if l1 == n:
            ans += 1
        for l2 in range(1, 4):
            if l1+l2 == n:
                ans += 1
            for l3 in range(1, 4):
                if l1+l2+l3 == n:
                    ans += 1
                for l4 in range(1, 4):
                    if l1+l2+l3+l4 == n:
                        ans += 1
                    for l5 in range(1, 4):
                        if l1+l2+l3+l4+l5 == n:
                            ans += 1
                        for l6 in range(1, 4):
                            if l1+l2+l3+l4+l5+l6 == n:
                                ans += 1
                            for l7 in range(1, 4):
                                if l1+l2+l3+l4+l5+l6+l7 == n:
                                    ans += 1
                                for l8 in range(1, 4):
                                    if l1+l2+l3+l4+l5+l6+l7+l8 == n:
                                        ans += 1
                                    for l9 in range(1, 4):
                                        if l1+l2+l3+l4+l5+l6+l7+l8+l9 == n:
                                            ans += 1
                                        for l0 in range(1, 4):
                                            if l1+l2+l3+l4+l5+l6+l7+l8+l9+l0 == n:
                                                ans += 1
    print(ans)
