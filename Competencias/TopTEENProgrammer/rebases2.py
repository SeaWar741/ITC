cars = int(raw_input())
carsl =list(map(int,raw_input().split()))

def insertionSort(arr): 
    counter =0 
    for i in range(1, len(arr)): 
        key = arr[i] 
        j = i-1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
                counter +=1
        arr[j + 1] = key
    print(counter)
insertionSort(carsl)
