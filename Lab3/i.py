def binary_search(arr, x):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == x:
            return "Yes"
        elif arr[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return "No"

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    x = int(input())
    print(binary_search(arr, x))