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

int n , m;
const int MAXN = (5 * 1e3) + 7 ;
lli INF = 30000;


vector< pair<int, int > > g[MAXN] ; 

lli dist[MAXN];


void bford( int src ){

    fill( dist, dist+n+1, INF ); dist[src] = 0 ;
    fore(_,0,n + 1 ) fore(x,0,n + 1 ) if(dist[x]!=INF)for(auto t: g[x]){
        dist[t.ff] = min( dist[t.ff] , dist[x]+t.ss ) ;
    }

    return ;
}

void solve(){

    cin>>n>>m;

    for(int i=0; i < m ; ++i ){
        char col;
        int a, b, c ;
        cin>>a>>b>>col>>c;

        if(col == 'r') c *= -1;

        g[a].pb({ b , c });

    }

    bford(1);

    for(int i=1; i <= n ; ++i){
        if(dist[i] < 0 )
        cout<<i<<endl;
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
