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
    int n, h, w ;
    cin>>w>>h>>n;

    set<lli>x, y ;
    x.insert( 0 );
    x.insert( w );
    y.insert( 0 );
    y.insert( h );

    map<lli, lli> ladox, ladoy ;

    ladox[w]++;
    ladoy[h]++;

    lli tmp , horizontal = w , vertical = h ;

    for(int i=0; i < n; ++i){
        string s; 
        cin>>s;
        
        cin>>tmp;

        if(s == "V"){
            x.insert( tmp ) ;

            auto it = x.find( tmp ) ;

            lli anterior = *prev( it ) ;
            lli siguiente = *next( it ) ;

            

            ladox[ siguiente - anterior ]--;

            if( ladox[ siguiente - anterior ] == 0 ){
                ladox.erase(siguiente - anterior);
            }

            ladox[ tmp - anterior ]++;
            ladox[ siguiente - tmp ]++;

            pair<lli , lli> aux = *ladox.rbegin() ;

            horizontal = aux.first ;

        } else{
            y.insert( tmp ) ;

            auto it = y.find( tmp ) ;

            lli anterior = *prev( it ) ;
            lli siguiente = *next( it ) ;

            //cout<<anterior <<" e "<< siguiente <<endl;

            ladoy[ siguiente - anterior ]--;

            if( ladoy[ siguiente - anterior ] == 0 ){
                ladoy.erase(siguiente - anterior);
            }

            ladoy[ tmp - anterior ]++;
            ladoy[ siguiente - tmp ]++;

            pair<lli , lli> aux = *ladoy.rbegin() ;

            vertical = aux.first ;

        }

        cout<<horizontal*vertical<<endl;

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
