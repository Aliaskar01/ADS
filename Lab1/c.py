def process_string(s):
    stack = []
    for char in s:
        if char == '#':
            if stack:
                stack.pop()
        else:
            stack.append(char)
    return ''.join(stack)

def equal_strings(s1, s2):
    return process_string(s1) == process_string(s2)


input_str = input().split()
s1, s2 = input_str[0], input_str[1]

if equal_strings(s1, s2):
    print("Yes")
else:
    print("No")