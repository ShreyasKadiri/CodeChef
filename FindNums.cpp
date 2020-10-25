#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include<math.h>
int main()
{
  long int p,s,i,j,k,l=1,x,y,q;
  cin>>s>>p>>k;
  
  if(k==1){
    if(s==p)
    cout<<s<<endl;
    l=0;
  }
  
  else if(k==2){
    for(i=1; i<=sqrt(p)+1; i++){
      for(j=1; j<s; j++)
      if(i+j==s && i*j==p){
        cout<<i<<" "<<j;
        l=0;
        break;
      }
      
      if(l==0)
      break;
    }
  }
  
  else if(k==3){
    for(i=1; pow(i,3)<=p; i++){
      for(j=1; j<s; j++){
        for(x=1; x<s; x++){
          if(i+j+x==s && i*j*x==p){
           cout<<i<<" "<<j<<" "<<x;
           l=0;
           break;
          }
        }
        
        if(l==0)
        break;
      }
      if(l==0)
      break;
    }
  }
  
  else if(k==4){
    for(i=1; pow(i,4)<=p; i++){
      for(j=1; j<s; j++){
        for(x=1; x<s; x++){
          for(y=1; y<s; y++){
          if(i+j+x+y==s && i*j*x*y==p){
     cout<<i<<" "<<j<<" "<<x<<" "<<y;
           l=0;
           break;
             }
          }
         if(l==0)
         break;
        }
        if(l==0)
        break;
      }
      if(l==0)
      break;
    }
  }
  if(l==1)
  cout<<"NO";
}
