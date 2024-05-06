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
     cin>> n ;

     lli cont = 0 ;

     vector< int > v(n);

    for(int i=0; i <n ; ++i ){
        cin>>v[i];
    }

    bool res = true ;

    for( int i = 0 ; i < n ; ++i ){
        cont+=v[i];
        v[i]=0;

        if(i-1 >= 0 ){
            if( v[i-1] + 1 <= cont ){
                v[i] = v[i-1] + 1 ;
                cont -= v[i];
            }
            else{
                res = false ;
                break;
            }
        }
    }
    if(res){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
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
