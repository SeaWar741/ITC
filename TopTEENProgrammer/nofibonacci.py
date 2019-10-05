a = 0
b = 1
c = 0
n = int(raw_input())
numbers = []
while c <= n:
    c = a+b
    a = b
    b = c
    d = a+b
    for i in range(c+1,d):
        if(i<n):
            numbers.append(i)
        else:
            break
print(' '.join(map(str, numbers)))