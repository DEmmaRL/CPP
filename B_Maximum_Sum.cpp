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

const int MOD = 1e9 + 7 ;

void solve(){

    lli n , k;

    cin>>n >>k ;

    vector<lli>v(n) , dp(n);

    fore(i,0,n){
        cin>>v[i];
    }

    lli res = max( (lli)0 , v[0]) , curr = 0 , total = v[0] , extra;

    dp[0]= (v[0] ) % MOD;
    for(int i=1; i< n ; ++i){

        total = (total + v[i] ) ;

        dp[i] = max( ( v[i] ) , ( v[i] + dp[i-1]) ) ;
        res = max(dp[i], res) ;
    }
    extra = res ;

    for(int i=0; i < k ; ++i){
    
        total = (total + extra + MOD ) % MOD  ;

       // cout<<total<<endl;

        extra= (extra + extra + MOD ) % MOD ;

    }

    

    
    cout<<total<<endl;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
