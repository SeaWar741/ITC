library(RISmed)
#query con las palabras
#search <- EUtilsSummary("hepatitis[Ti] AND (virus[Ti] AND child[TI])")
title_list <-vector()

continue <- TRUE
cat("\n\n -----------------------------------------------------------------------\n") 
cat("|Abraham Cepeda,Juan Carlos Garfias,Lucas Eduardo Idígoras y Vanina Sada|\n")
cat(" -----------------------------------------------------------------------\n") 

cat("\n\n")

cat("\n-----------------------------------------------------------------------------------------------------------------------\n")
cat("########  ##     ## ########  ##     ## ######## ########      ######  ########    ###    ########   ######  ##     ## \n")
cat("##     ## ##     ## ##     ## ###   ### ##       ##     ##    ##    ## ##         ## ##   ##     ## ##    ## ##     ## \n")
cat("##     ## ##     ## ##     ## #### #### ##       ##     ##    ##       ##        ##   ##  ##     ## ##       ##     ## \n")
cat("########  ##     ## ########  ## ### ## ######   ##     ##     ######  ######   ##     ## ########  ##       ######### \n")
cat("##        ##     ## ##     ## ##     ## ##       ##     ##          ## ##       ######### ##   ##   ##       ##     ## \n")
cat("##        ##     ## ##     ## ##     ## ##       ##     ##    ##    ## ##       ##     ## ##    ##  ##    ## ##     ## \n")
cat("##         #######  ########  ##     ## ######## ########      ######  ######## ##     ## ##     ##  ######  ##     ##\n")
cat("\n-----------------------------------------------------------------------------------------------------------------------\n\n")

selection <- readline(prompt="Deseas realizar busqueda manual o default? (M/D): ")
if(tolower(selection) == "m"){
    while (continue){
        title <- readline(prompt="Titulo: ")
        add <- readline(prompt="Quieres añadir otro elemento a busqueda? (S/N):")
        title_list <- c(title_list, tolower(title))
        if(tolower(add) !="s"){
            continue<-FALSE
        }
    }
    for(i in 1:length(title_list)){
        if(i != (length(title_list))){
            title_list[i] <- paste(title_list[i],"[Ti] AND ", sep = " ", collapse = NULL)
        }else{
            title_list[i] <- paste(title_list[i],"[Ti]", sep = " ", collapse = NULL)
        }
    }
    search <-paste(title_list, collapse = '')
}else{
    search <- EUtilsSummary("Coronavirus[Ti] AND Covid19[Ti]")
}
records <- EUtilsGet(search)
df <-data.frame('Title'=ArticleTitle(records), 'Abstract'=AbstractText(records), 'PID'=ArticleId(records))

cat("\n-----------------------------------------------------------------------------------------------------------------------\n")
cat("\nCOMENZANDO BUSQUEDA")
for(i in 1:5){
    Sys.sleep(0.6)
    if(i!=5){
        cat(".")
    }else{
        cat(".\n")
    }
}

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
txt<- scan("research.txt", what="character", sep="\n",quiet=TRUE)
#se pasa a minusculas
txt1 <- tolower(txt)
#los separa en p|alabras
txt2 <- strsplit(txt1, "\\W")
Word <- unlist(txt2)
#crea una tabla con todas las palabras y frecuencias
freq<-table(Word)
#las ordena de mayor a menor
freq1<-sort(freq, decreasing=TRUE)

#crea un df de frecuencias
df_f <-data.frame(freq1)
df_f <-df_f[-1,] #borrar primer filas que es un espacio



#Lectura de las palabras no deseadas
forbbiden<- scan("forbidden.txt", what="character", sep="\n", quiet=TRUE)
#se pasa a minusculas
forbbiden <- tolower(forbbiden)
#se cortan/pasan a vector
forbbiden <-unlist(strsplit(forbbiden, ","))

#se eliminan del dataframe esas palabras
for(i in 1:length(forbbiden)){
    df_f<-df_f[!df_f$Word == forbbiden[i], ]
}

#se toman los diez primeros elementos del dataframe
top_ten <- df_f[1:10,]
cat("\n------------------------------------------------------------------------\n") 

cat("\n\n-=Palabras mas frecuentes en la busqueda=-\n\n")

#se imprimen los diez primeros elementos
print(top_ten)
#se crea un vector con las palabras
word_list <- as.vector(top_ten$Word)
#se crea un vector con las frecuencias
frequency <- as.vector(top_ten$Freq)
#se grafica
barplot(frequency, main="Palabras más frecuentes", names.arg=word_list, cex.names=1.5,col = grey.colors(10))

write.csv(df_f,"Palabras_mas_frecuentes.csv", row.names = FALSE)