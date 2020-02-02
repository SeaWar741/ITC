sizep = int(raw_input())
password = raw_input()
secure = False
vocals = ["a","e","i","o","u"]
#Contains vocal
vocal = False
for i in vocals:
    if i in password:
        vocal = True
#No 2 or more caracters
caracter=True

#12 characters
twelve = False
if sizep >= 12:
    twelve = True
#Contains number
numberc = False
for i in password:
    if i.isdigit():
        numberc = True
#validate
print(vocal)
print(caracter)
print(twelve)

if vocal == True and caracter == True and twelve == True:
    print("SEGURO")
else:
    print("INSEGURO")
