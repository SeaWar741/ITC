n = int(raw_input())
alumnos=list(map(int,raw_input().split()))
alumnos.sort(reverse = True)
print(" ".join(str(x) for x in alumnos))