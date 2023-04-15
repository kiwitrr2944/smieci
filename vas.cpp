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

string K = "0000000000000000000000000000000000000000";

struct node {
    node *zero, *one, *father;
    int cnt;
    node (node *p) {
        father = p;
        zero = one = NULL;
        cnt = 0;
    }
};

string d2b (int k) {
    string res = "";
    while (k>0) {
        char x = (k%2) + '0';
        res = x + res;
        k /= 2;
    }
    while (res.size()<K.size()) res = '0'+res;
    return res;
}

void adds (node *q, string s) {
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == '1') {
            if (q->one) {
                q = q->one;
            }
            else {
                node *p = new node(q);
                q->one = p;
                q = q->one;
            }
        }
        else {
            if (q->zero) {
                q = q->zero;
            }
            else {
                node *p = new node(q);
                q->zero = p;
                q = q->zero;
            }
        }
        q->cnt++;
    }
}


void remove(node *q, string s) {
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == '1') {
            q = q->one;
            q->cnt--;
            if (q->cnt == 0) {
                q->father->one = NULL;
                return;
            }
        }
        else { 
            q = q->zero;
            q->cnt--;
            if (q->cnt == 0) {
                q->father->zero = NULL;
                return;
            }
        }
    }
}

int find_max(node *p, string s) {
    int res = 0, v = (1ll<<(K.size()-1));
    for (int i=0; i<s.size(); ++i) {
        if (s[i]=='1') {
            if (p->zero) {
                res += v;
                p = p->zero;
            }
            else {
                p = p->one;
            }
        }
        else {
            if (p->one) {
                res += v;
                p = p->one;
            }
            else {
                p = p->zero;
            }
        }
        v >>= 1;
    }
    return res;
}


void test() {
    string s;
    int n, k; cin>>n;
    char c; 
    node *root = new node(NULL);
    root->cnt = 100000000;
    adds(root, K);
    for (int i=0; i<n; ++i) {
        cin>>c>>k;
        s = d2b(k);
        if (c == '+') {
            root->cnt++;
            adds(root, s);
        }
        else if (c == '-') {
            remove(root, s);
        }
        else {
            int mx = find_max(root, s);
            cout<<mx<<'\n';
        }
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