#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

#define INF 1e9

struct Tree {
    struct T {
        map<char, int> mapa;
        T(const map<char, int>& mapa = {}) : mapa(mapa) {}
        T operator+(const T& n) {
            map<char, int> tmp;
            for (const auto& e : mapa) {
                tmp[e.first] += e.second;
            }
            for (const auto& e : n.mapa) {
                tmp[e.first] += e.second;
            }
            return T(tmp);
        }
        void set(char a) {
            mapa.clear();
            mapa[a]++;
        }
        int countUnique() {
            return mapa.size();
        }
    };

    static T unit;
    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, char val) {
        pos += n;
        s[pos].set(val);
        for (pos /= 2; pos >= 1; pos /= 2) {
            s[pos] = s[pos * 2] + s[pos * 2 + 1];
        }
    }

    int query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2 == 1) ra = ra + s[b++];
            if (e % 2 == 1) rb = s[--e] + rb;
        }
        return (ra + rb).countUnique();
    }
};

Tree::T Tree::unit;

void solve(){
  string s ;
  cin >> s ;

  int n = s.size() ;

  vector<int> v( n ) ;

  Tree tree( n ) ;

  for(int i = 0 ; i < n ; ++i ){
    v[ i ] = s[ i ] ;
    tree.update( i , v[i] ) ;
  }

  int q ;
  cin >> q ;
  
  while( q-- ){
    int a ;
    cin >> a ;
    //cout<<a<<" "<<b<<" "<<c << endl ;

    if( a == 1 ){
      int b ;
      char c ;
      cin>> b >> c ;

      //cout<<a<<" aaa "<<b<<" "<<c<<endl;
      
      b-- ;

      tree.update( b , c ) ; 

      v[ b ] = c ;

    } else {

      int b,c ;
      cin>>b>>c ;
      
      map< lli , lli > mapa  ;

      lli res =  tree.query(  b-- , c-- ) ;
      
      
      //cout<<"para "<<b<<" - "<< c << endl ;
      for(auto e : mapa ){
        if(e.ss > 0 ){
          //cout<<(char)(e.ff)<<" " ;
          res++;
        }
      }
      /*
      cout<<endl ;
      for(auto e : mapa ){
        if(e.ss > 0 ){
          cout<<e.ss<<" " ;
          //res++;
        }
      }
      cout<<endl ;
      */
      cout << res << endl ;

    }
    /*
    for(int i = 0 ; i < n ; ++i ){
      cout<<(char)(v[i]);
    }
    cout<<endl;
    */

  }
  /*
  map< lli , lli > mapa = tree.query( 0 , 0 , n - 1 , 0 , 0 ).mapa ;

  for(auto e : mapa ){
    if(e.ss>0)
    cout<<(char)(e.first)<<" ";
  }
  cout<<endl;
  */
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
