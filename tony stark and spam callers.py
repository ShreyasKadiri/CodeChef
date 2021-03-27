# cook your dish here
for _ in range(int(input())):
    n=int(input())
    s=input()
    s=s.lower()
    p=list(s)
    s=set(p)
    if(len(s)%2!=0):
        print("AVENGER")
    else:
        print("SPAM")
