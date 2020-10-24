#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i(0);i<n;i++)
    cin>>a[i];
    
    sort(a.begin(),a.end());
    
    auto query=[&](vector<int> b,int s)
    {
        int l=0,r=b.size()-1;
        while(l<r)
        {
            if(a[l]+a[r]<s)
            l++;
            else if(a[l]+a[r]>s)
            r--;
            else
            return 1;
        }
        return 0;
    };
    
    int val=0;
    for(int i=0;i<n;i++)
    val+=query(a,2*a[i]);
    cout<<val;
}


int main()
{
    #ifdef from_300_iq_fun_club
    mt19997 rnd(RAND_MAX);
    #endif
    int t=1;
    //cin>>t;
    while(t--)
    solve();
    return 0;
}
