word = raw_input()
if word.isalpha():
    if word == word.lower():
        print("MINUSCULA")
    else:
        print("MAYUSCULA")
else:
    print("OTRO")