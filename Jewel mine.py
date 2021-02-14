t = int(input())
while t != 0:
    M = 1000000007
    n, m = map(int, input().split()) 
    ans = 1
    tt = n//2
    tt = tt * (tt + 1)
    
    ans = pow(m, tt, M)
    
    print(ans)
    t -= 1
