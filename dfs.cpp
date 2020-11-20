#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 200005;

int sub[N];
int A = 0;
vector<int> v[N];
int ans[N],n;

void dfs(int s,int p)
{
    sub[s] = 1;
    for(int j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            sub[s] += sub[j];
            ans[s] += ans[j];
        }
    }
    ans[s] += sub[s];
}

void dfs2(int s,int p)
{
    amax(A,ans[s]);
    for(auto j:v[s])
    {
        if(j!=p)
        {
            ans[j] = ans[s] + n - 2*sub[j];
            dfs2(j,s);
        }
    }
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        v[i].clear(),ans[i] = 0,sub[i] = 0;
    A = 0;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0);
    cout<<A<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}
