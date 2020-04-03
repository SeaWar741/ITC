x<-1:10
print(x)
x[4]<-"String" #no es necesario especificar tipo solo si se cambia
print(x)

LOG <-function(n)n*2
print(LOG(100))

#character scaping, especificar caracteres literales
x <- c("Doble comilla",'comilla simple')
print(x)
x <- c("Doble comilla",'comilla " simple')
print(x)
x <- c("doble comilla",'comilla " simple',"poner doble comilla \" interna")
print(x)
x <- c("Prueba")
print(nchar(x))
x<-c("Prueba\"")
print(x)
print(nchar(x))

x<- c("Prueba\\")
print(x)
print(nchar(x))

x<- c("Prueba\\\\") 
print(x)
print(nchar(x))

#NA--> dato que falta,es como borrar la variable, not found y NA es casi lo mismo
x <-c(1,2,3,NA,6)
print(x)

x=NULL
#tambien existe null, es como borrar variable
print(ls())
x <-c("1","2","3","no jala")
print(x)
as.numeric(x)
print(x)

#para quitar haces esto
na.omit(as.numeric(x))
is.na(x)
n<-as.numeric(x)
print(n)
print(is.na(n))
#no se puede hacer n==NA
print(n==NA)
Inf
-Inf
#generar seccuencias
print(seq(1,10))
print(seq(1,10,3))
print(seq(1,11,3))
#print(seq(11,1,3))
print(seq(11,1))
print(seq(11,11,-3))

print(seq(11,1,length.out=4))#(11-1)/4 y se le suma el valor

print(pi)
print(letters)
print(LETTERS)
print(month.name)

print(rep(1:3,times=c(3,2,1)))
print(rep(1:3,times=30:28))

print(table(rep(1:3,times=30:28)))
print(rep(1:3,times=3))

print(1:5)
print(seq(5,1))
print(rep(5,4))
print(seq(1,100,by=4))
print(1:25*4-3)

#Indexado de vectores
x<-1:100
print(x)
print(x[8])
x<-100:1
print(x)
print(x[8])

print(x[0])#no se puede, regresa vector null
print(x[-1])#regresa vector sin el primer elemento
print(x[-1][8])