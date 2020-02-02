#numbers=list(map(int,raw_input().split()))
line = raw_input()
linel = [i for i in line]
for i in range(0,len(linel)):
    if linel[i] == "b":
        linel[i] ="d"
    elif linel[i] =="B":
        linel[i] = "D"
    elif line[i] == "d":
        linel[i] = "b"
    elif linel[i] == "D":
        linel[i] = "B"
    #print(linel[i])}
print("".join(str(x) for x in linel))
        