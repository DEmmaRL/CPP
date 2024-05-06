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

struct Tree {
	typedef lli T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b ; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
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

void solve(){

    int n , q ;
    cin >> n >> q ;

    vector<lli > v(n);
    Tree tree = Tree( n ) ;

    for(int i=0; i<n; ++i){
        cin>>v[i];  
        tree.update( i , v[i] );
    }

    for(int i = 0 ; i < q ; ++i ){
        int tmp ;
        cin>>tmp;

        if(tmp == 1 ){
            int pos , val ;
            cin>>pos >> val ;

            tree.update( pos , val ) ;
        } else {
            int l , r ;
            cin>>l>> r ;
            
            cout<< tree.query( l , r  ) << endl ;
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
