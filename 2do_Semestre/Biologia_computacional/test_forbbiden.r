#Lectura de los abstracts
txt<- scan("forbidden.txt", what="character", sep="\n")
#se pasa a minusculas
txt1 <- tolower(txt)

forbbiden <-unlist(strsplit(txt1, ","))
print(forbbiden)