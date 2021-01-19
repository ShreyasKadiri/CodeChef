# cook your dish here
from collections import defaultdict
d=defaultdict(list)
def dfs(i):
    p=0
    global v
    e=[i]
    while(e!=[]):
        p+=1
        x=e.pop(0)
        v[x]=1
        for i in d[x]:
            if v[i]==-1:
                v[i]=1
                e.append(i)
    return p

n,m=map(int,input().split())
for i in range(n+1):
    d[i]=[]
for _ in range(m):
	a,b=map(int,input().split())
	d[a].append(b)
	d[b].append(a)
v=[]
for i in range(n+1):
    v.append(-1)
c=0
p=[]
for i in range(1,n+1):
    if v[i]==-1:
        c+=1
        p.append(dfs(i))
an=0
s=0
for i in range(c):
    s+=p[i]
    an+=p[i]*(n-s)
print(an)
