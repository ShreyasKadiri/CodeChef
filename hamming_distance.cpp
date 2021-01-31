#include <iostream>
using namespace std;

int main() {
    string a,b;
    cin>>a>>b;
    int count=0,real=0;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i]){
            count++;
        }else{
            real++;
        }
    }
    cout<<real;
}
