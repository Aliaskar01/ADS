def solve(arr, id, coef, bst):
    if id < 1:
        return

    bst.append(arr[id])
    if coef < 1:
        return

    solve(arr, id - coef, coef // 2, bst)
    solve(arr, id + coef, coef // 2, bst)


n = int(input())
size = 1 << n 
arr = [0]

arr += list(map(int, input().split()))
arr.sort()

bst = []
if n == 1:
    bst.append(arr[1])
else:
    solve(arr, 1 << (n - 1), 1 << (n - 2), bst)

print(' '.join(map(str, bst)))
