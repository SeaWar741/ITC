def are_permutations(str1, str2): 
 return (len(str1) == len(str2) and sorted(str1) == sorted(str2))
number = raw_input()
list1 = raw_input()
list2 = raw_input()
if are_permutations(list1,list2) == True:
    print("SI")
else:
    print("NO")
