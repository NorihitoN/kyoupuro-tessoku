n = int(input())
a = list(map(int, input().split()))
d = int(input())
l = [0]*d
r = [0]*d
for i in range(d):
    l[i], r[i] = map(int, input().split())

x = [0]*n
y = [0]*n

x[0] = a[0]
for i in range(1,n):
    x[i] = max(x[i-1], a[i])

y[n-1] = a[n-1]
for i in range(n-2,-1,-1):
    y[i] = max(y[i+1], a[i])

for i in range(d):
    print(max(x[l[i]-2], y[r[i]]))