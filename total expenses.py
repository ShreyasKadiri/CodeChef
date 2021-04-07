for _ in range(int(input())):
    p,q=map(int,input().split())
    if(p>1000):
        t=(p*q)*0.1 
        k=(p*q)-t
        print(k)
    else:
        print(int(p*q))
