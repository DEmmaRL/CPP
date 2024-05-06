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

    int n ;
    cin>>n ;

    int res = 0 ;

    vector<int>a(n), b(n);

    for(int i=0; i<n; ++i){
        cin>>a[i];
    }

    for(int i=0; i<n; ++i){
        cin>>b[i];
    }

    int r = 0 ;

    for(int l=0; l < n; ++l ){

        if( a[l] <= b[r] ){
            r++;
        } else if(r < n ){
            //cout<<l<<" "<<r<<endl;

            while( r < n && a[l] > b[r]){
                r++;
                res++;
              //  cout<<"ahora es "<<res<<endl;
            }
            //cout<<endl;
            //cout<<a[l ]<<"es menor que "<<b[r]<<endl;
            if( r < n ){
                r++;
            }

 //           cout<<l <<" == "<<r<<endl;

            if( r >= n){
                break;
            }

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
