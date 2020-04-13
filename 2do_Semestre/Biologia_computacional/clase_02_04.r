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
print(x[-c(1,3,5)])
print(x)
print(x[-c(-1,-3,-5)])#solo puede eliminar o seleccionar, no se pueden mezclar

print(x[c(1,1,1,1,1,1,2,2,2,2,2,3,4,5)])

x<- 1:5
names(x)<-c("A","B","C","D","E") #en R no se llama diccionario, se llama vector nombrado
print(x)
print(x[4])
print(x["E"])

print(x[x>3])
print(x>3)

print(x[x>3&x<5])
print(x[x>=3&x<5])

y<-c(1,3,5)
print(y)
y<-c(1,3,5,7)
print(y)
print(x)
print(x[x%in%y])
print(x[y%in%x])
print(y%in%x)
print(y%in%x)

#matrices
m <- matrix(c(1:9),nrow=3,ncol=3,byrow=FALSE,dimnames=list(c("ROW1","ROW2","ROW3"),c("COL1","COL2","COL3")))
print(m)
print(m[2,2])
print(m[1,3])
print(m[1,])#regresa columna
print(m[,3])#regresa fila

#arrays
arry <- array(1:24,dim=c(3,4,2))
print(arry)

#Dataframes--> permite tener diferentes tipos de dato

#listas pueden combinarse
l<-list(c(1,5,3),matrix(1:6,nrow=3),c("Hello","world"))
print(l)
print(l[[2]][,2])
print(l[2])
print(l[2:3])
print(l[[2]][3])
print(l[[2]])

#ploteo
x<-c(1:20)^2
plot(x,type="p")
plot(x,type="b")
plot(x,type="o",pch=1:3,col=1:5)
x<-rep(1:5,times=c(5,4,3,2,10))
print(table(x))
hist(x)
hist(rnorm(10000))

gender <-(c("machote","feminista","machote","feminista","feminista"))
print(gender)#no sale entre comillas es factor
class(gender)
gender.char<-(c("machote","feminista","machote","feminista","feminista"))
print(class(gender.char))
print(gender)
print(as.integer(gender)) #te permite representarlo como numero

L<-list(c(1,5,3),matrix(1:6,nrow=3),c("Hello","World"))

v = list(bob=c(2,3,5),john=c("aa","bb"))
print(v)


#sample --> shuffle

x =c(rep(1,5),rep(2,3),rep(3,2))
print(x)
x<-sample(x)
print(x)
table(x)
print(table(x*2))

print(x*2)
