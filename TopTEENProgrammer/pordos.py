def ___gcd(a,b): 

    if (a == 0 or b == 0): 
        return 0
    if (a == b): 
        return a  
    if (a > b): 
        return ___gcd(a-b, b) 
    return ___gcd(a, b-a) 
  
def lcmOfArray(arr,n): 
    ans = arr[0] 
    for i in range(1,n): 
        ans = (arr[i]*ans)/___gcd(arr[i], ans) 
    return ans 
def checkArray(arr, num, n, m): 
    lcm = lcmOfArray(arr, n) 
    for i in range(n): 
        val = lcm/arr[i] 
        for j in range(m and val!=1): 
            while (val % num[j] == 0): 
                val = val/num[j] 
        if (val != 1): 
            return 0
    return 1
arr=list(map(int,raw_input().split()))
num = [2] 
n = len(arr) 
m = len(num) 
   
if(checkArray(arr, num, n, m)): 
    print("felizmil") 
else: 
    print("tristemil") 
  