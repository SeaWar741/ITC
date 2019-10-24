n = int(raw_input())
numbers=list(map(int,raw_input().split()))
diff = 10**20
for i in range(n-1):
    for j in range(i+1,n):
        if abs(numbers[i]-numbers[j]) <diff:
            diff = abs(numbers[i]-numbers[j])
print(diff)