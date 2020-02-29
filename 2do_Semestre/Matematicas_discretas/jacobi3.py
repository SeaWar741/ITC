#Juan Carlos Garfias Tovar, A01652138

def valx(a1, b1, c1, d1, y, z): #retorna valor x
    x = (-(b1*y)-(c1*z)+d1)/a1   
    return x
def valy(a2, b2, c2, d2, x, z):  #retorna valor y
    y = (-(a2*x)-(c2*z)+d2)/b2   
    return y   
def valz(a3, b3, c3, d3, x, y):  #retorna valor z
    z = (-(a3*x)-(b3*y)+d3)/c3   
    return z 

vals = [[0.0,0.0,0.0],[1.0,1.0,1.0]]
cons = [[0,0,0,0],[0,0,0,0],[0,0,0,0]]
cons[0][0] = float(input("\nIngrese A1 > "))   # Constantes para ecuacion 1
cons[0][1] = float(input("Ingrese B1 > "))
cons[0][2] = float(input("Ingrese C1 > "))
cons[0][3] = float(input("Ingrese D1 > "))
cons[1][0] = float(input("\nIngrese A2 > "))   # Constantes para ecuacion 2)
cons[1][1] = float(input("Ingrese B2 > "))
cons[1][2] = float(input("Ingrese C2 > "))
cons[1][3] = float(input("Ingrese D2 > "))
cons[2][0] = float(input("\nIngrese A3 > "))   # Constantes para ecuacion 3)
cons[2][1] = float(input("Ingrese B3 > "))
cons[2][2] = float(input("Ingrese C3 > "))
cons[2][3] = float(input("Ingrese D3 > "))

for i in range(10): #Realiza for loop para el numero de iteraciones
    print("\nIteracion "+str(i)+":")
    print(vals[0])
    vals[1][0] = valx(cons[0][0], cons[0][1], cons[0][2], cons[0][3],vals[0][1], vals[0][2])
    vals[1][1] = valy(cons[1][0], cons[1][1], cons[1][2], cons[1][3],vals[0][0], vals[0][2])
    vals[1][2] = valz(cons[2][0], cons[2][1], cons[2][2], cons[2][3],vals[0][0], vals[0][1])
    print(vals[1])
    vals[0][0] = valx(cons[0][0], cons[0][1], cons[0][2], cons[0][3],vals[1][1], vals[1][2])
    vals[0][1] = valy(cons[1][0], cons[1][1], cons[1][2], cons[1][3],vals[1][0], vals[1][2])
    vals[0][2] = valz(cons[2][0], cons[2][1], cons[2][2], cons[2][3],vals[1][0], vals[1][1])