mod=1e9+7
dp=[[1]*(1001) for i in range(1001)]
for i in range(1001):
    for j in range(1,1001):
        if i==0: dp[i][j]=j+1
        else: dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod

for _ in range(int(input())):
    n,q=(map(int,input().split()))
    for i in range(q):
        #a=[i for i in range(n)]
        l,r,k=(map(int,input().split()))
        print(int(sum(dp[k][l-1:r])%mod))
