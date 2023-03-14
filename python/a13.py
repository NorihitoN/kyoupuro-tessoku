n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
j = 1


for i in range(1, 10):
    print(i)


for i in range(0, n - 1):
    while j < n and a[j] - a[i] <= k:
        j += 1
    ans += j - i - 1

print(ans)

