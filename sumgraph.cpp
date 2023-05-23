#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int add(int x) {
    cout<<"+ "<<x<<'\n';
    cout.flush();
    cin>>x;
    return x;
}


int query(int a, int b) {
    cout<<"? "<<a<<' '<<b<<'\n';
    cout.flush();
    cin>>a;
    return a;
}

void guess(vector <int> & res) {
    cout<<"! ";
    for (auto x : res) {
        cout<<x<<' ';
    }
    reverse(all(res));
    for (auto x : res) {
        cout<<x<<' ';
    }
    cout<<'\n';
    cout.flush();
    cin>>res[0];
}

void test() {
    int n; cin>>n;
    vector <int> res(n+1);
    vector <int> odl(n+1, 0);
    vector <int> path(n+1);
    vector <int> occ(n+1, 0);
    int l = 1, r = n;
    for (int i=1; i<=n; i++) {
        if (i%2==1) path[i] = r--;
        else path[i] = l++;
    }

    add(n+1);
    add(n);

    for (int i=2; i<=n; ++i) {
        odl[i] = query(1, i);
        occ[odl[i]]++; 
    }

    int mx = 0;
    for (int i=1; i<=n; ++i) {
        if (occ[i] > 0) {
            mx = i;
        }
    }
    int other = n - mx - 1;
    int a = 0, b = 0, c = 0;
    for (int i=1; i<=n; ++i) {
        if (odl[i] == other) {
            if (a == 0) a = i;
            else b = i;
        }
        else if (odl[i] == mx) {
            c = i;
        }
    }
    if (a != 1) {
        int odl = query(a, c);
        if (odl != n-1) {
            a = b;
        }
    }

    res[a] = path[1];
    res[c] = path[n];

    for (int i=1; i<=n; ++i) {
        if (i != c && i != a) {
            int odl = query(a, i);
            res[i] = path[1+odl];
        }
    }
    vector <int> res2;
    for (int i=1; i<=n; ++i) res2.push_back(res[i]);
    guess(res2);
}



int main () {
    int t; cin>>t;
    while (t--) {
        test();
    }
}