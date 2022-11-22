# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# +A
# +B + reverse

# ex) 
# (A) <- by A
# AB > (B)A <- by B
# (B)AA(A) <- check
# BAAAB
# BAAABA
# BAAABAB > BABAAAB

s = input()
t = input()
def can(s, t):
    if s == t:
        return True
    if len(t) > 0:
        if t[-1] == 'A' and can(s, t[:-1]): # if last is A, by A -> remove last
            return True
        if t[0] == 'B' and can(s, t[:0:-1]): # if first is B, by B -> reverse and remove last
            return True
    return False
print(1 if can(s, t) else 0)

