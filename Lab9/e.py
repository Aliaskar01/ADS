def find_minimal_task_name(s, k):
    n = len(s)
    
    lps = [0] * n
    j = 0
    for i in range(1, n):
        while j > 0 and s[i] != s[j]:
            j = lps[j - 1]
        if s[i] == s[j]:
            j += 1
            lps[i] = j
    
    overlap = lps[-1]
    minimal_length = n + (k - 1) * (n - overlap)
    
    return minimal_length


t = int(input())
results = []
for _ in range(t):
    s, k = input().strip().split()
    k = int(k)
    result = find_minimal_task_name(s, k)
    results.append(result)


for res in results:
    print(res)