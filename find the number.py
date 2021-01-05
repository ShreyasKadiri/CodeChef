import math
def findnumber(l,n):
    l.sort()
    x = l[0] * l[-1]
    vec = []
    i = 2
    while (i*i)<=x:
        if x%i==0:
            vec.append(i)
            if x//i !=i:
                vec.append(x//i)
        i = i + 1
    vec.sort()    
    if len(vec)!=n:
        return -1
    else:
        j = 0
        for it in range(n):
            if(l[j] != vec[it]):
                return -1
            else:
                j += 1
    return x
if __name__=="__main__":
    t = int(input())
    while t:
        n = int(input())
        arr = list(map(int,input().split()))
        n = len(arr)
        print(findnumber(arr,n))
        print()
        t=t-1
