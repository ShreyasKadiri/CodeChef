#include <bits/stdc++.h>

using namespace std;

long long int largepower(long long int x, unsigned long long int y,long long int p)  
{  
    long long int res = 1;    
  
    x = x % p;   
    if (x == 0) 
    return 0;  
  
    while (y > 0)  
    {   
        if (y & 1)  
            res = (res*x) % p;  
  
       
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}  
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
       long long int n,m,p=1e9+7;
       cin>>n>>m;
       long long int s=n/2;
       if(s==0)
       cout<<1<<endl;
       else
       {
            long long int sum=0;
            sum=(s*(s+1))/2;
            sum=sum*2;
            long long int ans=largepower(m,sum,p);
            cout<<ans<<endl;
       }
        
    }
	
	return 0;
}
