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

    int arr[ n ][ n ] ;

    for(int i=0; i< n ; ++i ){
        arr[i][0] = 1 ;
        arr[0][i] = 1 ;
    }

    int res = 1 ;

    for(int i = 1 ; i < n ; ++i){
        for(int j=1 ; j < n ; ++j){
            arr[i][j] = arr[i-1][j] + arr[i][j-1] ;
            res = max(res , arr[i][j]) ;
        }
    }
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
