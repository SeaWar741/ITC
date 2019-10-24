number =list(raw_input())
numbera = ["0","0","0"]
if len(number) == len(numbera):
    for i in range(3):
        numbera[i] = number[i]
elif len(number) == len(numbera)-1:
    for i in range(0,2):
        numbera[i]=number[i-1]
else:
    numbera[2]=number[0]
numbera =numbera[::-1]
#print(numbera)
inverse = "".join(str(x) for x in numbera)
#for i in range(3):
#    if i == 0:
#        if numbera[i] != "0":
#            inverse = inverse+numbera[i]
#    else:
#        if numbera[i-1] !=0 and numbera[i] != 0:
#            inverse = inverse+numbera[i]

print(int(inverse))