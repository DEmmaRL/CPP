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

    int cont = 1 ;

    vi v(n) ;

    for(int i =0; i < n; ++i ){
        cin>>v[i];
    } 
    sort(all(v));

    for(int i=n-1; i >= 0 ; --i){
        if( v[i] <= i + 1 ){
            cont = i + 2 ; break ;
        }
    }

    cout << cont << endl ;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
