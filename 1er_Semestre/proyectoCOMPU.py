import random

def num():
    lista = []
    for x in range(0,2):
        for y in range(0,18):
            lista.append(y+1)
    random.shuffle(lista)
    return lista

def memorama(numeros):
    carta = []
    for x in range(0,6):
        sublista = []
        for y in range(0,6):
            sublista.append(numeros.pop(0))
        carta.append(sublista)
    return carta

def tof():
    mat = []
    for x in range(0,6):
        sublista = []
        for y in range(0,6):
            sublista.append(False)
        mat.append(sublista)
    return mat

def imprimir(carta,tf):
    ren = len(carta)
    col = len(carta)
    for x in range(0,ren+1):
        if x == 0:
            print(" ",end="\t")
        else:
            print(x-1,end="\t")
    print("")
    print("")
    for z in range(0,ren):
        print(z,end="\t")
        for y in range(0,col):
            if tf[z][y] == False:
                print("-",end="\t")
            else:
                print(carta[z][y],end="\t")
        print("")
        print("")

def verificador(tf,carta,ren1,col1,ren2,col2):
    imprimir(carta,tf)
    if carta[ren1][col1] == carta[ren2][col2] and tf[ren1][col1] == True and tf[ren2][col2] == True:
        print("Posiciones correctas")
    else:
        tf[ren1][col1] = False
        tf[ren2][col2] = False
        print("Posiciones incorrectas")
        print("")

def pedir1(tf,carta,puntos1,puntos2):
    ren1 = int(input("Renglon Carta 1: >"))
    col1 = int(input("Columna Carta 1: >"))
    print()
    ren2 = int(input("Renglon Carta 2: >"))
    col2 = int(input("Columna Carta 2: >"))
    if ren1 < 6 and col1 < 6 and ren2 < 6 and col2 < 6 and tf[ren1][col1] == False and tf[ren2][col2] == False:
        tf[ren1][col1] = True
        tf[ren2][col2] = True
        verificador(tf,carta,ren1,col1,ren2,col2)
        puntos1 = puntosj1(tf,carta,ren1,col1,ren2,col2,puntos1)
        print("Puntos jugador 2: ",puntos2)
        return puntos1

    else:
        while ren1 > 5 or col1 > 5 or ren2 > 5 or col2 > 5 or tf[ren1][col1] == True or tf[ren2][col2] == True:
            print("Intenta con otros numeros")
            ren1 = int(input("Renglon Carta 1: >"))
            col1 = int(input("Columna Carta 1: >"))
            print()
            ren2 = int(input("Renglon Carta 2: >"))
            col2 = int(input("Columna Carta 2: >"))
        tf[ren1][col1] = True
        tf[ren2][col2] = True
        verificador(tf,carta,ren1,col1,ren2,col2)
        puntos1 = puntosj1(tf,carta,ren1,col1,ren2,col2,puntos1)
        print("Puntos jugador 2: ",puntos2)
        return puntos1

def pedir2(tf,carta,puntos1,puntos2):
    ren1 = int(input("Renglon Carta 1: >"))
    col1 = int(input("Columna Carta 1: >"))
    print()
    ren2 = int(input("Renglon Carta 2: >"))
    col2 = int(input("Columna Carta 2: >"))
    if ren1 < 6 and col1 < 6 and ren2 < 6 and col2 < 6 and tf[ren1][col1] == False and tf[ren2][col2] == False:
        tf[ren1][col1] = True
        tf[ren2][col2] = True
        verificador(tf,carta,ren1,col1,ren2,col2)
        print("Puntos jugador 1: ",puntos1)
        puntos2 = puntosj2(tf,carta,ren1,col1,ren2,col2,puntos2)
        return puntos2

    else:
        while ren1 > 5 or col1 > 5 or ren2 > 5 or col2 > 5 or tf[ren1][col1] == True or tf[ren2][col2] == True:
            print("Intenta con otros numeros")
            ren1 = int(input("Renglon Carta 1: >"))
            col1 = int(input("Columna Carta 1: >"))
            print()
            ren2 = int(input("Renglon Carta 2: >"))
            col2 = int(input("Columna Carta 2: >"))
        tf[ren1][col1] = True
        tf[ren2][col2] = True
        verificador(tf,carta,ren1,col1,ren2,col2)
        print("Puntos jugador 1: ",puntos1)
        puntos2 = puntosj2(tf,carta,ren1,col1,ren2,col2,puntos2)
        return puntos2
                
def puntosj1(tf,carta,ren1,col1,ren2,col2,puntos1):
    if tf[ren1][col1] == True and tf[ren2][col2] == True:
        puntos1 += 1
    print("Puntos jugador 1: ",puntos1)
    return puntos1

def puntosj2(tf,carta,ren1,col1,ren2,col2,puntos2):
    if tf[ren1][col1] == True and tf[ren2][col2] == True:
        puntos2 += 1
    print("Puntos jugador 2: ",puntos2)
    print("")
    return puntos2

def winner(puntos1,puntos2):
    ganador = ""
    if puntos1> puntos2:
        ganador = "Jugador 1"
    if puntos1< puntos2:
        ganador = "Jugador 2"
    else:
        ganador = "Empatados"
    print()
    print("    |@@@@|     |####|")
    print("    |@@@@|     |####|")
    print("    \@@@@|     |####/")
    print("     \@@@|     |###/")
    print("      `@@|_____|##'")
    print("           (O)")
    print("        .-'''''-.")
    print("      .'  * * *  `.")
    print("     :  *       *  :")
    print('    : ~           ~ :')
    print(f"    : ~ {ganador} ~ :")
    print('    : ~           ~ :')
    print("     :  *       *  :")
    print("      `.  * * *  .'")
    print("        `-.....-'")
    print()
    print(f"Puntaje Jugador 1: {puntos1}")
    print(f"Puntaje Jugador 2: {puntos2}")

def main():
    print()
    numeros = num()
    carta = memorama(numeros)
    tf = tof()
    puntos1 = 0
    puntos2 = 0
    while True:
        imprimir(carta,tf)
        print("")
        print("Jugador 1")
        print("")
        puntos1 = pedir1(tf,carta,puntos1,puntos2)
        sino = input("Quieres seguir jugando? Si/No: >")
        if sino.lower() == "no":
            winner(puntos1,puntos2)
            break
        print("")
        
        imprimir(carta,tf)
        print("")
        print("Jugador 2")
        print("")
        puntos2 = pedir2(tf,carta,puntos1,puntos2)
        sino = input("Quieres seguir jugando? Si/No: >")
        if sino.lower() == "no":
            winner(puntos1,puntos2)
            break
        print("")
        
main()