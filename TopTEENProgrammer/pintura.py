number = int(raw_input())
listn = list(map(int,raw_input().split()))
flag = len(set(listn)) == len(listn) 
zeros = listn.count(0)
if flag:
    print(1)
else:
    print(len(listn))
