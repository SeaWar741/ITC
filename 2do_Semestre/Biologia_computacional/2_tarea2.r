#EJERCICIO 1
file <- 'PACIENTES_DE_NUEVO_INGRESO.csv'
dataa <- read.csv(file)

# <-----b)----->
tumores = length(unique(dataa$DESCRIPCION.DIAGNOSTICO))
cat("\n\n -----------------------------------------------------------------------\n") 
cat("|Abraham Cepeda,Juan Carlos Garfias,Lucas Eduardo Idígoras y Vanina Sada|\n")
cat(" -----------------------------------------------------------------------\n") 
cat("\n\n<----Cantidad de tumores diferentes---->\n\n")
cat("CANTIDAD DE TUMORES:\t",tumores) 

estados = sort(table(dataa$ESTADO))
diezEstados = estados[(length(estados)-9):length(estados)] 
cat("\n\n<----Diez estados con mayor número de casos---->\n\n")
print(diezEstados) 

municipios = sort(table(dataa$MUNICIPIO))
diezMunicipios = municipios[(length(municipios)-9):length(municipios)]    
cat("\n\n<----Diez municipios con mayor número de casos---->\n\n")
print(diezMunicipios) 

# <-----c)----->
tumorColonRecto = length(dataa$DESCRIPCION.DIAGNOSTICO[dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO"])
cat("\n\n<----Número de casos de tumor de colon o recto---->\n\n")
cat("TUMOR COLOR/RECTO:",tumorColonRecto)

tumorColonJovenes = length(dataa$DESCRIPCION.DIAGNOSTICO[dataa$EDAD <= 29 & dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON"])
cat("\n\n<----Número de casos de tumor de colon o recto en jóvenes (menor a 29 años)---->\n\n")
cat("NUMERO EN JOVENES:",tumorColonJovenes)

tumorColonJovenesA = length(dataa$DESCRIPCION.DIAGNOSTICO[dataa$EDAD < 50 & dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON"])
cat("\n\n<----Número de casos de tumor de colon o recto en jóvenes adultos (menor a 50 años)---->\n\n")
cat("NUMERO EN JOVENES:",tumorColonJovenesA)

tumorCRE = rev(sort(table(dataa$ESTADO[dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO"])))
cat("\n\n<----Número de casos de tumor de colon o recto por estado---->\n\n")
print(tumorCRE[1:10])

tumorCRM = rev(sort(table(dataa$MUNICIPIO[dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO"])))
cat("\n\n<----Número de casos de tumor de colon o recto por municipio---->\n\n")
print(tumorCRM[1:10])


#EJERCICIO 2
#a) Compara todas las muestras de cáncer contra todos los normales.

#b) Compara las muestras de cada cáncer contra su respectivo normal. En el caso de leucemia o linfoma, usa las muestras normales que dicen “Germinal” y “peripheral blood”; para glioblastoma usa “whole brain” y para meduloblastoma usa “cerebellum”. Describe también por qué se deben hacer así estas comparaciones.

#c) Compara si los genes con medias más diferentes en las comparaciones de cánceres individuales son similares al de la comparación de todas las muestras. Comenta en especial para el caso de cáncer colorectal.
cat("_________________________________________________________________________________________________________________\n\n")
load("Multi_Cancer_Data.RData", verbose = FALSE)
df <- data.frame(multi_cancer_data)

#cat(colnames(dataFile))
tumors <- df[,1:190]
normal <- df[,191:280]
#write.csv(tumors,"tumors.csv", row.names = FALSE)
#write.csv(normal,"normal.csv", row.names = FALSE)

#obtiene promedios
meandt <-as.data.frame(t(apply((tumors),MARGIN=2,FUN=mean)))
meann <-as.data.frame(t(apply((normal),MARGIN=2,FUN=mean)))
#cat(length(meann))


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
diff_avg <- totalm_dt-totalm_dn

cat("-=COMPARACION GENERAL TUMORES CONTRA NORMALES=-\n\n")
cat("\nPROMEDIO TUMORES:",totalm_dt,"| PROMEDIO NOMRALES:",totalm_dn,"| DIFERENCIA:",diff_avg,"\n", sep="\t")

#b)

#renombrar columnas
for(i in 1:190){
  #gets col name
  name <-colnames(meandt)[i]
  name <-gsub("Tumor__","",name)
  names<-strsplit(name, '_')
  name <-names[[1]][1]
  #cat(name)
  colnames(meandt)[i] <- name
}
write.csv(meandt,"renamed_T.csv", row.names = FALSE)

for(i in 1:90){
  #gets col name
  name <-colnames(meann)[i]
  name <-gsub("Normal__","",name)
  names<-strsplit(name, '_')
  name <-names[[1]][1]
  #cat(name)
  colnames(meann)[i] <- name
}

#type_list = unique(colnames(meann))
type_list_n = unique(colnames(meann))
type_list_t = unique(colnames(meandt))
type_list = unique(c(type_list_n,type_list_t))

vector_tumor = rep(c(0), times=20)
vector_tumorc = rep(c(0), times=20)
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
vector_normal = rep(c(0), times=20)
vector_normalc = rep(c(0), times=20)
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

vector_dif <-rep(c(0), times=20)
for (i in 1:20){
  vector_dif[i]= as.numeric(vector_tumor[i])-as.numeric(vector_normal[i])
}

table_comparison  <- matrix(0, 20, 3)

for(i in 1:20){
  table_comparison[i,1] = vector_tumor[[i]]
  table_comparison[i,1] = vector_normal[[i]]
  table_comparison[i,3] = vector_dif[[i]]
}

rownames(table_comparison) <- c(type_list)
colnames(table_comparison) <- c("Tumor","Normal","Diferencia")
cat("\n\n")
cat("-=COMPARACION DE TUMORES CONTRA NORMALES=-\n\n")
print(table_comparison)

