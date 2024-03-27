#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

//typedef
typedef long long int lli ;
#define fore(i, a, b) for(int i = (a); i < (b); ++i)
#define pll pair<long long, long long>
#define vll vector<long long>
#define all(a) (a).begin(),(a).end()

#define sz(a) int(a.size())

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

template <class T, class F = function<T(const T&, const T&)>>
struct Sparse {
  vector<T> sp[21]; // n <= 2^21
  F f;
  int n;

  Sparse(T* begin, T* end, const F& f) : Sparse(vector<T>(begin, end), f) {}

  Sparse(const vector<T>& a, const F& f) : f(f), n(sz(a)) {
    sp[0] = a;
    for (int k = 1; (1 << k) <= n; k++) {
      sp[k].resize(n - (1 << k) + 1);
      fore (l, 0, sz(sp[k])) {
        int r = l + (1 << (k - 1));
        sp[k][l] = f(sp[k - 1][l], sp[k - 1][r]);
      }
    }
  }

  T query(int l, int r) {
#warning Can give TLE D:, change it to a log table
    int k = __lg(r - l + 1);
    return f(sp[k][l], sp[k][r - (1 << k) + 1]);
  }
};


void solve() {

    int n;
    cin>>n;
    int q;
    cin>>q;

    vector<pll >v(n);

    for(int i=0; i<n; ++i)
    {
        cin>>v[i].f;
        v[i].s = i ;
    }

    

    Sparse< pll > spMin(v, [&](pll a, pll b){ return min(a, b); });
    Sparse< pll > spMax(v, [&](pll a, pll b){ return max(a, b); });

    while(q--)
    {
        int l , r , x; cin>>l>>r>>x;
        l--; r--;

        pll res1 = spMax.query(l, r);
        pll res2 = spMin.query(l, r);

        if( res1.f == res2.f && res1.f == x )
        {
            cout << -1 << endl;
        } else {
            cout << (res1.f == x ? res2.s : res1.s) + 1 << endl;
        }
    }

}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t = 1;
     //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

}