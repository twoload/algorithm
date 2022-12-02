# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# way 1
#   i, j, sum > O(N^3)
#   calc sum every time 
# way 2
#   i=1, j=b > i=a, j=b+1
#   sum(a ~ b) + a[b+1] = sum(a ~ b+1)
#   calc sum : accumulate
#   i, j > O(N^2)
# way 3
#   two pointer
#   O(n) + O(n) = O(n)

n, s = map(int, input().split())
a = list(map(int, input().split()))
left = right = 0
sum = a[0]
ans = 0
while left<=right and right<n:
    if sum < s:
        right += 1
        if right < n:
            sum += a[right]
    elif sum == s:
        ans += 1 # found
        right += 1
        if right < n:
            sum += a[right]
    elif sum > s:
        sum -= a[left]
        left += 1
        if left>right and left<n: # make right same as left
            right = left
            sum = a[left]
print(ans)
