from sys import stdin,stdout
input=stdin.readline
import sys
def query(i,j):
    global mat,k,count,q
    count+=1
    assert count<=q
    print(1,i+1,j+1,flush=True)
    # temp[i][j]^=1
    # x=0
    # for i in range(n-1):
    #     for j in range(n-1):
    #         if temp[i][j]==temp[i+1][j+1]==0 and temp[i+1][j]==temp[i][j+1]==1:
    #             x+=1
    x=int(input())
    if x==-1:
        sys.exit()
    return x

def f1(i,j):
    global k, mat, dec
    if mat[i][j]!=-1:
        return False
    x=query(i,j)
    if x>=k+1:
        k=x
        mat[i + 1][j] = mat[i][j + 1] = 1
        mat[i + 1][j + 1]=mat[i][j]=0
        return True
    elif x<k:
        k = x
        mat[i + 1][j] = mat[i][j + 1] =mat[i][j] = 1
        mat[i + 1][j + 1] =  0
        return True
    k=x


def f2(i,j):
    global k,mat,dec
    if mat[i+1][j]!=-1:
        return
    x=query(i+1,j)
    if x>=k+1:
        y=query(i,j)
        if y<x:
            k=y
            mat[i][j]=mat[i+1][j]=mat[i][j+1]=1
            mat[i+1][j+1]=0
            return True
        k=query(i,j)
    elif x<k:
        query(i+1,j)
        y=query(i,j)
        if y<k:
            mat[i][j] = mat[i + 1][j] = mat[i][j + 1] = 1
            mat[i + 1][j + 1] = 0
            return True
    # k=x
    if f1(i,j):
        return True



def f3(i,j):
    global k, mat,dec
    if mat[i+1][j+1]!=-1:
        return
    x=query(i+1,j+1)
    if x>=k+1:
        y=query(i,j)
        if y<x:
            k=y
            mat[i][j]=mat[i+1][j]=mat[i][j+1]=1
            mat[i+1][j+1]=0
            return True
        k=query(i,j)
    elif x<k:
        query(i + 1, j + 1)
        y = query(i, j)
        if y < k:
            k = y
            mat[i][j] = mat[i + 1][j] = mat[i][j + 1] = 1
            mat[i + 1][j + 1] = 0
            return True
        if dec:
            k = query(i, j)
        k=query(i + 1, j + 1)
    # k=x
    if f1(i,j):
        return
    if f2(i,j):
        return


def f4(i,j):
    global k,mat,dec
    if mat[i][j+1]!=-1:
        return
    x=query(i,j+1)
    if x>=k+1:
        if dec:
            k = x
            mat[i + 1][j] = mat[i][j + 1] = 1
            mat[i + 1][j + 1]=mat[i][j] = 0
            return True
        y=query(i,j)
        if y<x:
            k=y
            mat[i][j]=mat[i+1][j]=mat[i][j+1]=1
            mat[i+1][j+1]=0
            return True
        if dec:
            k = query(i, j)
    k=x
    if f1(i,j):
        return True
    if f2(i,j):
        return True
    if f3(i,j):
        return True

def pivot(i,j):
    global k,mat
    if f1(i,j):
        return
    if f2(i,j):
        return
    if f3(i,j):
        return
    if f4(i,j):
        return

t=int(input())
for _ in range(t):
    count=0
    n,q,k=map(int,input().split())
    mat=[[-1 for i in range(n)] for j in range(n)]
    for i in range(0,n-1,2):
        for j in range(n-1):
            if mat[i][j]!=-1 and mat[i+1][j]!=-1 and mat[i][j+1]!=-1 and mat[i+1][j+1]!=-1:
                continue
            dec=0
            if mat[i][j]==1:
                dec=1
                k=query(i,j)
                mat[i][j]=0
            if mat[i][j+1]==0:
                dec=1
                k=query(i,j+1)
                mat[i][j+1]=1
            if mat[i+1][j]==0:
                dec=1
                k=query(i+1,j)
                mat[i+1][j]=1
            if mat[i+1][j+1]==1:
                dec=1
                k=query(i+1,j+1)
                mat[i+1][j+1]=0
            pivot(i,j)
            # print(mat)
    if n%2:
        i=n-2
        for j in range(n-1):
            if mat[i][j]==1:
                k=query(i,j)
                mat[i][j]=0
            if mat[i][j+1]==0:
                k=query(i,j+1)
                mat[i][j+1]=1
            if mat[i+1][j]==0:
                k=query(i+1,j)
                mat[i+1][j]=1
            if mat[i+1][j+1]==1:
                k=query(i+1,j+1)
                mat[i+1][j+1]=0
            pivot(i,j)
    for i in range(n):
        for j in range(n):
            assert mat[i][j]!=-1
    print(2,flush=True)
    for i in range(n):
        print(*mat[i],flush=True)
    x=int(input())
    if x==-1:
        sys.exit()
