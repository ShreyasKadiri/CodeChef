# cook your dish here
n=int(input())
a=[0]*n
a[0],a[1],a[2]=1,2,5
for i in range(3,n):
    a[i]=(2*a[i-1]+a[i-3])%10000
print(a[-1])
