n = int(raw_input())
fichas = list(map(int,raw_input().split()))
suma = 0
for i in range(len(fichas)):
    suma += fichas[i]
if suma % 2 != 0:
    print(suma)
else:
    fichas.sort()
    aux = suma
    for i in range(len(fichas)):
        suma = aux
        suma = suma - fichas[i]
        if i == len(fichas) - 1:
            if suma % 2 != 0:
                print(suma)
            else:
                print(0)
        else:
            if suma % 2 != 0:
                print(suma)
                break