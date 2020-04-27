hyper <- read.csv("order_hypergeometric.csv")
ttest <- read.csv("order_t_test.csv")

size <- length(ttest$Pos)
names <- ttest[,1]
posh <-replicate(length(hyper[,1]), 0)
post <-replicate(length(ttest[,1]), 0)

for(i in 1:length(names)){
    for(j in 1:length(hyper[,1])){
        if(hyper[j,1]==names[i]){
            posh[i] =hyper[j,2]
        }
    }
}
for(i in 1:length(names)){
    for(j in 1:length(ttest[,1])){
        if(ttest[j,1]==names[i]){
            post[i] =ttest[j,2]
        }
    }
}


nombres <- [TTA,PPA,PFE]
vtest <- [0,0,0]
vhyper <-[0,0,0]

HACES FORS

plot(vtest,hyper)