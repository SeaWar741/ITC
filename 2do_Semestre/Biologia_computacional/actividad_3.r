library(RISmed)
search <- EUtilsSummary("hepatitis[Ti] AND (virus[Ti] AND child[TI])")
records <- EUtilsGet(search)
df <-data.frame('Title'=ArticleTitle(records), 'Abstract'=AbstractText(records), 'PID'=ArticleId(records))

#Concatenar todos los abstracts de las investigaciones
text =""
for(i in 1:nrow(df)){
    words <-toString(df[i,2])
    text <-paste(text, words, sep = "")
}
#Se guardan los abstracts concatenados como txt
fileConn<-file("research.txt")
writeLines(text, fileConn)
close(fileConn)


#Lectura de los abstracts
txt<- scan("research.txt", what="character", sep="\n")
#se pasa a minusculas
txt1 <- tolower(txt)
#los separa en p|alabras
txt2 <- strsplit(txt1, "\\W")
txt3 <- unlist(txt2)
#crea una tabla con todas las palabras y frecuencias
freq<-table(txt3)
#las ordena de mayor a menor
freq1<-sort(freq, decreasing=TRUE)

#crea un df de frecuencias
df_f <-data.frame(freq1)
df_f <-df_f[-1,] #borrar primer filas que es un espacio

#crea una lista de palabras no deseadas (articulos, adjetivos)

#Lectura de los abstracts
forbbiden<- scan("forbidden.txt", what="character", sep="\n")
#se pasa a minusculas
forbbiden <- tolower(txt)

forbbiden <-unlist(strsplit(txt1, ","))

df_f2<-data.frame()

for(i in 1:nrow(df_f)){
    for(j in 1:length(forbbiden)){
        if(df_f[i,1]==forbbiden[j]){
            df_f2<-df_f[-i,]
        }
    }
}
#se tiene que leer un archivo txt con las palabras no deseadas
#se hace un split por cada coma y se crea un vector con todas las palabras no deseadas
#se itera sobre el dataframe con variable i
#se itera sobre la lista de palabras no deseadas con variable j
#si la palabra del dataframe es igual a la de las palabras no deseadas se borra esa fila

#eso en teoria deberia de eliminar todas las palabras no medicas y no deseadas
#ya con eso se hace una grafica de frecuencia o de barras la que sea mejor 
#y ya queda la parte 1

write.csv(df_f2,"Frequencies.csv", row.names = FALSE)
