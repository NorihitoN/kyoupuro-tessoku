N = int(input())
A = list(map(int, input().split()))
w = [0]
lo = [0]
for i in range(N):
    if A[i] == 1:
        w.append(w[-1]+1)
        lo.append(lo[-1])
    else:
        w.append(w[-1])
        lo.append(lo[-1]+1)


Q = int(input())
for _ in range(Q):
    l, r = map(int, input().split())
    wl = (w[r] - w[l-1]) - (lo[r] - lo[l-1])
    if wl > 0:
        print("win")
    elif wl < 0:
        print("lose")
    else:
        print("draw")
