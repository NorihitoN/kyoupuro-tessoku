n, k = map(int, input().split())
a = list(map(int, input().split()))

def check(m):
    sum = 0
    for i in range(n):
        sum = sum + m // a[i]
    return k <= sum

l = 1
r = 1000_000_000
while(l < r):
    m = (l + r) // 2
    if (check(m)):
        r = m
    else:
        l = m+1

print(l)