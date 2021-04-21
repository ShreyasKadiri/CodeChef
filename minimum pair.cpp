from math import gcd
for _ in range(int(input())):
    l,r=map(int,input().split())
    if(l+l+1 > r):
        print("-1 -1")
    else:
        print(l,l+1)
