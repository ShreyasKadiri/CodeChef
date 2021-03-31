#include<iostream>
using namespace std;
long long int dif(long long int a,long long int b)
{
    long long int d;
    d=a-b;
    if(d<0)
    {
        d=d*(-1);
    }
    return d;
}
long long int search(long long int a[],long long int n,long long int find)
{
    long long int i,loc=-1;
    for(i=0;i<n;i++)
    {
        if(find==a[i])
        {
            loc=i;
            break;
        }
    }
    return loc;
}
int main()
{
    long long int t;
    cin>>t;
    while(t>0)
    {
        long long int n,i,loc,adder=0,var=1;
        cin>>n;
        long long int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }    
        for(i=0;var<=n;var++)
        {
            
            loc=search(a,n,var);
            adder+=dif(i,loc);
            i=loc;
        }
        cout<<adder<<endl;
    t--;
    }
    return 0;
}
