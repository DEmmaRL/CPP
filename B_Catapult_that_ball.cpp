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


int solve() {

    int n;
    cin>>n;

    if(n==0)
    return 0 ;
    
    int q;
    cin>>q;

    vector< map<int , int> >v(n+1);

    for(int i=1; i<=n; ++i)
    {
        int tmp;
        cin>>tmp;
        v[i][tmp]++;
    }

    

    Sparse< map<int , int> > sp(v, [&](map<int , int> a, map<int , int> b){  for(auto e : a ) { b[e.f] += e.s; } return b; });

    while(q--)
    {
        int l , r; cin>>l>>r;
        

        map<int, int> left = sp.query(0 , l-1) , right = sp.query(l , r) ;

        int maximo = 0 ;


        for( auto e : right )
        {
            //cout<<e.f<<" es "<<e.s<<endl;
            maximo = max(maximo , e.s - left[e.f] ) ;
        }

        cout<<maximo<<endl;
        
    }

    return 1 ;
}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t = 1;
     //cin >> t;
    for (int i = 1; i <= t; i++) {
        while(solve());
    }

}