times=int(raw_input())
answers=[]
for i in range(times):
    w= raw_input()
    w = [x for x in w]
    abc = "abcdefghijklmnopqrstuvwxyz"
    ab = [x for x in abc]
    numb = range(0,26)
    comb = dict(zip(ab, numb))
    #for i in range(len(w)):
    #    w[i] = comb.get(w[i])

    def isCycle(w,n):
        isit = False
        for i in range(1,n):
            if i !=n:
                if w[i-1] < w[i] and w[i]!=25:
                    isit = True
                    break
                else:
                    isit = False
                    break  
        return isit
    
    def areDistinct(arr) : 
        n = len(arr) 
        s = set() 
        for i in range(0, n):  
            s.add(arr[i])  
        return (len(s) == len(arr) and len(arr)==26) 

    if areDistinct(w):  
        answers.append("PERFECT")  
    else: 
        answers.append("NO WAY") 
for i in answers:
    print(i)
  