def min_subarray_length(array, S):
    n = len(array)
    min_length = float('inf')
    current_sum = 0
    start = 0
    
    for end in range(n):
        current_sum += array[end]
        
        while current_sum >= S:
            min_length = min(min_length, end - start + 1)
            current_sum -= array[start]
            start += 1
            
    return min_length

n, S = map(int, input().split())
array = list(map(int, input().split()))

result = min_subarray_length(array, S)
print(result)
