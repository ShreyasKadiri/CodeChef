#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;
unsigned long long a[110];
vector<unsigned long long> d;
int vis[110];
void dfs(int count)
{
    if(count==n)
    {
        for(vector<unsigned long long >::iterator i=d.begin();i!=d.end();i++)
            cout<<*i<<' ';
        cout<<endl;
        return;
    }
    unsigned long long t=*(d.end()-1);
    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
    if(a[i]*3==t||t*2==a[i])
    {
        d.push_back(a[i]);
        vis[i]=1;
        dfs(count+1);
        vis[i]=0;
        d.pop_back();
    }
    }
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            vis[i]=1;
            d.push_back(a[i]);
            dfs(1);
            vis[i]=0;
            d.pop_back();
        }
    }
    return 0;
}
