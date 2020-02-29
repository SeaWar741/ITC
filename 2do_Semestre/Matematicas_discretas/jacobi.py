
funcion = [[5.,-2.,3.],[-3.,9.,1.],[2.,-1.,-7.]]
res=[-1.,2.,3.]
x0=1
y0=3
z0=5

for i in range(10):
    x=(funcion[0][1]*y0+funcion[0][2]*z0-res[0])/-1*funcion[0][0]
    y=(-funcion[1][0]*x0+funcion[1][2]*z0-res[1])/-1*funcion[1][1]
    z=(-1*res[2]+funcion[2][0]*x0+funcion[2][1]*y0)/-1*funcion[2][2]
    x0=x
    y0=y
    z0=z
    print(str(x)+" "+str(y)+" "+str(z))

print("-*-*-*-*-*")
x0=1
y0=3
z0=5

x=(-1+2*y0-3*z0)/3
y=(2+3*x0-z0)/9
z=(3-2*x0+y0)/7

for i in range(10):
    x=(12+y0-2*z0)/5
    y=(-25+3*x0+2*z0)/8
    z=(6*x0-y0)
    x=(-1+2*y0-3*z0)/3
    y=(2+3*x0-z0)/9
    z=(3-2*x0+y0)/7
    x0=x
    y0=y
    z0=z
    print(str(x)+" "+str(y)+" "+str(z))
