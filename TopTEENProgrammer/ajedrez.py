pos = list(map(str,raw_input().split()))
col = '"'+pos[0]+pos[1]+'"'
print('NBELGARNOC O'[sum(map(ord,col))%2::2])
