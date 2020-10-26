m=int(input())
result=[]

for i in range(m):
    x,y=map(int,input().split())
    result.append(abs(x-y))
    result.sort()
    
while len(result)>1:
    result[-2]-=result[-1]
    result.pop()
    result[-1]=abs(result[-1])
    result.sort()
print(result[0])
