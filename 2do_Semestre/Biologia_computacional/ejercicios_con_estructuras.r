a = matrix(c(1,2,3,4,5,6,7,8,9),nrow=3,ncol=3,byrow = TRUE)
print(a)
dimnames(a) = list(c("fila_1","fila_2","fila_3"),c("columna1","columna2","columna3"))
print(a)

b = matrix(c(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16),nrow=4,ncol=4,byrow = TRUE)
print(b)
dimnames(b) = list(c("fila_1","fila_2","fila_3","fila_4"),c("columna_1","columna_2","columna_3","columna_4"))
print(b)

c = as.data.frame(b)
print("Data Frame")
print(c)

d <- list(a,b,c)
print(d)