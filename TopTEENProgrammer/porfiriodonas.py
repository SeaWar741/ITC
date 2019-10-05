preguntas,a,b = raw_input().split()
preguntas = int(preguntas)
a = int(a) #paquete 1
b = int(b) #paquete 2

for i in range(preguntas):
    num = int(raw_input())
    if num % a ==0 or num % b==0:

        print("SI")
    else:
        print("NO")
