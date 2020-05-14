tTest <- read.csv("order_t_test.csv")
hyper <- read.csv("order_hypergeometric.csv")
namesTest <- matrix(tTest[,1])
namesHyper <- matrix(hyper[,1])
names  <- rep(NA, times = (length(namesTest) + length(namesHyper)))

for(i in 1:length(namesTest)){
  names[i] <- namesTest[i,1]
}
count <- length(namesTest)
for(i in 1:length(namesHyper)){
  if (!namesHyper[i,1] %in% names){
    count <- count + 1
    names[count] <- namesHyper[i,1]
  }
}
names <- sort(names)

vTest <- rep(NA, times = length(names))
vHyper <- rep(NA, times = length(names))

for (i in 1:length(names)) {
  if (names[i] %in% namesTest){
    vTest[i] <- tTest[match(names[i],namesTest),2]
  }
  if (names[i] %in% namesHyper){
    vHyper[i] <- hyper[match(names[i],namesHyper),2]
  }
}

scatter.smooth(vTest, vHyper)


namesCommon  <- rep("", times = length(namesTest))
count2 <- 0
for (i in 1:length(namesTest)){
  if(namesTest[i,1] %in% namesHyper){
    count2 <- count2 + 1
    namesCommon[count2] <- namesTest[i,1]
  }
}
namesCommon <- namesCommon[1:count2]

vTest2 <- rep(NA, times = length(namesCommon))
vHyper2 <- rep(NA, times = length(namesCommon))

for (i in 1:length(namesCommon)) {
  vTest2[i] <- tTest[match(namesCommon[i],namesTest),2]
  vHyper2[i] <- hyper[match(namesCommon[i],namesHyper),2]
}



vCommon = rep(NA, times = 10)
vSuma = rep(200, times = 10)
vPositionsTest = rep(0, times = 10)
vPositionsHyper = rep(0, times = 10)
count <- 0
pos <- 1

for (i in 1:length(namesCommon)) {
  suma <- vTest2[i] + vHyper2[i]
  if (suma < vSuma[10]){
    j <- 1
    while (suma > vSuma[j] && j < 10){
      j <- j + 1
    }
    n <- length(vSuma)
    while (n > j){
      vPositionsTest[n] <- vPositionsTest[n-1]
      vPositionsHyper[n] <- vPositionsHyper[n-1]
      vSuma[n] <- vSuma[n-1]
      n <- n - 1
    }
    vPositionsTest[j] = vTest2[i]
    vPositionsHyper[j] = vHyper2[i]
    vSuma[j] = suma
  }
}

for (i in 1:10){
  vCommon[i] = namesTest[match(vPositionsTest[i],tTest$Pos)]
}

table = data.frame(vCommon, vPositionsTest, vPositionsHyper, vSuma)
print(table)


