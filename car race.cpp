#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


long long powe(long long x,  long long y, long long mod)
{
    long long res = 1;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y / 2;
        x = (x * x) % mod;
    }
    return res;
}

long long gcde(long long a, long long b) {
  while(a != 0) {
     long long a1 = b % a, b1 = a;
     a = a1; b = b1;
  }
  return b;
}
const long long mod = 1e9 + 7;
int main()
{
  fast_io();
  long long n, m;
  cin >> n >> m;
  long long sum = 0;
  for (long long i = 0; i < n; ++i)
  {
    long long a;
    cin >> a;
    sum += a;
    sum %= mod;
  }

  while(m--) {

   long long a;
   cin >> a;

   if(n < a) {
    cout << "0\n";
    continue;
  }

   long long ans = (n - a) * sum;
   ans %= mod;
   ans *= powe(n, mod - 2, mod);
   ans %= mod;
   cout << ans << "\n";
  }
   return 0;
}
