import collections
n = int(raw_input())
listn = list(map(int,raw_input().split()))
n2 = int(raw_input())
numb = list(map(int,raw_input().split()))

for i in numb:
    a = collections.Counter(listn)
del n,listn,n2
for i in numb:
    print(a[i])