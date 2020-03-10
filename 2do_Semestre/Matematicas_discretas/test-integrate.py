import sympy as sym
x = sym.Symbol('x')
print(float(sym.integrate(x**3, (x, -1, 50))))