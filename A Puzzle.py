n=int(input())
list1=[]
list2=[]
result=[]

for i in range(n):
    list1.append(list(map(int,input().split())))

for i in range(n):
    list2.append(list(map(int,input().split())))
    

def solve(arr1,arr2):
    c=0
    for k in range(n):
        if arr1[k]==arr2[k]:
            c+=1
    return c
    
value=0

for i in range(n):
    j=0
    current=solve(list1[i],list1[i])
    while True:
        if current==n-1 or current==n or j==n:
            if current==n-1:
                value=i
            break
            
        else:
            temp_value=list1[i][0]
            for _ in range(n-1):
                list1[i][_]=list1[i][_+1]
            list1[i][n-1]=temp_value
        j+=1
        current=solve(list1[i],list1[i])
    
    if j==n:
        print("NO")
    
    if j!=0:
        if j<(n+1)//2:
            temp=0
            while temp<j:
                result.append(i+1)
                temp+=1
        else:
            diff=n-j
            temp=0
            while temp<diff:
                result.append(-(i+1))
                temp+=1
ele=0

while ele<n and list1[value][ele]==list1[value][ele]:
    ele+=1
if ele==n:
    print("NO")
    

t1=[list1[i][ele] for i in range(n)]
t2=[list2[i][ele] for i in range(n)]
tl=0

while solve(t1,t2)!=n and tl<n:
    temp_value=list1[0][ele]
    for _ in range(n-1):
        list1[_][ele]=list1[_+1][ele]
    list1[n-1][ele]=temp_value
    tl+=1
    t2=[list1[i][ele] for i in range(n)]
    
if (tl==n-1 or tl==1) and len(result)>0:
    result.append(-(ele+1) if tl==1 else (ele+1))
    print("YES")
    print(len(result),*result[::-1])

else:
    print("NO")
