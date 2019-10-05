#tomaras el numero minio de monedas, cuya suma de valores es estrictamente mayor que la suma de los valores de las monedas restantes

def printSubArray(arr, start, end): 
    print ("[ ") 
    for i in range(start, end+1): 
        print (arr[i]) 
    print ("]") 
  
# Function that divides the array into 
# two subarrays with the same sum 
def divideArray(arr, n): 
  
    # sum stores sum of all  
    # elements of the array 
    sum = 0
    for i in range(0, n): 
        sum += arr[i] 
  
    # sum stores sum till previous  
    # index of the array 
    sum_so_far = 0
    for i in range(0, n): 
  
        # If on removing arr[i], we get 
        # equals left and right half 
        if 2 * sum_so_far + arr[i] == sum: 
            print ("The array can be divided into", 
                    "two subarrays with equal sum") 
            print ("two subarrays are -") 
            printSubArray(arr, 0, i - 1) 
            printSubArray(arr, i + 1, n - 1) 
            return True
  
        # add current element to sum_so_far 
        sum_so_far += arr[i] 
  
    # The array cannot be divided 
    print ("The array cannot be divided into"
           "two subarrays with equal sum") 
    return False

n = int(raw_input())
money=list(map(int,raw_input().split()))

divideArray(money, n) 
