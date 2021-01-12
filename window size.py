# cook your dish here
t=int(input())
j=0
while j<t:
    n=int(input())
    lst=list(map(int,input().split()))
    s=set()
    d=list()
    for i in lst:
        if i in s:
            s.remove(i)
            d.append(i)
        else:
            s.add(i)
    x=len(d)
    if x%2==0:
        print(x//2)
    else:
        print((x-1)//2)
    j+=1
