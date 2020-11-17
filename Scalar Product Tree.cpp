
#include<bits/stdc++.h>
using namespace std;
 
#define ll long
const int N = 500005;
#define M2 (1LL << 32)
#define vll vector<int>
 
int n, M, K, cur, Arr[N], LVL[N], DP[20][N];
int BL[N << 1], ID[N << 1], HMM[N];
ll l[N], r[N], lol[N], sos[N],  ANS[N], dd[N], ror[N];;
bool VIS[N];
vll adj[N];
 
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow-1);
  int seg = (x < hpow) ? (
    (y < hpow) ? 0 : 3
  ) : (
    (y < hpow) ? 1 : 2
  );
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  int64_t subSquareSize = int64_t(1) << (2*pow - 2);
  int64_t ans = seg * subSquareSize;
  int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}
 
struct query{
  int id, l, r, lc;
  int64_t ord;
 
  inline void calcOrder() {
    ord = gilbertOrder(l, r, 21, 0);
  }
}Q[N];
 
inline bool operator<(const query &a, const query &b) {
  return a.ord < b.ord;
}
 
// Set up Stuff
void dfs(int u, int par, int h){
  l[u] = ++cur; 
  ID[cur] = u;
  LVL[u] = h;
  for (int i = 1; i < 20; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
  for (int i = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    if (v == par) continue;
    DP[0][v] = u;
    dfs(v, u, h + 1);
  }
  r[u] = ++cur; ID[cur] = u;
}
 
// Function returns lca of (u) and (v)
inline int lca(int u, int v){
  if (LVL[u] > LVL[v]) swap(u, v);
  for (int i = 20 - 1; i >= 0; i--)
    if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
  if (u == v) return u;
  for (int i = 20 - 1; i >= 0; i--){
    if (DP[i][u] != DP[i][v]){
      u = DP[i][u];
      v = DP[i][v];
    }
  }
  return DP[0][u];
}
 
inline void check(long  x, long& res){
  if((VIS[x]))
  {
    if(HMM[LVL[x]] == 2) 
    {
      HMM[LVL[x]]--; res -= lol[LVL[x]];    
      res += M2; res %= M2;
      sos[LVL[x]] -= Arr[x]; sos[LVL[x]] += M2; sos[LVL[x]] %= M2;
      ror[LVL[x]] -= (Arr[x] * sos[LVL[x]]);   ror[LVL[x]] += M2; ror[LVL[x]] %= M2;
    }
    else if(HMM[LVL[x]] == 3) 
    {
      HMM[LVL[x]]--;
      sos[LVL[x]] -= Arr[x]; sos[LVL[x]] += M2; sos[LVL[x]] %= M2;
        ror[LVL[x]] -= (Arr[x] * sos[LVL[x]]); ror[LVL[x]] += M2; ror[LVL[x]] %= M2;
      res += ror[LVL[x]]; res %= M2; lol[LVL[x]] = ror[LVL[x]];
    }
    else {
      HMM[LVL[x]]--;
      sos[LVL[x]] -= Arr[x]; sos[LVL[x]] += M2; sos[LVL[x]] %= M2;
      ror[LVL[x]] -= (Arr[x] * sos[LVL[x]]);   ror[LVL[x]] += M2; ror[LVL[x]] %= M2;
    }
  }
  else 
  {
    if(HMM[LVL[x]] == 1) {
      HMM[LVL[x]]++; ror[LVL[x]] += (Arr[x] * sos[LVL[x]]); ror[LVL[x]] %= M2;
      res += ror[LVL[x]]; res %= M2;
      sos[LVL[x]] += Arr[x]; sos[LVL[x]] %= M2;
      lol[LVL[x]] = ror[LVL[x]];
    }
    else if(HMM[LVL[x]] == 2) {
      HMM[LVL[x]]++;
      ror[LVL[x]] += (Arr[x] * sos[LVL[x]]); ror[LVL[x]] %= M2;
      sos[LVL[x]] += Arr[x]; sos[LVL[x]] %= M2;
      res -= lol[LVL[x]]; res += M2; res %= M2;
    }
    else {
      HMM[LVL[x]]++;
      ror[LVL[x]] += (Arr[x] * sos[LVL[x]]); ror[LVL[x]] %= M2;
      sos[LVL[x]] += Arr[x];  sos[LVL[x]] %= M2;
    }
  }
 
  VIS[x] ^= 1;
}
 
void dfsc(int v, int p);
 
void compute(){
 
  // Perform standard Mo's Algorithm
  ll curL = Q[0].l, curR = Q[0].l - 1, res = 0;
 
  for (int i = 0; i < M; i++){
 
    while (curL < Q[i].l) check(ID[curL++], res);
    while (curL > Q[i].l) check(ID[--curL], res);
    while (curR < Q[i].r) check(ID[++curR], res);
    while (curR > Q[i].r) check(ID[curR--], res);
 
    int u = ID[curL], v = ID[curR];
 
    // Case 2
    if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
 
    ANS[Q[i].id] = (res + dd[Q[i].lc]) % M2; 
 
    if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
  }
 
  for (int i = 0; i < M; i++) printf("%ld\n", ANS[i]);
}
 
int main(){
 
  int u, v, x;
 
  while (scanf("%d %d", &n, &M) != EOF){
 
    // Inputting HMMues
    for (int i = 1; i <= n; i++) scanf("%d", &Arr[i]);
 
    // Inputting Tree

for (int i = 1; i < n;i++){
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
 
    // Preprocess
    DP[0][1] = 1;
    dfs(1, -1, 1);
    dd[1] = Arr[1] * Arr[1];
    dd[1] %= M2;
 
    dfsc(1, 0); 
 
    for (int i = 0; i < M; i++){
      scanf("%d %d", &u, &v);
      Q[i].lc = lca(u, v);
      if (l[u] > l[v]) swap(u, v);
      if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
      else Q[i].l = r[u], Q[i].r = l[v];
      Q[i].id = i;
      Q[i].calcOrder();
    }
 
    sort(Q, Q + M);
    compute();
  }
}
 
void dfsc(int v, int p)
{
  for(auto i: adj[v])
  {
    if(i != p) {
       dd[i] = (dd[v] + (Arr[i] * Arr[i]) % M2) % M2;
       dfsc(i, v);
      }
  }
}
