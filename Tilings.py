n=int(input())
list=[0, 1, 2, 5]
for i in range(4, n+1):
    list.append((2*list[i-1] + list[i-3]) % 10000)
print(list[n])
