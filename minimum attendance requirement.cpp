#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n;cin>>t;while(t--)
    {
        ll o=0,z=0;
        cin>>n;
        string c;
        cin>>c;
        for(ll i=0;i<c.length();i++)
        {
            if(c[i]=='0') z++;
            else o++;
        }
        float d=(float(120-n+o)/120);
        if(d>=0.75)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
