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
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a or b ; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve(){
    int n , q ;
    cin>>n >> q ;

    int tam = 1 ;

    for( int i = 0 ; i < n ; ++i ) {
        tam*=2;
    }

    Tree tree(tam);

    for(int i=0; i<n; ++i){
        int tmp;
        cin>>tmp;

        tree.update(i , tmp);
    }

    while(q--){
        int pos , val;
        cin>>pos>>val;
        pos--;

        tree.update(pos, val);

        cout<< tree.query( 0 , 0) <<endl ;
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
