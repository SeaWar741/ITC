years = int(raw_input())
yearlist = []
for i in range(years):
    year = int(raw_input())
    yearlist.append(year)
for i in yearlist:
    if i%4 == 0 and i%100 !=0 or i%100 == 0 and i%400 == 0:
        print("S")
    else:
        print("N")