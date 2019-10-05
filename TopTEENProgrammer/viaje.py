encrypt = {chr(i+96):i for i in range(1,27)}
alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
cases = int(raw_input())
result=[]

for i in range(cases):
    ovni1 = raw_input().lower()
    ovni2 = raw_input().lower()
    ovni1n = 1
    ovni2n =1
    for i in ovni1:
        ovni1n = ovni1n*encrypt[i]
    for i in ovni2:
        ovni2n = ovni2n*encrypt[i]
    # Si el numero del grupo modulo 47 es el mismo que el numero del cometa modulo 47
    if ovni1n %47 == ovni2n%47:
        result.append("GO")
    else:
        result.append("STAY")
for i in result:
    print(i)