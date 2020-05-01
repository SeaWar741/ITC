cat("\n\n -----------------------------------------------------------------------\n") 
cat("|Abraham Cepeda,Juan Carlos Garfias,Lucas Eduardo Idígoras y Vanina Sada|\n")
cat(" -----------------------------------------------------------------------\n") 
#Lectura de datos Cosmic
cosmic <-  read.delim(file="cosmic_data.csv", sep=",", as.is=T)
cat("\n\nSize cosmic\n")
print(dim(cosmic))
cat("\n\nCosmic 1-2\n")
print(as.data.frame(cosmic[1:2,]))

cat("\n\nTabla cosmic")
print(table(cosmic$Sample.Type))

#filtrar mutaciones por tipo de muestra y conservar tumor sample
cosmic <- cosmic[which(cosmic$Sample.Type == "Tumour Sample"),]
#Estatus somático, quitar variantes de origen
cat("\n\nTabla de cosmic estatus somatico")
print(table(cosmic$Somatic.Status))

cosmic <- cosmic[-which(cosmic$Somatic.Status == "Variant of unknown origin"),]

#Lectura de datos gnomAD
gnomAD <-  read.delim(file="gnomad_data.csv", sep=",", as.is=T)
#por tipo de mutacion
cat("\n\nTabla gnomad por tipo de mutacion")
print(table(gnomAD$Annotation))
#añadir variables conjuntas
aux_loc <- unlist(strsplit(x=cosmic$Genomic.Co.ordinates, split=":"))[seq(from=2, to=nrow(cosmic)*2, by=2)]
cat("\n\nVariables comunes entre cosmic y gnomad\n")
print(aux_loc[1:5])

aux_loc2 <- unlist(strsplit(x=aux_loc, split="\\.\\."))
print(aux_loc[1:6])

#Los elementos impares son el inicio de la locación de la mutación y los elementos pares son el final
cosmic$start <- aux_loc2[seq(from=1, to=nrow(cosmic)*2, by=2)]
cosmic$end <- aux_loc2[seq(from=2, to=nrow(cosmic)*2, by=2)]

#comparar cantidad de locaciones de variantes
cosmic_pos <- sort(as.numeric(unique(c(cosmic$start, cosmic$end))))
gnomAD_pos <- sort(unique(gnomAD$Position))

#obtener posiciones 
cosmic_pos <- sort(as.numeric(unique(c(cosmic$start,cosmic$end))))
gnomAD_pos <- sort(unique(gnomAD$Position))

cat("\n\nRangos de secuencias\n")
#rango secuencia cosmic
print(range(cosmic_pos))
#rango secuencia gnomAD
print(range(gnomAD_pos))
#longitud
cat("\n\nLongitud de secuencias\n")
print(diff(range(cosmic_pos)))
print(diff(range(gnomAD_pos)))

#mutaciones de alelos mayor a 1000
cat("\n\nMutaciones de alelos mayor a 1000\n")
gnomAD[which(gnomAD$Allele.Count > 1000),c(1:5,9,10,12,14:16)]
sort(table(cosmic$AA.Mutation),decreasing=T)
print(as.data.frame(sort(table(cosmic$AA.Mutation),decreasing=T)))
barplot(sort(table(cosmic$AA.Mutation),decreasing=T))

#mutaciones en mas de 1000 muestras
cat("\n\nMutaciones en mas de 1000 muestras\n")
cosmic[c(30181556,26806567,27502118),c(1,2,4,6,7,9,16,17,19:21)]
print(cosmic[c(30181556,26806567,27502118),c(1,2,4,6,7,9,16,17,19:21)])

#mutacion presente en gnomAD
cat("\n\nMutacion presente en gnomAD\n")
gnomAD[which(gnomAD$Position == 25398284),c(1:5,9,10,12,14:16)]
print(gnomAD[which(gnomAD$Position == 25398284),c(1:5,9,10,12,14:16)])

#mutaciones mas frecuentes en gnomAD y en cosmic
cat("\n\nMutacion presente en gnomAD y en cosmic\n")
cosmic[which(cosmic$start %in% c(30181556,26806567,27502118))[1],]
print(cosmic[which(cosmic$start %in% c(30181556,26806567,27502118))[1],])
