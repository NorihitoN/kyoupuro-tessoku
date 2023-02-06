n, x = map(int, input().split())
a = list(map(int, input().split()))

l = 0
r = n-1
while(l < r):
    m = (l + r) // 2
    if (x <= a[m]):
        r = m
    else:
        l = m+1

print(l+1)