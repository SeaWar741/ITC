#camiones
#preguntas
inv=list(map(int,raw_input().split()))
n = inv[0]
p = inv[1]
camiones = []
result =[]
for i in range(n):
    camiones.append(int(raw_input()))
for i in range(p):
    camion = int(raw_input())
    result.append(camiones[camion-1])
for i in result:
    print(i)

