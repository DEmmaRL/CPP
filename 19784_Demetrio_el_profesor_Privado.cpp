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
    lli n, q ;
    cin>>n>>q ;

    map<lli , lli > mapa ;
     
    while(q--){
        lli a , b ;
        cin>>a>>b;

        mapa[a]+=b;
    }

    lli sum = 0 , mx = 0 ; 

    for(auto e : mapa){
        sum+=e.ss;
        mx = max(mx , e.ss ) ;
    }

    cout<<sum<<" "<<mx<<endl ;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
