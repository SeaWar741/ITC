n = int(raw_input())
numb=list(map(int,raw_input().split()))
numba= sorted(numb,reverse=False)
numbd = sorted(numb,reverse=True)

if numb == numba:
    print("CRECIENTE")
elif numb == numbd:
    print("DECRECIENTE")
else:
    print("NO ORDENADA")