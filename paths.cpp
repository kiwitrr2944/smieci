#include <bits/stdc++.h> 
#define dbg if(DEBUG)cout
#define pb push_back
#define fi first 
#define sec second
#define ppair(x, end) cout<<x.fi<<' '<<x.sec<<end;
#define last(x) x[x.size()-1]
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;

constexpr int INF = 1e9+7;
bool DEBUG = false;
typedef pair<int, int> pii; 
constexpr int N = 1e5+7;
int fact[N];
int qpow (int a, int b, int MOD = INF) {
    if (b==0) return 1;
    if (b&1) return (a*qpow(a, b-1))%MOD;
    int x = qpow(a, b/2);
    return (x*x)%MOD;
}
int modinv (int a, int MOD = INF) {
    return qpow(a, MOD-2);
}
int binom (int n, int k) {
    return 
    ((fact[n]
    * modinv(fact[k]))%INF
    * modinv(fact[n-k]))%INF;
}

void test() {
    int w, h, a, b, res = 0; cin>>h>>w>>a>>b;
    int dim1 = b+1, dim2 = w-b-1;
    for (int i=0; i<h-a; ++i) {
        int dim3 = i+1, dim4 = h-i;
        int f = binom((dim1-1)*(dim3-1), dim3);
        int s = binom((dim2-1)*(dim4-1), dim4);
        res += (f*s)%MOD;
    }
    cout<<res<<'\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;  
    fact[0] = 1;
    for (int i=1; i<1e5+7; ++i) {
        fact[i] = fact[i-1]*i;
    }
    while(t--) {
        test();
    }
    return 0; 
}