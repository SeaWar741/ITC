inp = list(map(int,raw_input().split()))
#dinero n dias
#carlos compra k pizzas durante n dias
days = list(map(int,raw_input().split()))
tot =0
for i in days:
    tot= (i*inp[1])+tot
print(tot)