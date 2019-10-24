class Point: 
    def __init__(self, x, y): 
        self.x = x 
        self.y = y 
def overlap(l1, r1, l2, r2): 
    if(l1.x > r2.x or l2.x > r1.x): 
        return False
    if(l1.y < r2.y or l2.y < r1.y): 
       return False
        
    return True


numbers = list(map(int,raw_input().split()))

x1 = numbers[0]
y1 = numbers[1]
x2 = numbers[2]
y2 = numbers[3]

x3 = numbers[4]
y3 = numbers[5]
x4 = numbers[6]
y4 = numbers[7]
  
r1 = Point(x1, y1) 
l1 = Point(x2, y2 )
r2 = Point(x3, y3) 
l2 = Point(x4, y4 )
  
if(overlap(l1, r1, l2, r2)): 
    print("SI") 
else: 
    print("NO")


#l1: Top Left coordinate of first rectangle.
#r1: Bottom Right coordinate of first rectangle.
#l2: Top Left coordinate of second rectangle.
#r2: Bottom Right coordinate of second rectangle.