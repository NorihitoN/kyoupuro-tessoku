A, B = map(int, input().split())
find_ans = False
for i in range(A, B+1):
    if 100%i == 0:
        find_ans = True
        break
if find_ans == True:
    print("Yes")
else:
    print("No")