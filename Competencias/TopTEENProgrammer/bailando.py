n = int(raw_input())
chicas =[]
for i in range(n):
    chicas.append(raw_input())
    chicas.append(raw_input())
deseo = raw_input()
if chicas[chicas.index(deseo)+1].lower() == "si":
    print("Si")
else:
    print("No") 