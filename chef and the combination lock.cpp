#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long LL;
typedef double db;
int get() {
char ch;
while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
if (ch == '-') {
int s = 0;
while (ch = getchar(), ch >= '0' && ch <= '9')s = s * 10 + ch - '0';
return -s;
}
int s = ch - '0';
while (ch = getchar(), ch >= '0' && ch <= '9')s = s * 10 + ch - '0';
return s;
}
const int mo = 998244353;
const int MAXN = (1 << 18) + 5;
const int maxn = (1 << 18);
const db pi = acos(-1);
const int Blk = 31623;
LL quickmi(LL x, LL tim) {
LL ret = 1;
for (; tim; tim /= 2, x = x * x % mo)
if (tim & 1)ret = ret * x % mo;
return ret;
}
LL add(LL x, LL y) {return x + y >= mo ? x + y - mo : x + y;}
LL dec(LL x, LL y) {return x < y ? x - y + mo : x - y;}
struct comp {
db x, y;
comp(const db x_ = 0, const db y_ = 0) {x = x_; y = y_;}
} mi[MAXN], A[MAXN], B[MAXN], C[MAXN], D[MAXN];
comp operator *(comp a, comp b) {return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}comp operator +(comp a, comp b) {return comp(a.x + b.x, a.y + b.y);}
comp operator -(comp a, comp b) {return comp(a.x - b.x, a.y - b.y);}
comp conj(comp a) {return comp(a.x, -a.y);}
int N;
LL js[MAXN], inv[MAXN];
LL calc(int n, int m) {return js[n] * inv[m] % mo * inv[n - m] % mo;}
void prepare() {
fo(i, 0, maxn)mi[i] = comp(cos(pi * 2 / maxn * i), sin(pi * 2 / maxn * i));
js[0] = inv[0] = inv[1] = 1;
fo(i, 1, maxn)js[i] = js[i - 1] * i % mo;
fo(i, 2, maxn)inv[i] = 1ll * (mo - mo / i) * inv[mo % i] % mo;
fo(i, 2, maxn)inv[i] = inv[i] * inv[i - 1] % mo;
}
void DFT(comp *a) {
for (int i = 0, j = 0; i < N; i++) {
if (i < j)swap(a[i], a[j]);
int x = N >> 1;
for (; (j ^ x) < j; x >>= 1)j ^= x;
j ^= x;
}
for (int i = 1, d = 1; i < N; i <<= 1, d++)
for (int j = 0; j < N; j += (i << 1))
for (int k = 0; k < i; k++) {
comp l = a[j + k], r = a[i + j + k] * mi[(maxn >> d) * k];
a[i + j + k] = l - r;
a[j + k] = l + r;
}
}
void IDFT(comp *a) {
DFT(a);
reverse(a + 1, a + N);
fo(i, 0, N - 1)a[i].x /= N, a[i].y /= N;
}
LL origin[MAXN], ny[MAXN], tmp[MAXN];
void multi(LL *a, LL *b, LL *c, int n, int m) {
N = 1;
while (N <= n + m)N <<= 1;fo(i, 0, N - 1)A[i] = B[i] = comp(0, 0);
fo(i, 0, n)A[i] = comp(a[i] / Blk, a[i] % Blk);
fo(i, 0, m)B[i] = comp(b[i] / Blk, b[i] % Blk);
DFT(A), DFT(B);
fo(i, 0, N - 1) {
comp a0 = A[i], a1 = A[i == 0 ? 0 : N - i], b0 = B[i], b1 = B[i == 0 ? 0 : N - i];
comp A0 = (a0 + conj(a1)) * comp(0.5, 0), A1 = (a0 - conj(a1)) * comp(0, -0.5);
comp B0 = (b0 + conj(b1)) * comp(0.5, 0), B1 = (b0 - conj(b1)) * comp(0, -0.5);
C[i] = A0 * B0 + A1 * B0 * comp(0, 1), D[i] = A0 * B1 + A1 * B1 * comp(0, 1);
}
IDFT(C), IDFT(D);
fo(i, 0, n + m) {
db cx = C[i].x, cy = C[i].y, dx = D[i].x, dy = D[i].y;
LL v0 = cx + 0.3, v1 = cy + 0.3, v2 = dx + 0.3, v3 = dy + 0.3;
v0 = v0 % mo, v1 = v1 % mo, v2 = v2 % mo, v3 = v3 % mo;
v0 = v0 * Blk % mo * Blk % mo; v1 = v1 * Blk % mo; v2 = v2 * Blk % mo;
c[i] = (v0 + v1 + v2 + v3) % mo;
}
}
const int L = 100005;
void getny(int n) {
if (n == 1) {ny[0] = quickmi(origin[0], mo - 2); return;}
int l;
getny(l = n / 2 + (n & 1));
multi(ny, ny, tmp, l - 1, l - 1);
multi(tmp, origin, tmp, 2 * l - 2, n - 1);
fo(i, 0, n - 1)ny[i] = (ny[i] * 2 + mo - tmp[i]) % mo;
}
//Bernouli
LL Ber[MAXN];
void Bernouli() {
fo(i, 0, L)origin[i] = dec(0, inv[i + 1]);
getny(L + 1);
fo(i, 0, L)Ber[i] = ny[i];
fo(i, 0, L)origin[i] = ny[i] = 0;
}LL tmp1[MAXN], tmp2[MAXN];
void test() {
int la = get(), lb = get();
fo(i, 0, la)tmp1[i] = get();
fo(i, 0, lb)tmp2[i] = get();
multi(tmp1, tmp2, tmp, la, lb);
fo(i, 0, la + lb)printf("%lld ", tmp[i]);
putchar('\n');
}
LL a[MAXN], T;
int n, k;
LL sum[MAXN];
LL f[MAXN], g[MAXN];
int tk, st[MAXN], len[MAXN];
void solveg() {
fo(i, 1, n)g[i] = a[i];
fo(i, 1, n) {st[i] = i; len[i] = 1;}
tk = n;
for (N = 2; tk > 1; N <<= 1) {
int k1 = 0;
for (int i = 1; i <= tk;) {
int j = i + 1;
for (; j <= tk && len[i] + len[j] < N; j++) {
fo(x, 1, len[i])tmp1[x] = g[st[i] + x - 1];
fo(x, 1, len[j])tmp2[x] = g[st[j] + x - 1];
tmp1[0] = tmp2[0] = 1;
multi(tmp1, tmp2, tmp, len[i], len[j]);
fo(x, 1, len[i] + len[j])g[st[i] + x - 1] = tmp[x];
len[i] += len[j];
}
st[++k1] = st[i];
len[k1] = len[i];
i = j;
}
tk = k1;
}
g[0] = 0;
return;
}LL G1[MAXN], G2[MAXN];
void solvef() {
solveg();
fo(i, 1, n)
if (i & 1)G1[i] = g[i], G2[i] = g[i] * i % mo;
else G1[i] = dec(0, g[i]), G2[i] = dec(0, g[i] * i % mo);
fo(i, 0, k + 5)origin[i] = 0;
origin[0] = 1;
fo(i, 1, n)origin[i] = dec(0, G1[i]);
getny(k + 1);
fo(i, 0, k)tmp1[i] = G2[i], tmp2[i] = ny[i];
multi(tmp1, tmp2, tmp, k, k);
fo(i, 1, k)f[i] = tmp[i];
fo(i, 0, k)origin[i] = ny[i] = 0;
}
LL ans[MAXN];
namespace fft {
typedef double dbl;
struct num {
dbl x, y;
num() { x = y = 0; }
num(dbl x_, dbl y_) : x(x_), y(y_) {}
};
inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline num conj(num a) { return num(a.x, -a.y); }
int base = 1;
vector<num> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
const dbl PI = static_cast<dbl>(acosl(-1.0));
void ensure_base(int nbase) {
if (nbase <= base) {return;
}
rev.resize(1 << nbase);
for (int i = 0; i < (1 << nbase); i++) {
rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
}
roots.resize(1 << nbase);
while (base < nbase) {
dbl angle = 2 * PI / (1 << (base + 1));
//
num z(cos(angle), sin(angle));
for (int i = 1 << (base - 1); i < (1 << base); i++) {
roots[i << 1] = roots[i];
//
roots[(i << 1) + 1] = roots[i] * z;
dbl angle_i = angle * (2 * i + 1 - (1 << base));
roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
}
base++;
}
}
void fft(vector<num>& a, int n = -1) {
if (n == -1) {
n = (int) a.size();
}
assert((n & (n - 1)) == 0);
int zeros = __builtin_ctz(n);
ensure_base(zeros);
int shift = base - zeros;
for (int i = 0; i < n; i++) {
if (i < (rev[i] >> shift)) {
swap(a[i], a[rev[i] >> shift]);
}
}
for (int k = 1; k < n; k <<= 1) {
for (int i = 0; i < n; i += 2 * k) {
for (int j = 0; j < k; j++) {
num z = a[i + j + k] * roots[j + k];
a[i + j + k] = a[i + j] - z;
a[i + j] = a[i + j] + z;
}
}
}
}vector<num> fa, fb;
vector<int> multiply_mod(const vector<int>& a, const vector<int>& b, int m) {
if (a.empty() || b.empty()) {
return {};
}
int eq = (a.size() == b.size() && a == b);
int need = (int) a.size() + (int) b.size() - 1;
int nbase = 0;
while ((1 << nbase) < need) nbase++;
ensure_base(nbase);
int sz = 1 << nbase;
if (sz > (int) fa.size()) {
fa.resize(sz);
}
for (int i = 0; i < (int) a.size(); i++) {
int x = (a[i] % m + m) % m;
fa[i] = num(x & ((1 << 15) - 1), x >> 15);
}
fill(fa.begin() + a.size(), fa.begin() + sz, num {0, 0});
fft(fa, sz);
if (sz > (int) fb.size()) {
fb.resize(sz);
}
if (eq) {
copy(fa.begin(), fa.begin() + sz, fb.begin());
} else {
for (int i = 0; i < (int) b.size(); i++) {
int x = (b[i] % m + m) % m;
fb[i] = num(x & ((1 << 15) - 1), x >> 15);
}
fill(fb.begin() + b.size(), fb.begin() + sz, num {0, 0});
fft(fb, sz);
}
dbl ratio = 0.25 / sz;
num r2(0, -1);
num r3(ratio, 0);
num r4(0, -ratio);
num r5(0, 1);
for (int i = 0; i <= (sz >> 1); i++) {
int j = (sz - i) & (sz - 1);
num a1 = (fa[i] + conj(fa[j]));
num a2 = (fa[i] - conj(fa[j])) * r2;
num b1 = (fb[i] + conj(fb[j])) * r3;num b2 = (fb[i] - conj(fb[j])) * r4;
if (i != j) {
num c1 = (fa[j] + conj(fa[i]));
num c2 = (fa[j] - conj(fa[i])) * r2;
num d1 = (fb[j] + conj(fb[i])) * r3;
num d2 = (fb[j] - conj(fb[i])) * r4;
fa[i] = c1 * d1 + c2 * d2 * r5;
fb[i] = c1 * d2 + c2 * d1;
}
fa[j] = a1 * b1 + a2 * b2 * r5;
fb[j] = a1 * b2 + a2 * b1;
}
fft(fa, sz);
fft(fb, sz);
vector<int> res(need);
for (int i = 0; i < need; i++) {
int64_t aa = llround(fa[i].x);
int64_t bb = llround(fb[i].x);
int64_t cc = llround(fa[i].y);
res[i] = static_cast<int>((aa + ((bb % m) << 15) + ((cc % m) << 30)) % m);
}
return res;
}
} // namespace fft
vector<int> func(vector<int>& a, int l, int r) {
if (l == r) {
vector<int> res = { -a[l], 1};
return res;
}
vector<int> res;
int m = (l + r) >> 1;
vector<int> v1 = func(a, l, m);
vector<int> v2 = func(a, m + 1, r);
res = fft::multiply_mod(v1, v2, mo);
return res;
}
void solve() {
cin >> n;
k = n + 1;
fo(i, 1, n)a[i] = get();fo(i, 0, k)tmp1[i] = Ber[i];
LL T = mo;
for (int i = 1; i <= n; i++) T = min(T, a[i]);
tmp2[0] = 0; tmp2[1] = T;
fo(i, 2, k + 1)tmp2[i] = tmp2[i - 1] * T % mo;
fo(i, 1, k + 1) {
tmp2[i] = tmp2[i] * inv[i] % mo;
if (i & 1)tmp2[i] = dec(0, tmp2[i]);
}
multi(tmp1, tmp2, tmp, k, k + 1);
fo(i, 0, k) {
sum[i] = tmp[i + 1];
sum[i] = sum[i] * js[i] % mo;
if (i & 1)sum[i] = dec(0, sum[i]);
}
solvef();
LL sum1[k + 1] = {0};
for (int i = 0; i <= k; i++) sum1[i] = sum[i];
T = T / 2;
fo(i, 0, k)tmp1[i] = Ber[i];
tmp2[0] = 0; tmp2[1] = T;
fo(i, 2, k + 1)tmp2[i] = tmp2[i - 1] * T % mo;
fo(i, 1, k + 1) {
tmp2[i] = tmp2[i] * inv[i] % mo;
if (i & 1)tmp2[i] = dec(0, tmp2[i]);
}
multi(tmp1, tmp2, tmp, k, k + 1);
fo(i, 0, k) {
sum[i] = tmp[i + 1];
sum[i] = sum[i] * js[i] % mo;
if (i & 1)sum[i] = dec(0, sum[i]);
}
solvef();
LL sum2[k + 1] = {0}, fin[k + 1] = {0};
for (int i = 0; i <= k; i++) {
sum2[i] = (sum[i] * quickmi(2, i)) % mo;
fin[i] = (sum1[i] - sum2[i] + mo) % mo;
}
vector<int> t(n + 1, 0);
for (int i = 1; i <= n; i++) t[i] = a[i];vector<int> res = func(t, 1, n);
LL ans = 0;
for (int i = 0; i <= n; i++) {
ans += ((0LL + res[i]) * fin[i]) % mo;
ans %= mo;
}
for (int i = 1; i <= n; i++) {
ans *= quickmi(a[i] + 1, mo - 2);
ans %= mo;
}
if (n % 2 == 1) {
ans *= -1;
ans += mo;
}
cout << ans << endl;
}
int main() {
prepare();
Bernouli();
int t; cin >> t;
for(int kk=1;kk<=t;kk++)
solve();
}
