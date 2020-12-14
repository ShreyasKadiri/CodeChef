#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <climits>
#include <cstring>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <initializer_list>
#include <string.h>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
#define int long long int
#define double long double
#define fr(i, s, n) for (int i = s; i <= n; ++i)
#define frr(i, s, n) for (int i = s; i >= n; --i)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define M 998244353
const int inf = (1LL << 60) - 1;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// no. of cyclic shift needed = (j - pos[j] + N) % N;
// no. of cyclic shift needed = (final_pos[j] - curr_pos[j] + N) % N;
// a + b = (a ^ b) + 2 * (a & b);

const int N = 2e5 + 5;
vector<int> graph[N];
vector<bool> visited(N);
int a[N], available[50];
int ans[50], mn[N];
int n, m, k, p, x, y, q, z;
string s, t;

unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> dp;
unordered_map<int, unordered_map<int, unordered_map<int, int>>> vis, cnt;
unordered_map<int, int> recursion(int pos, int last, int cost, int mask)
{
    unordered_map<int, int> curr;
    if (pos > n)
    {
        curr[cost]++;
        return curr;
    }

    if (vis[pos][last][mask])
    {
        unordered_map<int, int> mp = dp[pos][last][mask];
        int r = cnt[pos][last][mask];
        for (auto x : mp)
        {
            curr[x.first + cost - r] = x.second;
        }
        return curr;
    }

    vis[pos][last][mask] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (!(mask & (1LL << i)))
        {
            int add = 0;
            if (i % last == 0 && available[i / last])
                add++;

            unordered_map<int, int> mp;
            mp = recursion(pos + 1, i, cost + add, mask ^ (1LL << i));
            for (auto x : mp)
            {
                curr[x.first] += x.second;
                curr[x.first] %= M;
            }
        }
    }

    dp[pos][last][mask] = curr;
    cnt[pos][last][mask] = cost;

    return curr;
}

void solve()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        available[i] = s[i - 1] - '0';

    unordered_map<int, int> ans;
    for (int i = 1; i <= n; i++)
    {
        unordered_map<int, int> mp;
        mp = recursion(2, i, 0, (1LL << i));
        for (auto x : mp)
        {
            ans[x.first] += x.second;
            ans[x.first] %= M;
        }
    }

    for (int i = 0; i <= n - 1; i++)
        cout << ans[i] << " ";
    cout << endl;
}

signed main()
{
    FAST int T = 1;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    while (T--)
    {
        solve();
    }
}
