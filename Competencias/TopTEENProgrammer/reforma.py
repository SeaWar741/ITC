counter = 0
number = int(raw_input())
x=list(map(int,raw_input().split()))
for i in range(len(x)):
    if i < number-1:
        if x[i] > x[i+1]:
            counter+=1
print(counter)

