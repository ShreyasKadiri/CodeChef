#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  
  while(t--)
  {
      int r;
      cin>>r;
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];
      int f=n;
      for(int i=0;i<n;i++)
      {
          if(a[i]>=r)
          {
              f=i+1;
              break;
          }
      }
      cout<<f<<endl;
  }
}
