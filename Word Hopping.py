def cpy(strr):
    stt = list(strr)
    return ''.join(stt)

def check1(i,j):
    s1,s2 = w[i],w[j]
    if w[i]>w[j]:
        s1,s2 = w[j],w[i]
        i,j = j,i
    c = 0
    for k in range(len(s1)):
        if c > 1:
            break
        if s1[k]<s2[k] and s2[k] in s1[k+1:]:
            c += 1
        elif s1[k]!=s2[k]:
            c = 0
            break
    if c == 1:
        adj[w[i]].append(w[j])

def check2(i,j):
    s1,s2 = w[i],w[j]
    if len(s2)>len(s1):
        s1,s2 = w[j],w[i]
        i,j = j,i
    flag = 0
    for k in range(len(s1)):
        st = cpy(s1)
        st = st[:k]+st[k+1:]
        if st == s2:
            flag = 1
            break
    if flag:
        adj[w[i]].append(w[j])

n = int(input())
w = [input() for _ in range(n)]
adj = {}
dp = {}
for i in w:
    adj[i] = []
    dp[i] = 0
for i in range(n-1):
    for j in range(i+1,n):
        a,b = len(w[i]),len(w[j])
        if a == b:
            check1(i,j)
        elif abs(a-b) == 1:
            check2(i,j)
#print(adj)
def dfs(v):
    visited.add(v)
    for u in adj[v]:
        if u not in visited:
            dfs(u)
        dp[v] = max(dp[v],dp[u])
    dp[v] += 1

visited = set()
for i in w:
    if i not in visited:
        dfs(i)
print(max(dp.values()))
