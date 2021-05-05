def fib(x):
    a,b=0,1
    while a<=x:
      a,b=b,a+b
      print(a)    

x=int(input())
fib(x)
