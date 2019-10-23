n = int(input())
lista = list(map(int,input().split()))
lista.sort()
if lista[1]-lista[0] > lista[-1]-lista[-2]:
    lista.remove(lista[0])
else:
    lista.remove(lista[-1])
if lista[1]-lista[0] > lista[-1]-lista[-2]:
    lista.remove(lista[0])
else:
    lista.remove(lista[-1])
dis = 0
for i in range(n-1):
    dis = dis + lista[i+1]-lista[i]
    lista.remove(lista[i])
print(dis)