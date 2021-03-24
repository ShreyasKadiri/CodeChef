#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int a[1001];
	a[0]=1;
	a[1]=2;
	a[2]=4;
	for(int i=3;i<1001;++i){
	    a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	while(t--){
	    int n;
	    cin>>n;
	    cout<<a[n]<<"\n";
	}
}
