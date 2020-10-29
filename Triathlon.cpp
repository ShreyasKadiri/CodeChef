#include <bits/stdc++.h>
using namespace std ;

#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define eb emplace_back
#define endl '\n'

typedef long long int ll ;

vector <vector<int>> a ;
vector <int> b(3) ;

bool sortt(vector<int>& v1, vector<int>& v2) {
	 return (v1[1] + v1[2]) > (v2[1] + v2[2]) ;
}

void solve()
{
	 int n;
	 cin >> n ;
	 int min_amount = 0 ;
	 for (int i = 0 ; i < n; i++) {
	 	 cin >> b[0] >> b[1] >> b[2] ;
	 	 a.eb(b) ;
	 	 min_amount += b[0] ;
	 }
	 sort(a.begin() , a.end() , sortt) ;
	 int ans = 0 ;
	 int rem = 0 ;
	 int add = a[n - 1][1] + a[n - 1][2] ;
	 for (int i = 0 ; i < n ; i++) {
	 	 ans += a[i][0] ;
	 	 rem = max(rem , (ans + a[i][1] + a[i][2] - min_amount)) ;
	 }
	 if (rem < 0) rem = 0 ;
	 add = max(add , rem) ;
	 cout << (ans + add) << endl ;
}

int main()
{
	 ios ;
   solve();
}
