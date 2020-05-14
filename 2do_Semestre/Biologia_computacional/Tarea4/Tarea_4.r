#Tu profesor te entregará  un archivo de texto donde se describe la base de datos por usar, una descripción y las comparaciones que se deben hacer de acuerdo a la situación problema. Deberás obtener los genes diferencialmente expresados usando una prueba t-Student (ttest en R) y el paquete de R LIMMA. Una vez que tengas los genes diferencialmente expresados, calcularás el enriquecimiento para vías de señalización celular usando una prueba hiper-geométrica. Al final harás la interpretación sobre las funciones celulares que están alteradas en cáncer.
#Vas a generar un reporte que contenga lo siguiente:
#Genes diferencialmente expresados usando cada método.
#Saber si las listas de genes son comparables. Para esto puedes hacer una gráfica (scatter) comparando los ranqueos de los genes (un método en el eje X y otro en Y).
#Ver cuáles vías de señalización están alteradas de acuerdo a cada método y compararlas.

library(gtools)
library(dplyr)

load("TCGA_COADREAD_comp_data.RData", verbose = TRUE)
df <- data.frame(tcga_coadread)
type <- data.frame(tcga_coadread_class)
type <- as.vector(type[,1])
yindex <- vector()
oindex <- vector()

#conteo de tipos de cancer
nyoung<-0
nold<-0

#recoleccion de indices
counter1 =1
counter2 =1
for(i in 1:length(type)){
  if(type[i]=="Young"){
    nyoung<-nyoung+1
    yindex[counter1]=i
    counter1=counter1+1
  }else{
    nold<-nold+1
    oindex[counter2]=i
    counter2=counter2+1
  }
}


#T Test
young <- df[,yindex]
old <- df[,oindex]

pvalues <-data.frame(matrix(, nrow=length(df[,1]), ncol=1))

for(i in 1:nrow(df)){
  pvalues[i,1]<-(t.test(df[i,yindex],df[i,oindex])$p.value)
}
colnames(pvalues)<-c("Pvalues")
rownames(pvalues)<-rownames(df)
#write.csv(pvalues,"pvalues.csv", row.names = TRUE)

#Getting mean graphs
type <- data.frame(tcga_coadread_class)
Averages <- data.frame(matrix(0, nrow = length(df[[1]]), ncol = 2))
countYoung <- 0
countOld <- 0
for (i in 1:length(df)) {
  if(type[[1]][i] == "Young"){
    Averages[[1]] = Averages[[1]] +  df[[i]]
    countYoung <- countYoung + 1
  } else{
    Averages[[2]] = Averages[[2]] +  df[[i]]
    countOld <- countOld + 1
  }
} 
for(i in 1:length(Averages[[1]])){
  Averages[[1]][i] = Averages[[1]][i]/countYoung
  Averages[[2]][i] = Averages[[2]][i]/countOld
}
colnames(Averages)<-c("Young","Old")
rownames(Averages)<-rownames(df)
#write.csv(Averages,"Averages_Comparison.csv", row.names = TRUE)

#Filtrado de amonoacidos con el valor de significancia
different_aminoacids <-subset(pvalues,Pvalues<0.05) #significance value
#write.csv(different_aminoacids,"different_aminoacids.csv", row.names = TRUE)

#print(different_aminoacids[order(different_aminoacids$Pvalues),])

#Plotting t test
par(mfrow=c(2,2))
hist(Averages$Young,col=rgb(1,0,0,0.5))
hist(Averages$Old,col=rgb(0,0,1,0.5))
boxplot(young)
boxplot(old)
x11() 
hist(Averages$Young, col=rgb(1,0,0,0.5))
hist(Averages$Old, col=rgb(0,0,1,0.5), add=T)
x11()
par(mfrow=c(2,2))
hist(different_aminoacids$Pvalues)
boxplot(different_aminoacids$Pvalues)
barplot(different_aminoacids$Pvalues)

