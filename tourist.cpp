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

constexpr int INF = 4e5+7;
bool DEBUG = false;
typedef pair<int, int> pii; 

bool bridge[INF], odw[INF], odw2[INF], ori[INF];
int pre[INF];
int low[INF];
vector <pii> G[INF];
int t;
pii E[INF];
vector <pii> ss;


void count_low (int ind, int oj, int enr) {
    pre[ind] = ++t;
    low[ind] = pre[ind];
    for (auto &[u, i] : G[ind]) {
        if (u == oj) {
            continue;
        }
        if (pre[u]) {
            low[ind] = min(low[ind], pre[u]);
        }
        else {
            count_low(u, ind, i);
            low[ind] = min(low[ind], low[u]);
        }
    }
    bridge[enr] = (low[ind] == pre[ind]); 
}


void dfs (int ind) {
    ss.back().fi++;
    odw[ind] = true;
    for (auto &[u, i] : G[ind]) {
        if (!odw[u] && !bridge[i]) {
            dfs(u);
        }
    }
}


void dfs2 (int ind) {
    odw2[ind] = true;
    for (auto &[u, v] : G[ind]) {
        if (!ori[v]) {
            if (bridge[v]) {
                if (E[v].fi == ind) swap(E[v].fi, E[v].sec);
            }
            else {
                if (E[v].fi == u) swap(E[v].fi, E[v].sec);
            }
        }
        ori[v] = true;

        if (!odw2[u]) {
            dfs2(u);
        }
    }
}


void test() {
    int n, m, a, b; cin>>n>>m; 
    for (int i=1; i<=m; ++i) {
        cin>>a>>b;
        E[i] = {a, b};
        G[a].pb({b, i});
        G[b].pb({a, i});
    }
    
    count_low(1, 0, 0);
    for (int i=1; i<=n; ++i) {
        if (!odw[i]) {
            ss.pb({0, i});
            dfs(i);
        }
    }
    sort(all(ss));
    dfs2(ss.back().sec);
    cout<<ss.back().fi<<'\n';
    for (int i=1; i<=m; ++i) {
        ppair(E[i], '\n');
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--) {
        test();
    }
    return 0; 
}