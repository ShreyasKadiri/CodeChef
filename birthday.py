import itertools
a = list(map(int, input().split()))
x = list(map(int, input().split()))
y = list(map(int, input().split()))
z = list(map(int, input().split()))
    
x.sort()
y.sort()
z.sort()

if (x[0] > a[0]) or (y[0] > a[0]) or (z[0] > a[0]):
    print(-1)
    
new = []
new.append(x)
new.append(y)
new.append(z)
    
result = list(itertools.product(x, y, z))
#print(result)


res = (list(map(sum, list(result))))


#print(res)
new1 = []

for i in res:
    if (i <= a[0]):
        new1.append(i)

print(a[0] - max(new1))
