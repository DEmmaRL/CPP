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
    int k = __lg(r - l + 1);
    return f(sp[k][l], sp[k][r - (1 << k) + 1]);
  }
};


void solve() {

    int n , dif , tam ;
    cin>>n>>dif>>tam;

    vector<int>v(n);

    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
    }


    Sparse<int> spMin(v, [&](int a, int b){ return min(a, b); });
    
    Sparse<int> spMax(v, [&](int a, int b){ return max(a, b); });

    int minimo = 0 ;

    int l = 0 , r = n- 1 ;

    while(true)
    {
        while( r >= l && (r - l) + 1 >= tam && spMax.query(l , r ) - spMin.query(l , r) > dif )
        {
            r--;
        }
        if( r < l )
        {
            
            minimo = -1 ;
            break;
        }
        else if( ( r - l ) + 1 < tam )
        {
            cout<<l<<" "<<r<<endl;
            minimo = -1 ;
            break;
        }
        else if( spMax.query(l , r ) - spMin.query(l , r) > dif )
        {
            minimo = -1 ;
            break;
        }
        else
        {
            l=r+1;
            r = n - 1 ;
            minimo++;
        }
    }
    cout<<minimo<<endl;

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