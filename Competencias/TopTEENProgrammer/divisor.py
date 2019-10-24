n = int(raw_input())
i = 1
count = 0
while i <= n : 
    if (n % i==0) : 
        count+=1
    i = i + 1
print(count)
print()

def factors(n):
    while n > 1:
        for i in range(2, n + 1):
            if n % i == 0:
                n /= i
                yield i
            break

        for factor in factors(360):
            print factor