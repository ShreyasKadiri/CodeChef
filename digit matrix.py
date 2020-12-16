# cook your dish here
n = int(input())
a = [list(map(int,input().split())) for i in range(n)]
b = [[0]*(n+1) for i in range(n+1)]
def posibilities(i,j):
    if(i==0 and j==0):
        return 0,9
    if(i==0 and j==n):
        return max(0,a[0][-1]-b[0][n-1]-18),min(9,a[0][-1]-b[0][n-1])
    if(i==0):
        return max(0,a[i][j-1]-b[0][j-1]-18,a[i][j]-27),min(9,a[i][j-1]-b[0][j-1],a[i][j])
    if(j==0):
        return max(0,a[i-1][j]-b[i-1][j]-b[i-1][j+1]-9),min(9,a[i-1][j]-b[i-1][j]-b[i-1][j+1])
    return max(0,a[i-1][j-1]-b[i-1][j-1]-b[i][j-1]-b[i-1][j]),min(9,a[i-1][j-1]-b[i-1][j-1]-b[i][j-1]-b[i-1][j])


def solve(k):
    if k==(n+1)**2:
        return True
    minn,maxx = posibilities(k//(n+1),k%(n+1))
    if(minn<=maxx):
        for i in range(minn,maxx+1):
            b[k//(n+1)][k%(n+1)]=i
            if solve(k+1):
                return True
    return False
solve(0)

for i in b:
    temp = ''
    for j in i:
        temp+=str(j)
    print(temp)
