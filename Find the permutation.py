m=int(input())
array=list(map(int,input().split()))
result=[1]
for i in range(1,m):
    result.insert(i-array[i], i+1)
print(*result)
