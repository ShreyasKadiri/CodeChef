#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    unsigned long long n;
    cin >> t;
    
    while (t--){
        cin>>n;
        cout<<floor(log2(n))+1 << endl;
    }
    return 0;
}
