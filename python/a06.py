N, Q = map(int, input().split())
A = list(map(int, input().split()))
A = [0] + A
S = [0]
for a in A[1:]:
    S.append(S[-1] + a)


for _ in range(Q):
    L, R = map(int, input().split())
    print(S[R] - S[L-1])
