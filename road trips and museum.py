def merge(intervals,start,mid,end):
    al = mid-start+1
    bl = end-mid
    
    A = intervals[start:mid+1]
    B = intervals[mid+1:end+1]
    
    p=0;q=0;k=start;
    while(p<al and q<bl):
        if(A[p]<B[q]):
            intervals[k] = A[p]
            k+=1;p+=1;
        else:
            intervals[k] = B[q]
            k+=1;q+=1;
    
    while(p<al):
        intervals[k] = A[p]
        k+=1;p+=1;
    while(q<bl):
        intervals[k] = B[q]
        k+=1;q+=1;
    

def mergesort(intervals, start, end):
    if(start<end):
        mid = int((start+end)/2)
        mergesort(intervals,start,mid)
        mergesort(intervals,mid+1,end)
        merge(intervals,start,mid,end)

t = int(input())
for _ in range(t):
    n,m,k = map(int, input().split())
    
    cities = [[0,[]] for i in range(n)]
    for i in range(m):
        a,b = map(int, input().split())
        cities[a-1][1].append(b-1)
        cities[b-1][1].append(a-1)
    
    li = list(map(int, input().split()))
    
    def specialfunction():
        mergesort(li,0,n-1)
        if(k>len(li)):
            print(-1)
        else:
            sum = 0
            front = 0
            rear = len(li)-1
            for i in range(k):
                if(i%2==0):
                    sum += li[rear]
                    rear -= 1
                else:
                    sum += li[front]
                    front += 1
            print(sum)
    
    if(m == 0):
        specialfunction()
        continue
    
    for i in range(n):
        cities[i][0] = li[i]
    
    visited = [-1 for i in range(n)]
    count = 0
    museummonths = []
    def searchUnvisited():
        for i in range(n):
            if(visited[i] == -1):
                return i
        return -1
    
    def bfs(ind,count):
        museumcount = 0
        queue = []
        queue.append(ind)
        visited[ind] = 1
        museumcount += cities[ind][0]
        count += 1
        front = 0
        rear = 0
        while(front<=rear):
            noe = len(cities[ind][1])
            for i in range(noe):
                if(visited[cities[ind][1][i]] == -1):
                    queue.append(cities[ind][1][i])
                    rear += 1
                    count += 1
                    museumcount += cities[cities[ind][1][i]][0]
                    visited[cities[ind][1][i]] = 1
            front += 1
            try:
                ind = queue[front]
            except:
                break
        museummonths.append(museumcount)
        return count
    
    while(count<n):
        for i in range(n):
            if(visited[i] == -1):
                count = bfs(i,count)
    
    mergesort(museummonths,0,len(museummonths)-1)
    #print(museummonths)
    if(k>len(museummonths)):
        print(-1)
    else:
        sum = 0
        front = 0
        rear = len(museummonths)-1
        for i in range(k):
            if(i%2==0):
                sum += museummonths[rear]
                rear -= 1
            else:
                sum += museummonths[front]
                front += 1
        print(sum)
