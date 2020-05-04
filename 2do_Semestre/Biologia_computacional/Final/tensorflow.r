library(tidyverse)
library(keras)
library(ggplot2)
library(dplyr)
library(RColorBrewer)


load("TCGA_COADREAD_comp_data.RData", verbose = FALSE)
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
#Divididos
young <- t(df[,yindex])
old <- t(df[,oindex])


#Clustering Young
set.seed(2345)
kmeans.ani(young, 3)
young_cluster <- kmeans(young, 3)

kmean_withinss <- function(k) {
    cluster <- kmeans(young, k)
    return (cluster$tot.withinss)
}
print("Total within clusters sum of squares")
print(kmean_withinss(2))

#start of algorithm
# Set maximum cluster 
max_k <-20 
# Run algorithm over a range of k 
wss <- sapply(2:max_k, kmean_withinss)
# Create a data frame to plot the graph
elbow <-data.frame(2:max_k, wss)
# Plot the graph with gglop
ggplot(elbow, aes(x = X2.max_k, y = wss)) +
    geom_point() +
    geom_line() +
    scale_x_continuous(breaks = seq(1, 20, by = 1))

print("Cluster size")
print(young_cluster$size)

Sys.sleep(10)

#---------------------------------------------------------------
set.seed(2345)
kmeans.ani(old, 3)
old_cluster <- kmeans(old, 3)

kmean_withinss <- function(k) {
    cluster <- kmeans(old, k)
    return (cluster$tot.withinss)
}
print("Total within clusters sum of squares")
print(kmean_withinss(2))

#start of algorithm
# Set maximum cluster 
max_k <-20 
# Run algorithm over a range of k 
wss <- sapply(2:max_k, kmean_withinss)
# Create a data frame to plot the graph
elbow <-data.frame(2:max_k, wss)
# Plot the graph with gglop
ggplot(elbow, aes(x = X2.max_k, y = wss)) +
    geom_point() +
    geom_line() +
    scale_x_continuous(breaks = seq(1, 20, by = 1))

print("Cluster size")
print(young_cluster$size)