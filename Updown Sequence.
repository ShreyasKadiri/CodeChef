#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    
    int t ;cin>>t ;
    while(t--)
    {
        int n ;cin>>n ;
        int a[n+1] = {} ;

        for(int i = 1 ;i<=n ;i++) cin>>a[i] ;

        int down[n+1][2] = {} , up[n+1][2] = {} ;

        down[1][0] = 1 ; up[1][0] = 0 ;

        for(int i = 2 ;i<=n ;i++)
        {
            if(a[i]>=a[i-1]) up[i][0] = down[i-1][0]+1 ;
            
            if(a[i]<=a[i-1]) down[i][0] = up[i-1][0] +1 ;
            else down[i][0] = 1 ;
        }

        up[n][1] = 1 ; down[n][1] = 1 ;

        for(int i = n-1 ;i>=1 ;i--)
        {
            if(a[i]>=a[i+1]) up[i][1] = down[i+1][1]+1 ;
            else up[i][1] = 1 ;

            if(a[i]<=a[i+1]) down[i][1] = up[i+1][1]+1 ;
            else down[i][1] = 1 ;
        }

        int ans = max(up[1][1]+1,down[1][1]+1) ;
        ans = max(ans,max(up[n][0]+1,down[n][0]+1) ) ;

        for(int i = 1 ;i<n ;i++)
        {
            ans = max(ans,max(up[i][0],down[i][0] ) +1) ;
            ans = max(ans,max(up[i][1],down[i][1])+1) ;
            ans = max(ans,down[i][0]+down[i+1][1]+1) ;
            ans = max(ans,up[i][0]+up[i+1][1]+1) ;
        }  

        cout<<ans<<"\n" ;
    }
}
