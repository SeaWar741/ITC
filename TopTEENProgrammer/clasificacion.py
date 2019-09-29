lados = [int(i) for i in raw_input().split()]
if(lados[0]==lados[1] and lados[1]==lados[2]):
    print("EQUILATERO")
elif(lados[0]==lados[1] or lados[0]==lados[2] or lados[1]==lados[2]):
    print("ISOCELES")
elif (lados[0]!=lados[1] or lados[0]!=lados[2] or lados[1]!=lados[2]):
    print("ESCALENO")
else:
    print("RECTANGULO")