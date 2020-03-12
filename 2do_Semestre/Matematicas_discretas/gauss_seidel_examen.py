#Juan Carlos Garfias Tovar, A01652138
#solucion gauss seidel metodo matricial

#con este metodo no se puede resolver esta matrix debido a que la matriz no es de diagonal dominante

'''
 x +  y +  z = 7
 x -  y +  z = 3
2x + 3y - 5z = 2

Forma matricial:

|1,  1,  1|  7|
|1, -1,  1|  3|
|2,  3, -5|  2|

'''
#se puede observar que no se pueden observar los valores para que al despejar para x el coeficiente de la x tiene que ser el mas alto en la fila.
#en este caso esta condicion no se cumple por lo que no es factible obtener un valor real para x,y,z

previos = [0, 0, 0]	#guardar los valores previos de x,y,z, comenzando con 0,0,0					 
coeficientes = [[1, 1, 1],[1, -1, 1],[2, 3, -5]] #matriz para guardar los coeficientes de x,y,z
valores = [7,3,2] #resultados de cada ecuacion

def solver(coeficientes, previos ,valores): #metodo solver para gauss seidel
	for j in range(0, 3):		 
		d = valores[j]#variable para guardar los valores de manera temporal
		
		for i in range(0, 3):#se realiza un for para evaluar los valores, es decir despejarlos
			if(j != i):
				d-=coeficientes[j][i] * previos[i]
		previos[j] = d / coeficientes[j][j] #actualiza los valores previos a los nuevos calculados
	return previos


for i in range(1, 11):
    print("\n----------------------------------= Iteracion #"+str(i)+" =----------------------------------\n")
    previos = solver(coeficientes, previos ,valores)
    print("X: "+str(previos[0])+"\tY: "+str(previos[1])+"\tZ: "+str(previos[2]))
