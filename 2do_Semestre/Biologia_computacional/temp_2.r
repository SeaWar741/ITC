#a) Compara todas las muestras de cáncer contra todos los normales.

#b) Compara las muestras de cada cáncer contra su respectivo normal. En el caso de leucemia o linfoma, usa las muestras normales que dicen “Germinal” y “peripheral blood”; para glioblastoma usa “whole brain” y para meduloblastoma usa “cerebellum”. Describe también por qué se deben hacer así estas comparaciones.

#c) Compara si los genes con medias más diferentes en las comparaciones de cánceres individuales son similares al de la comparación de todas las muestras. Comenta en especial para el caso de cáncer colorectal.



load("Multi_Cancer_Data.RData", verbose = TRUE)
df <- data.frame(multi_cancer_data)

#print(colnames(dataFile))
tumors <- df[,1:190]
normal <- df[,191:280]
#write.csv(tumors,"tumors.csv", row.names = FALSE)
#write.csv(normal,"normal.csv", row.names = FALSE)

#obtiene promedios
meandt <-as.data.frame(t(apply((tumors),MARGIN=2,FUN=mean)))
meann <-as.data.frame(t(apply((normal),MARGIN=2,FUN=mean)))
#print(length(meann))


#a)
totalm_dt= 0
for(i in 1:190){
  totalm_dt<-totalm_dt+ meandt[1,i]
}
totalm_dn <-0
for(j in 1:90){
  totalm_dn<-totalm_dn+ meann[1,j]
}

totalm_dt <- totalm_dt/190
totalm_dn <- totalm_dn/90
diff_avg <- abs(totalm_dt-totalm_dn)

cat("\nPROMEDIO TUMORES:",totalm_dt,"| PROMEDIO NOMRALES:",totalm_dn,"| DIFERENCIA:",diff_avg,"\n", sep="\t")

#test

#renombrar columnas
for(i in 1:190){
  #gets col name
  name <-colnames(meandt)[i]
  name <-gsub("Tumor__","",name)
  names<-strsplit(name, '_')
  if (names[[1]][1] == "CNS"){
    if(names[[1]][2] == "Glioblastoma"){
      name <- paste("Whole", names[[1]][2], sep="_")
    } else{
      name <- paste("Cerebellum", names[[1]][2], sep="_")
    }
  } else if (names[[1]][1] == "Leukemia"){
    name <- paste("Germinal", names[[1]][1], sep="_")
  } else if (names[[1]][1] == "Lymphoma"){
    name <- paste("Peripheral", names[[1]][1], sep="_")
  } else{
    name <- names[[1]][1]
  }
  colnames(meandt)[i] <- name
}
write.csv(meandt,"renamed_T.csv", row.names = FALSE)

for(i in 1:90){
  #gets col name
  name <-colnames(meann)[i]
  name <-gsub("Normal__","",name)
  names<-strsplit(name, '_')
  
  if (names[[1]][1] == "Germinal"){
    name <- paste(names[[1]][1], "Leukemia", sep="_")
  } else if (names[[1]][1] == "Peripheral"){
    name <- paste(names[[1]][1], "Lymphoma", sep="_")
  } else if (names[[1]][1] == "Whole"){
    name <- paste(names[[1]][1], "Glioblastoma", sep="_")
  } else if (names[[1]][1] == "Cerebellum"){
    name <- paste(names[[1]][1], "Medulloblastoma", sep="_")
  } else{
    name <-names[[1]][1]
  }
  #print(name)
  colnames(meann)[i] <- name
}

#type_list = unique(colnames(meann))
type_list_n = unique(colnames(meann))
type_list_t = unique(colnames(meandt))
type_list = unique(c(type_list_n,type_list_t))

vector_tumor = rep(c(0), times=17)
vector_tumorc = rep(c(0), times=17)
count = 1
acum = 0

for(i in 1:190){
  for(j in 1:length(type_list)){
    if(colnames(meandt[i]) == type_list[j]){
      vector_tumorc[j] = vector_tumorc[j] + 1
      vector_tumor[j] = vector_tumor[j] + meandt[i]
    }
  }
}

for (i in 1:length(type_list)) {
  n = vector_tumor[i]
  c = vector_tumorc[i]
  prom = as.numeric(n) / as.numeric(c)
  vector_tumor[i] = prom
}

# normal
vector_normal = rep(c(0), times=17)
vector_normalc = rep(c(0), times=17)
count = 1
acum = 0

for(i in 1:90){
  for(j in 1:length(type_list)){
    if(colnames(meann[i]) == type_list[j]){
      vector_normalc[j] = vector_normalc[j] + 1
      vector_normal[j] = vector_normal[j] + meann[i]
    }
  }
}

for (i in 1:length(type_list)) {
  n = vector_normal[i]
  c = vector_normalc[i]
  prom = as.numeric(n) / as.numeric(c)
  vector_normal[i] = prom
}


vector_dif <-rep(c(0), times=length(type_list))
for (i in 1:length(type_list)){
  vector_dif[i]= abs(as.numeric(vector_tumor[i])-as.numeric(vector_normal[i]))
}

table_comparison  <- matrix(0, length(type_list), 4)

for(i in 1:length(type_list)){
  table_comparison[i,1] = vector_tumor[[i]]
  table_comparison[i,2] = vector_normal[[i]]
  table_comparison[i,3] = vector_dif[[i]]
  table_comparison[i,4] =abs (vector_tumor[[i]]-totalm_dt)
}

rownames(table_comparison) <- c(type_list)
colnames(table_comparison) <- c("Tumor","Normal","Diferencia","Difrenecia con media total")
cat("\n\n")
cat("-=COMPARACION DE TUMORES CONTRA NORMALES=-\n\n")
print(table_comparison)

type_list[18] = "Media total"
vector_f <- (c(vector_dif,diff_avg))
barplot(vector_f, main="Diferencias con promedio", names.arg=type_list, cex.names=0.4)