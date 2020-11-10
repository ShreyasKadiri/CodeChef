#include <stdio.h>
#include <stdlib.h>

int main(){

long n,k;
scanf("%ld",&n);
scanf("%ld",&k);

long arr[n];

for (int i=0;i<n;i++){
scanf("%ld",&arr[i]);
}

long result=0;
for (int i=0; i<n; i++){
for (int j=i+1; j<n; j++){ 
if (arr[i]+arr[j]<k)
result=result+1;
}
}
printf("%ld",result);
return 0;
}
