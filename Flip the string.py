import sys
if __name__=="__main__":
 for i in range(int(input())):
    x=input()
    y=input()
    a=[]
    for i in x:
        a.append(i)
    b=[]
    for i in y:
        b.append(i)
    c=0
    for i in range(len(a)):
        if a[i]==b[i]:
            continue
        p=i
        while p<len(a) and (a[p]!=b[p]):
            a[p]=b[p]
            p=p+2
        c=c+1
    print(c)
