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
    lli n, a , b; 
    cin>>n>>a>>b;

    lli res = a * n ;

    for(lli i = 0 ; i < n && i * 2 <= n ; ++i ){
        res = min(res , ( b * i ) + (a * ( n - ( i * 2 ) ) ) ) ;
    }

    cout << res << endl ;
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
