# <-----------Packages and import----------->
library(seqinr)
dataFile = read.fasta("TTN.fasta", strip.desc = TRUE)

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
  if(letter == dataFile[[1]][initialVal + vtrNum]){
    num = getNewRep(letter, 1, initialVal, vtrNum, dataFile)
    return(num)
  } else{
    return(vtrNum)
  }
}

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
cat("Porcentaje de A:", (vtrCount[1] * 100) / total)
cat("Porcentaje de C:", (vtrCount[2] * 100) / total)
cat("Porcentaje de G:", (vtrCount[3] * 100) / total)
cat("Porcentaje de T:", (vtrCount[4] * 100) / total)
cat("Porcentaje de A:", (vtrCount[1] * 100) / total)

# <-----------REPETICIONES----------->
cat("Repeticiones de A:", vtrRep[1])
cat("Repeticiones de C:", vtrRep[2])
cat("Repeticiones de G:", vtrRep[3])
cat("Repeticiones de T:", vtrRep[4])