h, w, n = map(int, input().split())
a = [0] * n 
b = [0] * n 
c = [0] * n 
d = [0] * n 
for i in range(n):
    a[i], b[i], c[i], d[i] = map(int, input().split())

x = [[0] * (w+1) for _ in range(h+1)]
for i in range(n):
    x[a[i]-1][b[i]-1] += 1
    x[a[i]-1][d[i]] -= 1
    x[c[i]][b[i]-1] -= 1
    x[c[i]][d[i]] += 1

z = [[0] * (w+1) for _ in range(h+1)]
for i in range(1,h+1):
    for j in range(1,w+1):
        z[i][j] = z[i][j-1] + x[i-1][j-1]
for j in range(1,w+1):
    for i in range(1,h+1):
        z[i][j] = z[i-1][j] + z[i][j]

for i in range(1,h+1):
    l = z[i][1:w+1]
    l = " ".join([str(_) for _ in l])
    print(l)