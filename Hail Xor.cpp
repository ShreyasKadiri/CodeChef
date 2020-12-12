#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
while(t--){
        long long int n,x;
        cin>>n>>x;
        
        long long int a[n];
        for(long long int i=0; i<n; i++)
            cin>>a[i];
           
        long long int i = 0,z,k,p,r,j;
        for(k=x; k>0,i<n-1; k--){
            int flag = 0;
            p = log(a[i])/log(2);
            r = 1<<p;
            a[i] = a[i] ^ r;
            
            
            for(j=i+1; j<n; j++){
                if(a[j]^r < a[j]){
                    a[j] = a[j]^r;
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                a[n-1] = a[n-1] ^ r;
            }
            
            while(a[i]<=0)
                i++;
            z=k+1;
            
        }
        if(z>0){
            if(n<3 && z%2>0){
                a[n-1] = a[n-1]^1;
                a[n-2] = a[n-2]^1;
            }
        }
        for(long long int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
	return 0;
}

