f = int(raw_input())
personas =11
veces = 0
c = True
while c:
    if (f-1)%personas == 0:
        c= False
        print(veces)
        print(f)
    else:
        veces=veces+1
        c=c+1
        f=f*2