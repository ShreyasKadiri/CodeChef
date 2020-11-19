# cook your dish here
t=int(input())
for _ in range(t):
    p, idx=map(int, input().split())
    length=2**p 
    so=0
    mult=1
    while length>1:
        length=length>>1 
        if idx>=length:
            idx-=length
            so+=mult
        mult*=2
    print(so)
        
