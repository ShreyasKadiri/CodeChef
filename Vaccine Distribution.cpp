#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	short int t;
	cin>>t;
	while(t--){
	    long long n,d;
	    cin>>n>>d;
	    long long arr[n];
	    
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }   
	    
	    long long danger=0;
	    long long no_danger=0;
	    for(int i=0; i<n; i++){
	        if(arr[i]>=80 || arr[i]<=9){
	            danger++;
	        }
	        else{
	            no_danger++;
	        }
	    }
	    
	    long long ans = ceil((double)danger/(double)d)
	                     + 
	                    ceil((double)no_danger/(double)d);
	    std::cout << ans << std::endl;
	}
	return 0;
}
