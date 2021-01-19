for i in range(int(input())):
    n=int(input())
    result=list(map(int,input().split()))
    sum=result[0]
    for j in range(1,n):
        sum^=result[j]
    print(sum)
