#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  using namespace __gnu_pbds;
using namespace std;
const ll mxM=1e5;


  //  order_of_key (k) : Number of items strictly smaller than k .
 //   find_by_order(k) : K-th element in a set (counting from zero).


void solve()
{
    int n,ans=1;
    cin>>n;
    int arr[n],dp[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        dp[i]=1;
    }
    for(int j=n-1;j>=0;j--)
    {
        for(int i=j+1;i<n;i++)
        {
            if(arr[i]%arr[j]==0)
                dp[j]=max(dp[j],dp[i]+1);
            ans=max(ans,dp[j]);
        }
    }
    cout<<ans<<"\n";
    return;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
	return 0;
}
