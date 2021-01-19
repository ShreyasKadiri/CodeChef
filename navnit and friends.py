# cook your dish here
a=input()
j3=1
l=[]
d=[]
l1=[]
for i in a:
    if i!=" ":
        if int(i)>200000 or int(i)<0:
            print("not defined")
            j3=4
            break
        int(i)
        if j3==1:
            n=i
            int(n)
            j3=j3+1
        else:
            m=i
z=int(m)
for y in range(z):
    if j3==4:
        break
    a=input()
    for j in a:
         if j!=" ":
             l1.append(j)
    r=0
    for j in l1:
        for k in d:
            if j in k:
                if j==l1[0] and l1[1] not in k:
                    d1=d.index(k)
                    d[d1].append(l1[1])
                    r=1
                elif j==l1[1] and l1[0] not in k:
                    d1=d.index(k)
                    d[d1].append(l1[0])
                    r=1                
    if r==0:
        d.append(l1)
    if l1[0] in l and l1[1] in l:
        k1=[]
        for k in d:
            for j in k:
                if j==l1[0] or j==l1[1]:
                    if k1!=[] and k!=k1:
                        d1=d.index(k)                        
                        for x in k1:
                            d[d1].append(x)
                        d.remove(k1)
                    k1=k
    for k in d:
        if d.count(k)>1:
            d.remove(k)
    for j in l1:            
        l.append(j)    
    l1=[]
m=0
m1=int(n)
for k in d:
    l2=[]
    for j in k:
        if j not in l2:
            l2.append(j)
    d.remove(k)
    d.append(l2)
l3=0
for k in d:    
    k1=len(k)
    m=m+k1*(m1-k1)-(l3*k1)
    l3=l3+k1
print(m)
