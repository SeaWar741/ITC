userinput = list(map(int,raw_input().split()))
numbers = [userinput[1],userinput[2]]
def combinations(arry,suma):
    for i in arry:
        left = suma-i
        values = arry[i]+","+