cases = int(raw_input())
for i in range(cases):
    oveja = 0
    subcases = int(raw_input())
    for i in range(subcases):
        animal = raw_input()
        if animal == "oveja":
            oveja+=1
    print(oveja)