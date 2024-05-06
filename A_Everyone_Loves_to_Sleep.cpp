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
    int n , h, m ;
    cin>>n>>h>>m;

    vector<pii> v(n);

    for(int i=0; i<n; ++i){
        int a, b;
        cin>>a>>b;
        v[i] = {a,b};
    }

    sort(all(v));
    
    bool res = false ;

    pii k ;

    for(int i=0; i<n; ++i){
        if( v[i].ff > h ){
            k = v[i];
            res = true ;
            break;
        }
        else if( v[i].ff == h && v[i].ss >= m ){
            k = v[i];
            res = true ;
            break;
        }
    }
    int total = 0 ;
    if(!res){
        k = v[0];
        total += 24 * 60 ;

        total-= (h * 60) + m ;

        total+= (k.ff * 60 ) + k.ss ;

        cout<<total/60<<" "<<total%60<<endl;
    } else {
        total = (k.ff * 60 ) + k.ss ; 
        total -= ( h * 60 ) + m ; 
        cout<<total/60<<" "<<total%60<<endl;
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
