n = input()

ans = 0
for i in range(len(n)):
    ans = ans + int(n[-i-1]) * (2**i)

print(ans)