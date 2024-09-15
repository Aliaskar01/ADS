arr = []
while True:
    l = input().split()
    if len(l) == 0:
        continue
    elif len(l) == 1:
        if l[0] == '!':
            break
        if len(arr) > 0:
            print(arr[0] + arr[-1])
            arr.pop()
            if len(arr) > 0:
                arr.pop(0)
        else:
            print('error')
    else:
        if l[0] == '+':
            arr.append(int(l[1]))
        else:
            arr = [int(l[1])] + arr