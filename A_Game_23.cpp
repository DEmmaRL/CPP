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

lli n , m , res = -1 ;

void f( lli k , lli cont = 0 ){

    if( res != -1 ) return ;

    if(k == m ){
        res = cont ;
        return ;
    }

    if( k * 2 <= m ){
        f( k* 2 , cont + 1 );
    }
    if( k * 3 <= m ){
        f( k* 3 , cont + 1 );
    }

}

void solve(){
    
    cin>>n >>m ;

    f(n);

    cout<<res<<endl;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
