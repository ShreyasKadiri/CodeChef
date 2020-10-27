try:
    n=int(input())-1
    w=input()
    w=[]
    for _ in range(n):
        w.append([int(i) for i in input().split()][1:])
    d=[float('inf') for i in range(n)]
    d[0]=0
    q=set([i for i in range(n)])
    while len(q):
        mn=float('inf')
        for i in range(n):
            if d[i]<mn and i in q:
                mn=d[i]
                v=i
        q.remove(v)
        for i in range(n):
            if w[v][i]<d[i] and i in q:
                d[i]=w[v][i]
    print(sum(d))
except:
    pass
