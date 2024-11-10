def kmp_search(text, pattern):
   
    lps = [0] * len(pattern)
    j = 0
    i = 1
    while i < len(pattern):
        if pattern[i] == pattern[j]:
            j += 1
            lps[i] = j
            i += 1
        else:
            if j != 0:
                j = lps[j - 1]
            else:
                lps[i] = 0
                i += 1

    result = []
    i = j = 0
    while i < len(text):
        if pattern[j] == text[i]:
            i += 1
            j += 1
        if j == len(pattern):
            result.append(i - j)
            j = lps[j - 1]
        elif i < len(text) and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return result

def count_common_parasite_occurrences(student1, student2, parasite):
    
    positions1 = set(kmp_search(student1, parasite))
    positions2 = set(kmp_search(student2, parasite))
    

    common_positions = positions1 & positions2
    return len(common_positions)

student1 = input().strip()
student2 = input().strip()
parasite = input().strip()

count = count_common_parasite_occurrences(student1, student2, parasite)
print(count)