# cook your dish here
for t in range(int(input())):
    n,m=[int(x)for x in input().rstrip().split()]
    s=[]
    for p in range(n):
        s.append(10)
    for c in range(m):
        i,j,k=[int(x)for x in input().rstrip().split()]
        for q in range(i-1,j):
            s[q]=s[q]*k
    print(sum(s)//n)
