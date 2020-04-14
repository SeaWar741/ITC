plot(sqrt(1:20),xlab="Elementos",ylab="Raiz Cuadrada",main="Prueba de PLot",sub="Sub de Plot")

data(cars)
attach(cars)
plot(x=dist,y=speed,main="Titulo",sub="Subtitulo",xlab="Eje X",ylab="Eje Y")

plot(speed,main="Titulo",ylab="Eje Y")

x<-c(1:20)^2
plot(x,type="p")
plot(x,type="l")
plot(1:25,type="p",pch=1:25)