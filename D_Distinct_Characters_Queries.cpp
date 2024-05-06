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
	//typedef map<int, int> T;

  struct T{
    map<lli, lli> mapa ;
    T( map< lli , lli > mapa = {} ): mapa(mapa) {}
    T operator + (const T &n){
      map<lli, lli> tmp ;

      for(auto e : mapa ){

        tmp[e.ff] += e.ss ;
      }
      for(auto e : n.mapa ){
        tmp[e.ff] += e.ss ;
      }

      return T( tmp );
    }
    void set( char a ){
      mapa.clear();
      mapa[a]++;
    }
  } ;
	
  static T unit ;
	T f(T a, T b) { return a + b ; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}

	void update(int pos, char val) {
		for (s[pos += n].set( val ); pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
        if (b % 2 == 1) ra = f(ra, s[b++]);
        if (e % 2 == 1) rb = f(s[--e], rb);
    }
    return f(ra, rb);
}
 
};

Tree::T Tree::unit;

void solve(){
  string input ;
  cin >> input ;
  int n = input.size();
  Tree segtree(n);
    for (int i = 0; i < n; ++i) {
        segtree.update(i, input[i]);
    }

    // Example usage of update and query functions
    int num_ops;
    cin >> num_ops;
    for (int i = 0; i < num_ops; ++i) {
        int op_type;
        cin >> op_type;
        if (op_type == 1) {
            int pos;
            char new_char;
            cin >> pos >> new_char;

            if(input[pos-1] != new_char )
              segtree.update(pos - 1, new_char); // Adjusting for 0-based indexing
            else 
              input[pos-1] = new_char ;

        } else if (op_type == 2) {
            int start, end;
            cin >> start >> end;
            int res = 0 ;

            auto a = segtree.query(start - 1, end).mapa; // Adjusting for 0-based indexing
        
            for(auto e : a ){
              if( e.ss >0  ){
                res++;
              }
            }
            cout<<res<<endl;

        }
    }
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
