# cook your dish here
def prod(x,z):
    return x[0]*z[2]+x[1]*z[0]+x[2]*z[1]
t=int(input())
for _ in range(t):
    n, k = map(int, input().split())
    lista=input().split()
    x_occ=[[0,0,0]]
    z_occ=[[0,0,0]]
    if lista[0]=='X':
        x_occ[0][0]=1
    if lista[n-1]=='Z':
        z_occ[0][(n-1)%3]=1
    for i in range(1,n):
        x_occ.append(x_occ[-1].copy())
        if lista[i]=='X':
            x_occ[i][i%3]+=1
        z_occ.append(z_occ[-1].copy())
        if lista[n-1-i]=='Z':
            z_occ[i][(n-1-i)%3]+=1
    z_occ=z_occ[::-1]
    tot=0
    for i in range(n-1):
        if lista[i]=='X':
            tot+=z_occ[i+1][(i-1)%3]
    start=[tot]
    end=[tot]
    for i in range(n-1):
        if lista[i]=='X':
            start.append(start[-1]-z_occ[i+1][(i-1)%3])
        else:
            start.append(start[-1])
        if lista[n-1-i]=='Z':
            end.append(end[-1]-x_occ[n-2-i][(n-i)%3])
        else:
            end.append(end[-1])
    end=end[::-1]
    if k==n:
        print(tot)
    else:
        minimo=min(tot-start[k], tot-end[-k-1])
        for i in range(1,n-k):
            minimo=min(minimo, tot-start[k+i]-end[i-1])
        print(minimo)
