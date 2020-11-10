n = int(input())
a = list(map(int,input().split()))
dp = [[0]*3 for i in range(n+1)]

for i in range(1,n+1):
    dp[i][0] = max(dp[i-1])
    for j in range(1,3):
        dp[i][j] = max(dp[i][j],dp[i-1][j-1] + a[i-1])

print(max(dp[-1]))        
