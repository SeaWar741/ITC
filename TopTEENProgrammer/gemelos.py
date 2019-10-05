#tomaras el numero minio de monedas, cuya suma de valores es estrictamente mayor que la suma de los valores de las monedas restantes


n = int(raw_input())
money=list(map(int,raw_input().split()))
c = 0
acum = 0
suma = 0
nacum =0
money.sort(reverse=True)
for i in range(n):
    acum+=money[i]
for j in range(n):
    suma += money[j]
    nacum = acum - suma
    if suma > nacum:
        print(j+1)
        break
