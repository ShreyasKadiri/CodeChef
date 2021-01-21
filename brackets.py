# cook your dish here
import bisect
n, k1, *l = map(int, input().split())
v_l, b_l = l[:n], l[n:]

b_inv = {key:[] for key in range(2*k1)}
for i in range(n):
    b_l[i] -= 1
    b_inv[b_l[i]].append(i)

dp = [[0 for _ in range(n)] for _ in range(n)]
for k in range(1, n):
    for j in range(n-2, -1, -1):
        if j+k >= n:
            continue
        
        dp[j][j+k] = max(dp[j][j+k], dp[j][j+k-1])
        if b_l[j+k] >= k1:
            left = bisect.bisect_right(b_inv[b_l[j+k]-k1], j)
            
            if b_l[j+k] >= k1:
                for i in b_inv[b_l[j+k]-k1][left:]:
                    if i > j+k:
                        break
                    if i > j:
                        dp[j][j+k] = max(dp[j][j+k], dp[j][i-1]+dp[i][j+k])
            if b_l[j+k]-k1 == b_l[j]:
                if j+k-1 < n:
                    dp[j][j+k] = max(dp[j][j+k], v_l[j+k]+v_l[j]+dp[j+1][j+k-1])
                else:
                    dp[j][j+k] = max(dp[j][j+k], v_l[j+k]+v_l[j])
        

print(dp[0][-1])
