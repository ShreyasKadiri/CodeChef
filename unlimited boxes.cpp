#include<bits/stdc++.h>
#define int long long
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
s.find_by_order(x) xth element in set
x.order_of_key(x) number of elements <x*/
#define ll long long
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define pii pair<int,int>
#define extract_word(s)  stringstream str(s); while(str>>word)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SET(s) cout<<fixed<<setprecision(s)
#define set0(a) memset(a,0,sizeof(a))
#define endl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lower_string(s) transform(all(s),s.begin(),::tolower)
#define upper_string(s) transform(all(s),s.begin(),::toupper)
#define size(s) (int)s.size()
template<typename T,typename U>
bool compare(T x,U y){return(abs(x-y)<=1e-9);}
const ll chotu=1e9+7;
ll bin(ll a,ll b)
{
    if(b==0)
    return 1;
    else if(b&1)
    return (a*bin(((a%chotu)*(a%chotu))%chotu,b/2))%chotu;
    else
    return bin(((a%chotu)*(a%chotu))%chotu,b/2);
}
vi prime;
void sieve(int n)
{
    vi occ(n+1);
    occ[0]=1;
    occ[1]=1;
    for(int i=0;i*i<=n;i++)
    {
        if(!occ[i])
        {
            for(int j=i*i;j<=n;j+=i)
            occ[j]=1;
        }
    }
    for(int i=0;i<=n;i++)
    if(!occ[i])
    prime.pb(i);
}
void solve()
{
ll n,m;
cin>>n>>m;
ll g=__gcd(n,m);
ll l=n*(m/g);
cout<<l;
}
signed main()
{
//code
fastio

int t;
cin>>t;
while(t--)
{
solve();
cout<<endl;
}
}
 
