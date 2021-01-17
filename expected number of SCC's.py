N=int(1e5+10)
mod=998244353

def exponent(X, Y):
	r=1
	X=int(X%mod)
	while Y>0:
		if Y&1:
			r=r*X%mod
		Y=Y>>1
		X=X*X%mod
	return r


def inverse(X):
	return exponent(X,mod-2)

def additon(x, y):
	return (x%mod+y%mod)%mod

def multiply(x, y):
	x%=mod
	y%=mod
	return ((x*y%mod)+mod)%mod



def awseome(m,n,k):
	ans=0
	b=[0 for i in range(N)]
	b[0]=1
	for i in range(1,N):
		b[i]=multiply(i,b[i-1])
	n-=1
	res=1
	for i in range(0,n+1):
		sum=multiply(b[n],multiply(inverse(b[i]),inverse(b[n-i])))
		sum=multiply(sum,i+1)
		# print(sum)
		ans=additon(ans,multiply(sum,res))
		res=multiply(res,k-1)
	num,den=0,k
	num=multiply(ans,k)
	while n:
		den=multiply(den,k)
		n-=1
	ans=multiply(num,inverse(den))
	print(ans)



def superb(m,n,k):
	b=[0 for i in range(N)]
	b[1]=multiply(k,2*k-1)
	c=multiply(k,k)
	d=k
	for i in range(2,n+1):
		b[i]=multiply(b[i-1],c)
		x=multiply(k-1,3)
		y=multiply((k-1)*(k-2),2)
		z=multiply(x+y,d)
		b[i]=additon(b[i],z)
		x=multiply(k-2,3)
		y=multiply((k-1)*(k-2)+1,2)
		z=multiply(x+y,(k-1)*d)
		b[i]=additon(b[i],z)
		d=multiply(c,d)
	num=b[n]
	den=1
	for _ in range(0,m*n):
		den=multiply(den,k)
	ans=multiply(num,inverse(den))
	print(ans)



if __name__ == '__main__':
	m,n,k=map(int,input().split())
	if(m==1):
		awseome(m,n,k);
	else:
		superb(m,n,k);
