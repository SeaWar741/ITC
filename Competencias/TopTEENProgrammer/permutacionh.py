from itertools import permutations
def  mcd(p, q):
    if q==0 :
        return p
    else:
        reminder = p%q
        return mcd(q, reminder)
fc = list(map(int,raw_input().split()))
n = fc[0]
k = fc[1]
if n > 1 and n != k:
    numeros_seguidos = [(i) for i in range(1, n + 1)]
    permutacion = list(permutations(numeros_seguidos))
    factorial = 1
    for i in range(1, n + 1):
        factorial = factorial * i
    hermosa = []
    count = 0
    while len(hermosa) != k and count < factorial:
        hermosa = []
        for x in range(n):
            reminder = mcd(permutacion[count][x], numeros_seguidos[x])
            if reminder > 1:
                hermosa.append(permutacion[count][x])
        count = count + 1
    if len(hermosa) != k:
        print(-1)
    else:
        for i in permutacion[count-1]:
            print(i)
else:
    print(-1)