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

lli gcd( lli a, lli b ){
    if(b==0) return a ;

    return gcd(b,a%b) ;
}

void solve(){

    int n ;
    cin>>n;

    int res = 0 , cur = 0 ;

    for(int i=1; i < n ; ++i){
        
        int tmp = gcd(n, i) + i;

        if( tmp > cur ){
            res = i ;
            cur = tmp ;
        }
    }
    cout<<res<<endl;
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
