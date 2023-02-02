t = int(input())
n = int(input())
l = [0] * 500009
r = [0] * 500009
for i in range(1,n+1):
    l[i], r[i] = map(int, input().split())

a = [0] * 500009
s = [0] * 500009
for i in range(1,n+1):
    a[l[i]+1] = a[l[i]+1] + 1
    a[r[i]+1] = a[r[i]+1] - 1

for i in range(1,t+1):
    s[i] = s[i-1] + a[i]
    print(s[i], end='\n')