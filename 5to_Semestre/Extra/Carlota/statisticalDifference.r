#-----------------------------------------------------
#create a dataframe with 3 columns
italian <- c(12,13,14,16,18,20,17,26)
seafood <- c(15,17,17,27,24,14,20,18)
steakhouse <- c(24,18,22,25,21,21,27,34)

sample.data <- data.frame(italian, seafood, steakhouse)

#alpha is the significance level
alphaValue <- 0.05


data <- rbind(sample.data)

chisq.test(data)

#-----------------------------------------------------

x=c(1,2,3,4,5,6,7,8,9,10)
y=c(6,8,9,10,5,7,4,1,2,3)

golf.data <- data.frame(x,y)

#find the correlation coefficient  and if the result is significant to the alpha value
cor(x, y, method = c("pearson", "kendall", "spearman"))
cor.test(x, y, method=c("pearson", "kendall", "spearman"))

res <- cor.test(x, y,  method = "pearson")
res
res2 <- cor.test(x,y,  method="kendall")
res2