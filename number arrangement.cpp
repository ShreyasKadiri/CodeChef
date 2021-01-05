#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<int,int> mp;
        unordered_map<int,int>::iterator it;
        int n;
        cin>>n;
        int a,mid=ceil(n/2),c=0,check=ceil(n/3);
        for(int i=0;i<n;i++)
        {
            cin>>a;
            it=mp.find(a);
            if(it!=mp.end())
            {
                mp[a]++;
            }
            else
            {
                mp[a]=1;
                c++;
            }
        }
          if(n==1)
        {
            cout<<"YES"<<endl;
        }
        
        else if(n==2)
        {
            if(c==2)
            {
                cout<<"YES"<<endl;
                
            }
            else 
             {
                 cout<<"NO"<<endl;
             }
        }
        else
        {
        bool f=1;
        if(c<3)
        {
            cout<<"NO"<<endl;
        }
        else
        {
        for(it=mp.begin();it!=mp.end();it++)
        {
            int s=it->second;
            if(s>mid) f=0;
            if(s>check) f=0;
        }
         if(f==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        }
        }
    }
	return 0;
}
