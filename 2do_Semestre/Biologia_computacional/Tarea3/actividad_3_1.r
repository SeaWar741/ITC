#se importa la libreria
library(RISmed)
#vector para almacenar palabras para query
title_list <-vector()
#variable para continuar añadiendo palabras a query
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

#  <---------------------Search query-------------------->
selection <- readline(prompt="Deseas realizar busqueda manual o default? (M/D): ")
if(tolower(selection) == "m"){ #si selecciona m --> manual
  while (continue){ #mientras que continue sea positivo preguntar palabras
    title <- readline(prompt="Titulo: ")
    add <- readline(prompt="Quieres añadir otro elemento a busqueda? (S/N):")
    title_list <- c(title_list, tolower(title))
    if(tolower(add) !="s"){ #opcion para romper añadiendo mas palabras
      continue<-FALSE
    }
  }
  for(i in 1:length(title_list)){#for loop que hace append de strings para formato de query
    if(i != (length(title_list))){
      title_list[i] <- paste(title_list[i],"[Ti] AND ", sep = "", collapse = NULL)
    }else{
      title_list[i] <- paste(title_list[i],"[Ti]", sep = "", collapse = NULL)
    }
  }
  query <-paste(title_list, collapse = '') 
  search <- EUtilsSummary(query)#se realiza la query
}else{
  #search <- EUtilsSummary("Coronavirus[Ti] AND Covid19[Ti]")
  search <- EUtilsSummary("hepatitis[Ti] AND (virus[Ti] AND child[TI])") #se realiza query default
}
records <- EUtilsGet(search)#se busca todos los articulos
#se crea dataframe con todos los articulos, abstracts y pids
df <-data.frame('Title'=ArticleTitle(records), 'Abstract'=AbstractText(records), 'PID'=ArticleId(records))

cat("\n-----------------------------------------------------------------------------------------------------------------------\n")
cat("\nCOMENZANDO BUSQUEDA")
#animacion de cargando
for(i in 1:5){
  Sys.sleep(0.6)
  if(i!=5){
    cat(".")
  }else{
    cat(".\n")
  }
}


#  <---------------------titles-------------------->
#Concatenar todos los titulos de las investigaciones
titles = ""
for(i in 1:nrow(df)){
  words <-toString(df[i,1])
  titles <-paste(titles, words, sep = "")
}
#Se guardan los abstracts concatenados como txt
fileTitlesCon<-file("titles.txt")
writeLines(titles, fileTitlesCon)
close(fileTitlesCon)

#Lectura de los abstracts
title <- scan("titles.txt", what="character", sep="\n",quiet=TRUE)
title_words <- unlist(strsplit(tolower(title), "\\W"))
title_freq <- sort(table(title_words), decreasing = TRUE)

#crea un df de frecuencias
df_title <- data.frame(title_freq)
df_title <- df_title[-1,] #borrar primer filas que es un espacio

#  <---------------------Abstracts-------------------->
#Concatenar todos los abstracts de las investigaciones
abstracts = ""
for(i in 1:nrow(df)){
  words <-toString(df[i,2])
  abstracts <-paste(text, words, sep = "")
}
#Se guardan los abstracts concatenados como txt
file_abstract_con<-file("abstracts.txt")
writeLines(abstracts, file_abstract_con)
close(file_abstract_con)

#Lectura de los abstracts
abstract <- scan("abstracts.txt", what="character", sep="\n",quiet=TRUE)
abstract_words <- unlist(strsplit(tolower(abstract), "\\W"))
abstract_freq <- sort(table(abstract_words), decreasing=TRUE)

#crea un df de frecuencias
df_abstract <- data.frame(abstract_freq)
df_abstract <- df_abstract[-1,] #borrar primer filas que es un espacio


#  <---------------------Forbidden-------------------->
#Lectura de las palabras no deseadas
forbbiden<- scan("forbidden.txt", what="character", sep="\n", quiet=TRUE)
#se pasa a minusculas
forbbiden <- tolower(forbbiden)
#se cortan/pasan a vector
forbbiden <-unlist(strsplit(forbbiden, ","))

#  <---------------------Eliminate Forbidden-------------------->
#se eliminan del dataframe esas palabras
for(i in 1:length(forbbiden)){
  df_abstract <- df_abstract[!df_abstract$abstract_words == forbbiden[i], ]
  df_title <- df_title[!df_title$title_words == forbbiden[i], ]
}


#  <---------------------Print title words-------------------->
#se toman los diez primeros elementos del dataframe
top_ten_title <- df_title[1:10,]
cat("\n------------------------------------------------------------------------\n") 

cat("\n\n-=Palabras mas frecuentes en la busqueda de titulos=-\n\n")

#se imprimen los diez primeros elementos
print(top_ten_title)
#se crea un vector con las palabras
word_list_title <- as.vector(top_ten_title$title_words)
#se crea un vector con las frecuencias
frequency_title <- as.vector(top_ten_title$Freq)
#se grafica
barplot(frequency_title, main="Palabras más frecuentes", names.arg=word_list_title, cex.names=1.5, col = grey.colors(10))

write.csv(df_title,"Palabras_mas_frecuentes_titlet.csv", row.names = FALSE)


#  <---------------------Print abstract words-------------------->
#se toman los diez primeros elementos del dataframe
top_ten_abstract <- df_abstract[1:10,]
cat("\n------------------------------------------------------------------------\n") 

cat("\n\n-=Palabras mas frecuentes en la busqueda de abstract=-\n\n")

#se imprimen los diez primeros elementos
print(top_ten_abstract)
#se crea un vector con las palabras
word_list_asbtract <- as.vector(top_ten_abstract$abstract_words)
#se crea un vector con las frecuencias
frequency_abstract <- as.vector(top_ten_abstract$Freq)
#se grafica
#barplot(frequency_abstract, main="Palabras más frecuentes", names.arg=word_list_asbtract, cex.names=1.5, col = grey.colors(10))

write.csv(df_abstract,"Palabras_mas_frecuentes_abstract.csv", row.names = FALSE)