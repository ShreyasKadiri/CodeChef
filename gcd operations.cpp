#include <bits/stdc++.h>

using namespace std;
//--------------------------------------Useful Macros------------------------------------

//-------Constants----------
#define MOD 1000000007
#define INF 1000000000000000001

//------Standard Input Output Tweaks------
#define fin freopen("D:/Programs/Competitive/input", "r", stdin);
#define fout freopen("D:/Programs/Competitive/output", "w", stdout);
#define sync ios_base::sync_with_stdio(false);
#define fastio sync cin.tie(NULL);
#define fileio fin fout

//--------Miscellaneous--------
#define F first
#define S second
#define pb push_back
#define sz(x) x.size()
#define isOdd(n) (n % 2)
#define isEven(n) (n % 2 == 0)
#define all(p) p.begin(), p.end()
#define notend(itr, s) (itr != s.end())
#define min3(a, b, c) min((a), min((b), (c)))
#define max3(a, b, c) max((a), max((b), (c)))
#define isPresent(x, s) (s.find(x) != s.end())
#define inrange(x, l, h) ((x >= l) && (x <= h))
#define myfor(x, s, e) for (int x = s; x < e; x++)
#define deb(x) cout << #x << " : " << x << endl;
#define endl '\n'

//-------------------------------------End of Macros------------------------------------

typedef long long int lli;

typedef pair<lli, lli> pii;
typedef vector<lli> vi;
typedef set<lli> si;
typedef unordered_map<lli, lli> umii;
typedef unordered_set<lli> usi;

bool CustomCompare(const pii &, const pii &);

lli modmul(lli, lli);
lli modadd(lli, lli);
lli modsub(lli, lli);
lli ncr(lli, lli);
void facto();
lli fpow(lli x, lli y, lli p = MOD);
//------------------------------Declaring Trace Functions----------------------------------

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P);
template <class T>
ostream &operator<<(ostream &os, vector<T> V);
template <class T>
ostream &operator<<(ostream &os, set<T> S);
template <class T>
ostream &operator<<(ostream &os, unordered_set<T> S);
template <class T, class T1>
ostream &operator<<(ostream &os, map<T, T1> S);
template <class T, class T1>
ostream &operator<<(ostream &os, unordered_map<T, T1> S);

//-----------------------------------End of Declarations------------------------------------
vi fact(3000007, 0);
//---------------------------------------SOLVE HERE----------------------------------------
int ispos(vi ar, int num, lli m, lli c)
{
    lli sum = c;
    for (auto v : ar)
    {
        sum += v % num;
    }
    if (sum <= m)
        return 1;
    return 0;
}
void solve()
{
    lli n, k;
    cin >> n >> k;
    vi ar(n);
    lli low = 10000000;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        low = min(low, ar[i]);
    }
    int l = 1, r = low;
    int m;
    while (l < r)
    {
        m = (l + r) / 2;
        // cout << m << endl;
        if (l == m)
            break;
        int f = 0;
        for (int i = 0; i < 5 && i + m <= r; i++)
        {
            if (ispos(ar, i + m, k, low - m - i))
            {
                l = m;
                f = 1;
            }
        }
        for (int i = r; i >= m && r - i <= 5; i--)
        {
            if (ispos(ar, i, k, low - i))
            {
                l = i;
                f = 1;
                break;
            }
        }
        if (!f)
            r = m - 1;
    }
    // cout << l << " " << r;
    if (l > r)
    {
        if (ispos(ar, l, k, low - l))
        {
            cout << l << endl;
            return;
        }
    }
    else
    {
        if (ispos(ar, r, k, low - r))
        {
            cout << r << endl;
            return;
        }
    }
    cout << m << endl;
}
//----------------------------------------MAIN HERE----------------------------------------

int main()
{
    // facto();
#ifndef ONLINE_JUDGE
    fileio;
    // fin;
#endif
    fastio;
    int t = 1;
    // cin >> t;
    int i = 1;
    while (i <= t)
    {
        // cout << "Case #" << i << ": ";
        solve();
        i++;
    }

    return 0;
}
//----------------------------------Defining Trace Functions------------------------------

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << ", " << P.second << ")";
}

template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    if (sz(V))
    {
        os << "[" << V[0];
        for (int i = 1; i < sz(V); i++)
            os << ", " << V[i];
        return os << "]";
    }
    return os << "[]";
}

template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{";
    for (auto s : S)
        os << s << ", ";
    return os << "}";
}

template <class T>
ostream &operator<<(ostream &os, unordered_set<T> S)
{
    os << "{";
    for (auto s : S)
        os << s << ", ";
    return os << "}";
}

template <class T, class T1>
ostream &operator<<(ostream &os, map<T, T1> S)
{
    os << "{" << endl;
    for (auto s : S)
        os << "\t" << s.first << " : " << s.second << "," << endl;
    return os << "}" << endl;
}

template <class T, class T1>
ostream &operator<<(ostream &os, unordered_map<T, T1> S)
{
    os << "{" << endl;
    for (auto s : S)
        os << "\t" << s.first << " : " << s.second << "," << endl;
    return os << "}" << endl;
}

//---------------------------------------End of Definitions--------------------------------

//stable sort by first then second both in increasing
bool CustomCompare(const pii &i, const pii &j)
{
    if (i.first == j.first)
        return i.second < j.second;
    return i.first < j.first;
}

//------------------------------------Modular Arithmetic-----------------------------------
lli modmul(lli a, lli b)
{
    lli ret = (a % MOD) * (b % MOD);
    ret %= MOD;
    return ret;
}
lli modadd(lli a, lli b)
{
    lli ret = (a % MOD) + (b % MOD);
    ret %= MOD;
    return ret;
}
lli modsub(lli a, lli b)
{
    a = a % MOD;
    b = b % MOD;
    if (a < b)
        a += MOD;
    lli ret = a - b;
    ret %= MOD;
    return ret;
}
lli fpow(lli x, lli y, lli p)
{
    // lli p = MOD;
    x = x % p;
    lli sum = 1;
    while (y)
    {
        if (y & 1)
            sum = sum * x;
        sum %= p;
        y = y >> 1;
        x = x * x;
        x %= p;
    }
    return sum;
}
void facto()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 3000007; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
lli ncr(lli n, lli r)
{
    if (r > n)
        return 0;
    lli res = 1;
    res = fact[n];
    res = (res * (fpow(fact[r], MOD - 2))) % MOD;
    res = (res * (fpow(fact[n - r], MOD - 2))) % MOD;
    return res;
}
