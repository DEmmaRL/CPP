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

void solve(){

    int n;
    cin>>n;

    map< pair<int , int > , int > values;
    map< string , int > kgenres ;
    int MAX = 36 ;

    vector<int> g[MAX] ;

    for(int i=0; i< n; ++i) {
        string a, b;
        cin>>a >> b ;
        if( kgenres.find( a ) == kgenres.end() ){
            int id = kgenres.size() ;

            kgenres[ a ] = id ;
        }
        if( kgenres.find( b ) == kgenres.end() ){
            int id = kgenres.size() ;

            kgenres[ b ] = id ;
        }

        values[{kgenres[a] , kgenres[b]}]++;

        g[kgenres[a]].pb( kgenres[b] );
        g[kgenres[b]].pb( kgenres[a] );
    }

    int res = 0 ;

    bool vis[MAX];

    for(int i=0; i< MAX; ++i){
        vis[i]=false ;      
    }

    for(auto e : values ){
        if( !vis[ e.ff.ff ] ){
            vis[ e.ff.ff ] = true ;
            vis[ e.ff.ss ] = true ;
            int cont = values[{ e.ff.ff , e.ff.ss }] ;
            queue< int > cola ;

            cola.push( e.ff.ff ) ;
            cola.push( e.ff.ss ) ;

            


        }
    }



}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
