# cook your dish here
N,K=map(int,input(" ").split(" "))
B=list(map(int,input(" ").split(" ")))
A=[]
for i in range(K):
    A.append(B[i])
i=K
g=1
while(i<N):
    if(g==1):
        A.append(B[i])
        g=0
        i=i+K
        continue
    if(g==0):
        if(i+K-1<N):
            A.append(B[i+K-1])
        g=1
        i=i+K
        continue
print(*A)
