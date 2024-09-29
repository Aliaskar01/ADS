def upper_bound(arr, val):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] > val:
            high = mid - 1
        else:
            low = mid + 1
    return high

def lower_bound(arr, val):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] < val:
            low = mid + 1
        else:
            high = mid - 1
    return low

def get_answer(arr, l, r):
    return upper_bound(arr, r) - lower_bound(arr, l) + 1

# Example usage (similar to the previous main):
n, q = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

for _ in range(q):
    cord = list(map(int, input().split()))
    if cord[0] > cord[2]:
        cord[0], cord[2] = cord[2], cord[0]
        cord[1], cord[3] = cord[3], cord[1]

    if cord[1] >= cord[2]:
        if cord[0] <= cord[2]:
            print(get_answer(arr, cord[0], max(cord[1], cord[3])))
        else:
            print(get_answer(arr, cord[2], max(cord[1], cord[3])))
    else:
        print(get_answer(arr, cord[0], cord[1]) + get_answer(arr, cord[2], cord[3]))
