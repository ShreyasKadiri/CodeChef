stri=str(input())
total=0
for i in stri:
    if i=="D":
        total+=238
    elif i=="T":
        total+=244
    elif i=="M":
        total+=138
    elif i=="B":
        total+=279
    elif i=="C":
        total+=186
run=total//50
remain=total%50
print(run)
cycle=remain//5
remain=remain%5
print(cycle)
Walking=int(remain//0.5)
print(Walking)
