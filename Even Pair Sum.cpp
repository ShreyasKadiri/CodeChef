#include <iostream>
#define  ll long long int
using namespace std;

int main() {
	ll  t;
	cin>>t;
	while(t--){
	    ll first,second,totalPairs=0;
	    cin>>first>>second;
	    
	    if(first%2==0 && second%2==0){
	        totalPairs+=(first/2) * (second/2);
	         totalPairs+=(first/2) * (second/2);
	    }
	    
	    
	    else if(first%2!=0 && second%2!=0){
	        totalPairs+=((first+1)/2) * ((second+1)/2);
	         totalPairs+=(first/2) * (second/2);
	    }
	    
	    else if(first%2!=0 && second%2==0){
	        totalPairs+=(first/2) * (second/2);
	         totalPairs+=((first+1)/2) * (second/2);
	    }
	    
	    
	    else if(first%2==0 && second%2!=0){
	        totalPairs+=(first/2) * (second/2);
	         totalPairs+=(first/2) * ((second+1)/2);
	    }
	    std::cout << totalPairs << std::endl;   
	}	
	return 0;
}
