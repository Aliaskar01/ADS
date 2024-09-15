x = int(input())
li = [int(i) for i in input().split()]
print(-1, end=" ")
for i in range(1, x):
    for j in range(i-1, -1, -1):
        if li[j] <= li[i]:
            print(li[j], end=" ")
            break
        if j==0:
            print(-1, end=" ")