data = list(map(int,raw_input().split()))
numbers = list(map(int,raw_input().split()))
T = data[0]
counter = 0
for i in range(len(numbers)):
    if T > 0:
        counter+=1
    T -=numbers[i]
if T > 0:
    counter = 0
print(counter)