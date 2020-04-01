# <-----------Packages and import----------->
library(seqinr)


# <-----------Functions----------->
getNewRep <- function(letter, c, initialVal,vtrNum, dataFile){
  if(dataFile[[1]][initialVal+c] == letter){
    c = c + 1
    getNewRep(letter, c, initialVal,vtrNum, dataFile)
  } else if(c > vtrNum){
    return(c)
  } else{
    return(vtrNum)
  }
}
checkRep <- function(letter, initialVal, vtrNum, dataFile){
  if(initialVal + vtrNum < length(dataFile[[1]])){
    if(letter == dataFile[[1]][initialVal + vtrNum]){
      num = getNewRep(letter, 1, initialVal, vtrNum, dataFile)
      return(num)
    } else{
      return(vtrNum)
    }
  } else{
    return(vtrNum)
  }
}

read_genome <-function(dataFile){
  total = length(dataFile[[1]])
  vtrCount = c(0,0,0,0)
  vtrRep = c(5,5,5,5)
  for(i in 1:length(dataFile[[1]])){
      if(dataFile[[1]][i] == "a"){
        vtrCount[1] = vtrCount[1] + 1
        vtrRep[1] = checkRep(dataFile[[1]][i], i, vtrRep[1], dataFile)
      } else if(dataFile[[1]][i] == "c"){
        vtrCount[2] = vtrCount[2] + 1
        vtrRep[2] = checkRep(dataFile[[1]][i], i, vtrRep[2], dataFile)
      } else if(dataFile[[1]][i] == "g"){
        vtrCount[3] = vtrCount[3] + 1
        vtrRep[3] = checkRep(dataFile[[1]][i], i, vtrRep[3], dataFile)
      } else if(dataFile[[1]][i] == "t"){
        vtrCount[4] = vtrCount[4] + 1
        vtrRep[4] = checkRep(dataFile[[1]][i], i, vtrRep[4], dataFile)
      }
  }
  # <-----------PORCENTAJE----------->
  print(cat("Porcentaje de A:", ((vtrCount[1] * 100) / total), "\n"))
  print(cat("Porcentaje de C:", ((vtrCount[2] * 100) / total), "\n"))
  print(cat("Porcentaje de G:", ((vtrCount[3] * 100) / total), "\n"))
  print(cat("Porcentaje de T:", ((vtrCount[4] * 100) / total), "\n"))

  # <-----------REPETICIONES----------->
  print(cat("Repeticiones de A:", vtrRep[1], "\n"))
  print(cat("Repeticiones de C:", vtrRep[2], "\n"))
  print(cat("Repeticiones de G:", vtrRep[3], "\n"))
  print(cat("Repeticiones de T:", vtrRep[4], "\n"))
}

ttn = read.fasta("TTN.fasta", strip.desc = TRUE)
tc77l2 = read.fasta("TCF7L2.fasta", strip.desc = TRUE)

print("SECUENCIA TTN:")
read_genome(ttn)
print("\nSECUENCIA TCF7L2:")
read_genome(tcf7l2)