#tomaras el numero minio de monedas, cuya suma de valores es estrictamente mayor que la suma de los valores de las monedas restantes
n = int(raw_input())
money=list(map(int,raw_input().split()))
total=0
for i in money:
    total +=i

for i in range(len(money)): 
        current_sum = 0; 
        for j in range(len(money)-1): 
            current_sum = current_sum + arr[i + j]; 
  
        # Update result if required. 
        max_sum = max(current_sum, max_sum ); 