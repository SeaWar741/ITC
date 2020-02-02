uinput = int(raw_input())
numbers=list(map(int,raw_input().split()))
numbers.sort()
arry = []
for i in range(uinput):
    arry.append(0)
print(arry)
for i in range(len(numbers)):
    arry[i] = numbers[i]-1


print(arry)