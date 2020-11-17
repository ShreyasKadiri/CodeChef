#include <bits/stdc++.h> 
using namespace std;
int b[100001];
int a[100001];
int p[100001];
int n,q,si;
int stx=0;
struct fg
{
 int val,lazy,rc,lc;
}Node[5000000];

void s(int v,int p,int ch)
{
 
    if(ch==1)
       { Node[++stx]=Node[Node[p].rc];
        Node[p].rc=stx; 
       }
        else
      { Node[++stx]=Node[Node[p].lc];
        Node[p].lc=stx; 
       }
 
}

void update(int v,int L,int R,int l,int r,int x)
{
 if(l==L&&r==R)
 {
   Node[v].lazy+=x;
   return;
 }
   else
   {  int mid=(L+R)/2;
 if(l>mid)
 {
 s(Node[v].rc,v,1);
 update(Node[v].rc,mid+1,R,l,r,x);
 }
    else if(r<=mid)
 {
 s(Node[v].lc,v,0);
 update(Node[v].lc,L,mid,l,r,x);
 }


    else 
 {
 s(Node[v].rc,v,1);
 s(Node[v].lc,v,0);
 update(Node[v].rc,mid+1,R,mid+1,r,x);
 update(Node[v].lc,L,mid,l,mid,x);
 }
 Node[v].val=max(Node[Node[v].rc].val+Node[Node[v].rc].lazy,Node[Node[v].lc].val+Node[Node[v].lc].lazy);

   }
}

int get(int v,int L,int R,int l,int r)
{   if(v==0)
    return 0;
 if(L==l&&R==r)
 return Node[v].val+Node[v].lazy;
    
    else
    {  int mid=(L+R)/2;
      if(l>mid)
      return get(Node[v].rc,mid+1,R,l,r)+Node[v].lazy;
      else if(r<=mid)
      return get(Node[v].lc,L,mid,l,r)+Node[v].lazy;
      else
      {
           return max(get(Node[v].rc,mid+1,R,mid+1,r)+Node[v].lazy,get(Node[v].lc,L,mid,l,mid)+Node[v].lazy);
      }
    }
}
int main()
{   int c;
    b[0]=0;
    p[0]=0;
 cin>>n>>q>>si;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    a[0]=100001;
    for(int i=1;i<=n;i++)
     {  
      c=i-1;
      while(a[c]<a[i])
      c=p[c];
      p[i]=c;
     }
     for(int i=1;i<=n;i++)
     {
     Node[b[i]=++stx]=Node[b[i-1]];
     update(b[i],1,n,p[i]+1,i,1);
     }
int l,r;
     if(si==0)
     {
        for(int i=1;i<=q;i++)
       { cin>>l>>r;
         if(r<l)
          swap(l,r);
        cout<<get(b[r],1,n,l,r)<<endl;}
     }
     else
     {  int last=0;

       for(int i=1;i<=q;i++)
        {cin>>l>>r;
          l=(l+last-1)%n+1;
          r=(r+last-1)%n+1;
          if(r<l)
          swap(l,r);
        last=get(b[r],1,n,l,r);
        cout<<last<<endl;}
     }
}
