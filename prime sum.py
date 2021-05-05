n=int(input())
d={}
count=n
i=2
current=1
number=0
d[current]=2
current+=1

for j in range(i+1,5000000):
    flag=False
    for k in range(2,(j//2)+1):
        if j%k==0:
            number=j
            flag=True
            break
    if flag==False:
        d[current]=j
        current+=1
    if current>n:
        break
total_sum=0
for z in range(1,n+1):
    total_sum+=d[z]
print(total_sum)
