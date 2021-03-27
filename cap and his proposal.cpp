#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pair tree<pair<int,int>,null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_mutiset tree<int,null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> pi; 
#define PI 3.1415926535897932384
#define FOR(i,vv,n) for(ll i=vv;i<n;i++)
#define FORR(i,n,vv) for(ll i=n-1;i>=vv;i--)
#define ve vector 
#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
#define minind(v) (min_element(v.begin(),v.end())-v.begin())
#define maxe(v) *max_element(v.begin(),v.end())
#define mine(v) *min_element(v.begin(),v.end())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define M 1000000007ll
#define INF 1000000000000000000ll
#define PRECISE cout.precision(18);
#define BS(v,n) binary_search(v.begin(),v.end(),n)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.begin(),v.end(),greater <ll>())
#define uni(v) v.resize(unique(v.begin(),v.end())-v.begin())
#define F first
#define S second
#define GET(i,p) get<p>(i)


int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt 
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
     #endif
    FAST
//  PRECISE

     set <pair<ll,ll> > s;
    unordered_map <ll,ll> m;
    unordered_map <ll,ll> dif;
    dif[1]=1;
    s.insert({2,1});m[2]=1;m[1]=1;
    FOR(i,1,2001){
        FOR(j,1,i+1){
            if(m.find(i)==m.end()&&m.find(j)==m.end()){
                if(i-j!=0&&dif.find(i-j)==dif.end()){
                    dif[i-j]=1;
                    m[i]=1;m[j]=1;
                    s.insert({i,j});
                }
            }
        }
    }

    ll t;
    cin>>t;
    FOR(i1,0,t){
        ll a,b,p,q;
        cin>>a>>b>>p>>q;
        ll z1=a-p;
        ll z2=b-q;
        if(s.find({max(z1,z2),min(z1,z2)})==s.end()){
            cout<<"YES";
        }
        else cout<<"NO";
        cout<<"\n";

    }

return 0;
 }
