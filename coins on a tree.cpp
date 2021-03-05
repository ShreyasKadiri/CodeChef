#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define forn(i,n) for(int (i)=0;(i)<(n);(i)++)
#define forr(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define fore(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define F first
#define S second
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(),(x).end()
#define fill(x,a) fill((x).begin(),(x).end(),(a)) 
#define setbitcount __builtin_popcount
#define isodd __builtin_parity
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pque priority_queue
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpi vector<pi>
#define vvpi vector<vector<pi>>
#define vpll vector<pll>
#define vvpll vector<vector<pll>>
#define pb push_back
#define mp make_pair
#define pln cout<<"\n";
#define endl "\n"
#define OPTIMISED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
using namespace __gnu_pbds;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
typedef  long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const ll inf9=1e9,inf18=1e18,inf6=1e6,inf14=1e14;
const ll mod7=inf9+7,mod9=inf9+9;
const int modi=998244353;
clock_t time_p=clock();
void clk()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
void dfs1(int i,vvi& adj,vll& coins,vll& first,vll& sec,int p)
{
	if(adj[i].size()==0)
	{
		return;
	}
	for(auto it:adj[i])
	{
		if(it==p)continue;
		dfs1(it,adj,coins,first,sec,i);
		first[i]+=first[it]+coins[it];
		sec[i]+=coins[it]+first[it]+sec[it];
	}
	return;
}
void dfs(int i,vvi& adj,vll& first,vll& sec,vll& ans,int p,vll& coins)
{
	if(p==-1)
	{
		ans[0]=sec[0];
		for(auto it:adj[0])dfs(it,adj,first,sec,ans,0,coins);
		return;
	}
	first[p]-=(coins[i]+first[i]);
	sec[p]-=(coins[i]+first[i]+sec[i]);
	first[i]+=(coins[p]+first[p]);
	sec[i]+=(coins[p]+first[p]+sec[p]);
	ans[i]=sec[i];
	for(auto it:adj[i])
	{
		if(it==p)continue;
		dfs(it,adj,first,sec,ans,i,coins);
	}
	sec[i]-=(coins[p]+first[p]+sec[p]);
	first[i]-=(coins[p]+first[p]);
	sec[p]+=(coins[i]+first[i]+sec[i]);
	first[p]+=(coins[i]+first[i]);
	return;
}
void solve()
{
	int n;cin>>n;
	if(n==0){cout<<endl;return;}
	vector<ll> coins(n);
	forn(i,n)cin>>coins[i];
	if(n==1){cout<<"0"<<endl;return;}
	vector<vector<int>> adj(n);
	vll sec(n,0);
	forn(i,n-1)
	{
		int a,b;cin>>a>>b;a--;b--;
		adj[a].pb(b);adj[b].pb(a);
	}
	vector<ll> first(n,0);
	dfs1(0,adj,coins,first,sec,-1);
	vll ans(n,0);
	dfs(0,adj,first,sec,ans,-1,coins);
	for(auto it:ans)cout<<it<<" ";
	cout<<endl;
}
int main()
{
	OPTIMISED
	int t=1;  cin>>t;
	while(t--)solve();
	//clk();
    return 0;
}
