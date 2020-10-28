s=[int(i) for i in input().split()]
n=s[0]
m=s[1]
temp=[[0 for _ in range(n)] for _ in range(n)]
while m>0:
    s=[int(i) for i in input().split()]
    i=s[0]-1
    j=s[1]-1
    temp[i][j]=1
    temp[j][i]=1
    m-=1
s=[int(i) for i in input().split()]
source=s[0]-1
destination=s[1]-1
v=[0 for i in range(n)]
distance=[0 for i in range(n)]
queue=[source]
v[source]=1
flag=0
while True:
    u=queue[flag]
    for i in range(n):
        if temp[u][i]==1 and v[i]==0:
            distance[i]=distance[u]+1
            v[i]=1
            queue.append(i)
    if flag==len(queue)-1:
        break
    else:
        flag+=1
print(distance[destintation])
