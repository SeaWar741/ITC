a, b = raw_input().split()
a = int(a)
b = int(b)
if a == b:
    print("felizmil")
else:
    if a % 2 != 0 and b % 2 != 0:
        print("tristemil")
    elif a % 2 == 0 and b % 2 == 0:
        if a > b:
            if a % b == 0:
                print("felizmil")
            else:
                print("tristemil")
        else:
            if b % a == 0:
                print("felizmil")
            else:
                print("tristemil")
    else:
        if a > b:
            if (a*2) % b == 0:
                print("felizmil")
            else:
                print("tristemil")
        else:
            if (b*2) % a == 0:
                print("felizmil")
            else:
                print("tristemil")