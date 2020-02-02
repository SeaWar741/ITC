import math
n = int(raw_input())
triangles =[]
answers= []
for i in range(n):
    triangles.append(float(raw_input()))
for i in triangles:
    h = math.sqrt(pow(i,2)-pow(i/2,2))
    answers.append(h)
for i in answers:
    print(round(i,2))