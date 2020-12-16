from functools import reduce
from operator  import mul

p = 998244353

def prod(L): return reduce(mul ,L,1)

def lsb(n):
    ret = 0
    while not (n & (1<<ret)):
        ret += 1
    return ret

def ham_weight(n):
    a = 0
    while n:
        a += n&1
        n //= 2
    return a

def zero_partitions(A, accum = [], q = 239):
    if len(A) == 0:
        yield accum
        return
    #if A[0]%p == 0:
        #for P in zero_partitions(A[1:],accum+[1],p):
            #yield P
    subset_sum = A[0]
    subset_msk = 0
    for i in range(1,1<<(len(A)-1)):
        k = lsb(i)
        if subset_msk & (1<<k):
            subset_sum -= A[k+1]
        else:
            subset_sum += A[k+1]
        subset_sum %= q
        subset_msk ^= (1<<k)
        if subset_sum == 0:
            #subset = [A[0]]+[A[k] for k in range(1,len(A)) if (1<<(k-1)&subset_msk)]
            rest = [A[k] for k in range(1,len(A)) if not (1<<(k-1)&subset_msk)]
            #for P in zero_partitions(rest,accum+[subset],p):
            for P in zero_partitions(rest,accum+[1+ham_weight(subset_msk)],q):
                yield P

def pow_mod(b,n):
    if n <= 1:
        return (b**n)%p
    sqrt = pow_mod(b,n//2)
    ans  = (sqrt*sqrt)%p
    if n%2:
        ans = (ans*b)%p
    return ans

def fall(x,n):
    accum = 1
    for i in range(x,x-n,-1):
        accum *= i
        accum %= p
    return accum

def fac(n): return fall(n,n)

def solve(A,q = 239):
    if A == []:
        return 1
    if A.count(0) > 0:
        nonzeroes = [a for a in A if a != 0]
        return solve(nonzeroes)*fall(q-len(nonzeroes),A.count(0)) % p
    ans = fall(q-1,len(A)-1)
    if (sum(A)%q) == 0: 
        for P in zero_partitions(A,q = 239):
            m = len(P)
            mu_coef = (-1)**(len(A)-m)*prod([fac(k-1) for k in P])
            ans += mu_coef*pow_mod(q,m-1)*(q-1)
            ans %= p
    return ans
    
n = int(input())
A = list(map(int,input().split()))
print(solve(A))
