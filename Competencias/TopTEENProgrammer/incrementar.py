import datetime
hour=list(map(int,raw_input().split()))
a = datetime.datetime(100,1,1,hour[0],hour[1],hour[2])
b = a + datetime.timedelta(0,1)
now = [b.hour,b.minute,b.second]
print(" ".join(str(x) for x in now))
    
