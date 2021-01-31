#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        long long n, m;
        int digitCount = 0;

        cin >> n;
        m = n;

        while(m > 0) {
            int curDigit = m % 10;
            m /= 10;
            if(curDigit != 0 && n % curDigit == 0) {
                digitCount++;
            }
        }
        cout << digitCount << "\n";
    }

    return 0;
}
