#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int inf = 1e9;

struct Edge {
  int to, nxt, flow;
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int flow) {
  edge[++tot] = (Edge){v, head[u], flow};
  head[u] = tot;
}
void addedge(int u, int v, int flow) {
  add(u, v, flow), add(v, u, 0);
}

struct node {
  int x, y;
} q[N];
int a[N], c[N];
int n, m, S, T;

vector<int> adj[N];
int vis[N], col[N];
void dfs(int u) {
  vis[u] = 1;
  for (auto v: adj[u]) {
    if (vis[v]) continue;
    col[v] = col[u] ^ 1;
    dfs(v);
  }
}

int flip(int x) {
  return x > n ? x - n : x + n;
}

int dep[N];
bool bfs(int S, int T) {
  queue<int> q;
  for (int i = 1; i <= T; i++) dep[i] = 0;
  q.push(S), dep[S] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to, fl = edge[i].flow;
      if (!dep[v] && fl) {
        dep[v] = dep[u] + 1;
        q.push(v);
      }
    }
  }
  return dep[T] > 0;
}
int dfs(int u, int T, int ans) {
  if (u == T) return ans;
  int over = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, fl = edge[i].flow;
    if (dep[v] == dep[u] + 1 && fl) {
      int res = dfs(v, T, min(ans, fl));
      edge[i].flow -= res, edge[i ^ 1].flow += res;
      ans -= res, over += res;
      if (!ans) break;
    }
  }
  return over;
}
int Dinic(int S, int T) {
  int ans = 0;
  while (bfs(S, T)) ans += dfs(S, T, 1e9);
  return ans;
}

int main() {
  int Test; scanf("%d", &Test);
  while (Test--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i++) {
      vis[i] = 0;
      adj[i].clear();
    }
    S = n + 1, T = n + 2;
    for (int i = 1; i <= T; i++) head[i] = 0;
    tot = 1;
    for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= m; i++) {
      int x, y; scanf("%d%d", &x, &y);
      if (x < 0) x = n - x;
      if (y < 0) y = n - y;
      q[i] = {x, y};
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
      adj[i].push_back(n + i);
      adj[n + i].push_back(i); 
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (!vis[i]) {
        col[i] = i > n;
        dfs(i);
      }
    }
    for (int i = 1; i <= m; i++) {
      int x = q[i].x, y = q[i].y;
      if ((x > n) ^ col[x]) x = flip(x);
      if ((y > n) ^ col[y]) y = flip(y);
      //cerr << "x = " << x << " y = " << y << endl;
      if (y > n) addedge(x, y - n, inf);
      else addedge(y, x - n, inf);
    }
    for (int i = 1; i <= n; i++) {
      if (col[i]) {
        a[i] ^= 1;
      }
      if (a[i]) {
        addedge(S, i, 0), addedge(i, T, c[i]);
      } else {
        addedge(S, i, c[i]), addedge(i, T, 0);
      }
    }
    printf("%d\n", Dinic(S, T));
  }
  return 0;
}
