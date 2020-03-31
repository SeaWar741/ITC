a <- 10
b <- 20
a
b

#operaciones basicas
a==b
a<b
a>b
a+b
a+5

#numerica
x <-2
x

x <- 4+3*5^2
x

#caracter
x <- "TP53"
x

x<-letters[26] #en R inician desde 1 los arrays
x

#boolean
x <- 3 ==3
x

x<-4==5
x

x<-4==3+1
x

#funciones

x<- exp #funcion exponencial
x(log(5))

x<-max
x(c(1:4))


trunc(5/2)

a = TRUE
b = FALSE
a-b
b-a
a==b
a!=b

2+3*5
(2+3)*5

#R es un lenguaje interpretado

#vectores secuenciales
seq(from=1, to=10, by=1)

seq(from=1, to=10, length.out=10)

seq(17)

rep(1,times=5)

#indexar vectores
x <- rep(1:5,times = 5)
x
x[1] #1
x[1:6]#1 2 3 4 5 6
x[c(1,6,11,16,21)]#1 1 1 1 1
x[-1]#a x quitar primer elemento del 2 al 5
x[0] #integer 0, no existe por que inician en 1

x[x>3 & x <5] #todos los elementos mayores a 3 y menores a 5
x[x %in% c("a","and","the")]#elementos en el set dado
