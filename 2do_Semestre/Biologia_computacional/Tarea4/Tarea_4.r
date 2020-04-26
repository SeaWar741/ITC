#Tu profesor te entregará  un archivo de texto donde se describe la base de datos por usar, una descripción y las comparaciones que se deben hacer de acuerdo a la situación problema. Deberás obtener los genes diferencialmente expresados usando una prueba t-Student (ttest en R) y el paquete de R LIMMA. Una vez que tengas los genes diferencialmente expresados, calcularás el enriquecimiento para vías de señalización celular usando una prueba hiper-geométrica. Al final harás la interpretación sobre las funciones celulares que están alteradas en cáncer.
#Vas a generar un reporte que contenga lo siguiente:
#Genes diferencialmente expresados usando cada método.
#Saber si las listas de genes son comparables. Para esto puedes hacer una gráfica (scatter) comparando los ranqueos de los genes (un método en el eje X y otro en Y).
#Ver cuáles vías de señalización están alteradas de acuerdo a cada método y compararlas.

library(gtools)

load("TCGA_COADREAD_comp_data.RData", verbose = TRUE)
df <- data.frame(tcga_coadread)
type <- data.frame(tcga_coadread_class)
type <- as.vector(type[,1])
yindex <- vector()
oindex <- vector()

nyoung<-0
nold<-0

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
write.csv(pvalues,"pvalues.csv", row.names = TRUE)

#Getting mean graphs
type <- data.frame(tcga_coadread_class)
dataNew <- data.frame(matrix(0, nrow = length(df[[1]]), ncol = 2))
countYoung <- 0
countOld <- 0
for (i in 1:length(df)) {
  if(type[[1]][i] == "Young"){
    dataNew[[1]] = dataNew[[1]] +  df[[i]]
    countYoung <- countYoung + 1
  } else{
    dataNew[[2]] = dataNew[[2]] +  df[[i]]
    countOld <- countOld + 1
  }
} 
for(i in 1:length(dataNew[[1]])){
  dataNew[[1]][i] = dataNew[[1]][i]/countYoung
  dataNew[[2]][i] = dataNew[[2]][i]/countOld
}
#colnames(dataNew)<-colnames(df)
write.csv(dataNew,"Averages_Comparison.csv", row.names = TRUE)

#Plotting t test
par(mfrow=c(2,2))
hist(dataNew$X1)
hist(dataNew$X2)
boxplot(young)
boxplot(old)

hist(pvalues$Pvalues)
barplot(pvalues$Pvalues)

plot(dataNew$X2,c(1:length(dataNew$X2)))

#hypergeometric-test
  #phyper(q, m, n, k, lower.tail = TRUE, log.p = FALSE)

  #x, q vector of quantiles representing the number of white balls drawn
  #without replacement from an urn which contains both black and white
  #balls.

  #m the number of white balls in the urn.

  #n the number of black balls in the urn.

  #k the number of balls drawn from the urn.

  #https://www.stat.auckland.ac.nz/~ihaka/787/lectures-quantiles.pdf