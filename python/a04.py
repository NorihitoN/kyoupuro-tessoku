N = int(input())

for i in range(9, -1, -1):
    print((N // (2**i)) % 2, end="")