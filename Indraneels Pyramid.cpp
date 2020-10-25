in=int(input())
temp=[]
while in>0:
    temp.append([int(i) for i in input().split()])
    in-=1
    temp[-1].sort() 
temp.sort()
k=1
count=0
for i in temp:
    if i[0]>=k and i[1]>=k:
        count+=1
        k+=1
print(count)
