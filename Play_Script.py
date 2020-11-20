for _ in range(int(input())):
    S=input()
    n=len(S)
    a=n-S.count('a')
    print(2**n-2 ** a)
