out =[]

def twoSum(arr, S):
  sums = []
  hashTable = {}
  for i in range(0, len(arr)):
    sumMinusElement = S - arr[i]
    if sumMinusElement in hashTable:
      sums.append([arr[i], sumMinusElement])
    hashTable[arr[i]] = arr[i]
  return sums

def is_multiple(x, y):
    return x and (y % x) == 0

preguntas,a,b = raw_input().split()
preguntas = int(preguntas)
a = int(a) #paquete 1
b = int(b) #paquete 2

for i in range(preguntas):
    num = int(raw_input())
    if num == 0:
        out.append("NO")
    else:
        if num == a or num == b:
            out.append("SI")
        else:
            arry = []
            arry.append(a)
            arry.append(b)
            arry2 = twoSum(arry,num)
            if not arry2:
                #out.append("NO")
                if is_multiple(a,num) or is_multiple(b,num):
                    out.append("SI")
                else:
                    out.append("NO")
            else:
                out.append("SI")
for i in out:
    print(i)
