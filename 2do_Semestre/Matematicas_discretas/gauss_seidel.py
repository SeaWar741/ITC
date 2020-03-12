import numpy as np

def gauss_seidel(A,B,tolera,X,iteramax=100):
    tamano = np.shape(A)
    n = tamano[0]
    m = tamano[1]
    diferencia = np.ones(n, dtype=float)
    errado = np.max(diferencia)
    
    itera = 0
    while not(errado<=tolera or itera>iteramax):
        for i in range(0,n,1):
            nuevo = B[i]
            for j in range(0,m,1):
                if (i!=j): # excepto diagonal de A
                    nuevo = nuevo-A[i,j]*X[j]
            nuevo = nuevo/A[i,i]
            diferencia[i] = np.abs(nuevo-X[i])
            X[i] = nuevo
        errado = np.max(diferencia)
        itera = itera + 1
    # Vector en columna
    X = np.transpose([X])
    # No converge
    if (itera>iteramax):
        X=0
    return(X)

# Programa de prueba #######
# INGRESO
A = np.array([[1,1,1],
              [1,-1,1],
              [2,3,-5]])

B = np.array([7,3,2])

tolera = 0.00001

# PROCEDIMIENTO
n = len(B)
X = np.zeros(n, dtype=float)
respuesta = gauss_seidel(A,B,tolera,X)
verifica = np.dot(A,respuesta)

# SALIDA
print('respuesta de A.X=B : ')
print(respuesta)
print('verificar A.X: ')
print(verifica)