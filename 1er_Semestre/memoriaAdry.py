import random
values={} #Diccionario guardar los pares de cartas

def creatablero():
    board = [[0]*6 for i in range(6)]#crea un array de 6x6 en un for
    num =1 #variable para el elemento del array
    for i in range(6):#for para aumentar el numero y colocar en el tablero [i][J] row
        for j in range(6):#columna
            board[i][j]= num
            num+=1#se le suma uno
    return board #regresa una matriz 6*6

def printtablero(board):
    s = [[str(e) for e in row] for row in board] #cada elemento del row lo hace un string
    lens = [max(map(len, col)) for col in zip(*s)] #cada elemento de la columna lo junta  y lo hace un string en grupos de filas
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)#le da un fomato con igual espaciado (\t --> tab(4 espacios aprox))
    table = [fmt.format(*row) for row in s]#lo vuelve una tabla
    print ('\n'.join(table))#lo junta y lo imprime por linea

def setvalues(values):    
    keys = list(range(1, 37)) #lista de tamaño 36 con valores del 1 al 36
    random.shuffle(keys)#mezcla de los numeros
    values={keys[0]:'azul',keys[1]:'rojo',keys[2]:'amarillo',keys[3]:'rosa',keys[4]:'morado',keys[5]:'naranja',keys[6]:'blanco',keys[7]:'negro',keys[8]:'celeste',keys[9]:'magenta',keys[10]:'turquesa',keys[11]:'cafe',keys[12]:'beige',keys[13]:'verde',keys[14]:'lila',keys[15]:'plata',keys[16]:'dorado',keys[17]:'marino',keys[18]:'azul',keys[19]:'rojo',keys[20]:'amarillo',keys[21]:'rosa',keys[22]:'morado',keys[23]:'naranja',keys[24]:'blanco',keys[25]:'negro',keys[26]:'celeste',keys[27]:'magenta',keys[28]:'turquesa',keys[29]:'cafe',keys[30]:'beige',keys[31]:'verde',keys[32]:'lila',keys[33]:'plata',keys[34]:'dorado',keys[35]:'marino'}
    #print(values)
    return values #regresa los valores cartas volteadas (diccionario)

def game(values,board):
    done_numbers = [] #se almacenan los pares que ya se sacaron
    print()
    print("----------= Bienvenido al Juego de Memoria =----------\n")
    printtablero(board)
    print()
    user1n = input("Ingresar nombre del jugador 1: >")#guardar nombre1
    user2n = input("Ingresar nombre del jugador 2: >")#guardar nombre2
    print()
    p1 = 0 #puntaje jugador 1
    p2 = 0 #puntaje jugador 2
    continueg = True #booleano para que continue el juego
    i = 0 #contador
    while continueg:
        if (i % 2 == 0):#jugador 1
            print(f"----------=      Turno de: {user1n} | Puntos: {p1}      =----------")#vaiable dentro de un output
            position = int(input("Ingresar carta 1: "))
            if position not in done_numbers:#posicion no esta en las cartas ya sacadas continua, si no pierde el turno
                print(values.get(position))#imprime el valor del numero ej.1-->azul
                position2 = int(input("Ingresar carta 2: "))
                if position not in done_numbers:#checa si no esta en las cartas ya sacadas, si no se pierde el turno
                    print(values.get(position2))#imprime el valor del numero
                    if values.get(position) == values.get(position2) and position != position2:
                        print("Obtuviste puntos!")
                        done_numbers.append(position)#añade la carta a las cartas ya sacadas
                        done_numbers.append(position2)#añade la carta a las cartas ya sacadas
                        p1 +=1#se le suma 1 punto
                    else:
                        print("Intentalo de nuevo!") ##no obtienes puntos
                else:
                    print("Pierdes tu turno por no poner atencion, esas cartas ya se obtuvieron!")
            else:
                print("Pierdes tu turno por no poner atencion, esa carta ya se obtuvo!")
        else: #jugador 2
            print(f"----------=      Turno de: {user2n} | Puntos: {p2}      =----------")
            position = int(input("Ingresar carta 1: "))
            if position not in done_numbers:
                print(values.get(position))
                position2 = int(input("Ingresar carta 2: "))
                if position not in done_numbers:
                    print(values.get(position2))
                    if values.get(position) == values.get(position2) and position != position2:
                        print("Obtuviste puntos!")
                        done_numbers.append(position)
                        done_numbers.append(position2)
                        p2 +=1
                    else:
                        print("Intentalo de nuevo!")
                else:
                    print("Pierdes tu turno por no poner atencion, esas cartas ya se obtuvieron!")
            else:
                print("Pierdes tu turno por no poner atencion, esa carta ya se obtuvo!")
        if i >=1: #si el contador es mayor a 1, si se paso la primera ronda preguntar si quieres continuar
            print("----------------------= ¿Continuar? =-----------------------")
            continuegq = input("(S/N) > ").lower() ##variable para el input si desea continuar (lo hace minuscualas)
            if continuegq == "n":#si es igual a n ya no va a continuar el juego
                continueg = False 
        print("------------------------= Tablero =------------------------\n")
        printtablero(board)#imprime el tablero
        print()
        i +=1
        if len(done_numbers) == 36 or continueg == False: ##si se sacan 36 cartas o el jugador ya no quiere seguir
            continueg = False #se vuelve falso
            winner = "" #string vacio aqui se va a guardar quien gano
            if p1 > p2: #si persona 1 mas puntos gana j1
                winner = user1n
            elif p2<p1:#si persona 2 mas puntos gana j2
                winner = user2n
            else:
                winner = "Empate!" #si no es empate
            print("-----------------------= ATENENCION =----------------------\n")
            print("-------------------= TENEMOS UN GANADOR =------------------\n")
            print("                      '._==_==_=_.'")
            print('                      .-\:      /-.')
            print('                     | (|:.     |) |')
            print("                      '-|:.     |-'")
            print("                        \::.    /")
            print("                         '::. .'")
            print("                           ) (")
            print("                         _.' '._")
            print('                        `"""""""`')
            print(f"                          {winner}                     ")
            print(f"Puntaje: {user1n}, Puntos: {p1}")
            print(f"Puntaje: {user2n}, Puntos {p2}")

board = creatablero() #crea un tablero
values = setvalues(values) #establece valores
game(values,board) #inicia el juego