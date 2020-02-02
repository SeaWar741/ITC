cars = int(raw_input())
cars=list(map(int,raw_input().split()))
counter = 0
for i in range(0, len(cars)):    
    for j in range(i+1, len(cars)):    
        if(cars[i] > cars[j]):    
            temp = cars[i];    
            cars[i] = cars[j];    
            cars[j] = temp;
            counter+=1
print(counter)