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
    lli n ;
    cin>>n ;
    vector <lli> v(n) , dp(n);

    lli  res = 0 , total = 0 ;

    for( int i = 0 ; i < n ; ++i ){
        cin>> v[ i ] ;
        dp[ i ] = 0 ;
        total += v[ i ] ;
    }

    if( total % 3 != 0 ){
        
        cout << 0 << endl ;
        return ;
    }

    lli p = total / 3 , c = 0 ;

    if( v[ n - 1 ] == p ){
        dp[ n - 1 ] = 1 ;
    }else{
        dp[ n - 1 ] = 0 ;
    }
    c+=v[n-1];

    for( int i = n - 2 ; i >= 0 ; --i ){
        c += v[ i ] ;
        
        dp[i] = dp[ i + 1 ] ;
        if( c == p ){
            
            dp[ i ]++ ;
            
        }
    }
    c = 0 ;

    for(int i = 0 ; i < n - 2 ; ++i ){
        c+= v[ i ] ;
        if( c == p ){
            res += dp[ i + 2 ] ;
        }
    }

    cout << res << endl ;
}   

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
