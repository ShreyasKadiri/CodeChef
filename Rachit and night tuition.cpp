#include<bits/stdc++.h>
#define ll long long int
#define str string
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vvi vector<vector<ll>>
#define vi vector<ll>
#define mapii map<ll,ll>
#define mapvi map<vector<ll>,ll>
#define mapiv map<ll,vector<ll>>
#define all(a) (a).begin(),(a).end()
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define show(arr,n) for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
#define pii pair<ll,ll>
#define itr vector<ll>::iterator
#define repi(x,n) for(ll i=x;i<n;++i)
#define repid(x,n) for(ll i=x;i>=n;--i)
#define repj(x,n) for(ll j=x;j<n;++j)
#define repjd(x,n) for(ll j=x;j>=n;--j)
#define print2(x,y) cout<<x<<" "<<y<<'\n'
#define print3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define input(x) cin>>x
#define input2(x,y) cin>>x>>y
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define M 1000000007
#define S 200005
#define E6 1000000
const ll INF = 1ll<<60;
using namespace std;

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll to;
cin>>to;
while(to--)
{
  ll a,b,c,r;
	cin>>a>>b>>c>>r;
	ll st,end;
	st=c-r;
	end=c+r;
  ll ans=0;
  ll temp;
  if(a>b)
  {
    temp=a;
    a=b;
    b=temp;
  }
  ll t=abs(b-a);
  if(b<=st)
  {
    ans=t;
  }
  else if(b>st and b<=end)
  {
    if(a>=st)
    {
      ans=0;
    }
    else
    {
      ans=st-a;
    }
  }
  else
  {
    if(a<=st)
    {
      ans=(st-a)+(b-end);
    }
    else if (a>st and a<end)
    {
      ans=b-end;
    }
    else
    {
      ans=t;
    }
  }
  print(ans);
}
  return 0;
}
