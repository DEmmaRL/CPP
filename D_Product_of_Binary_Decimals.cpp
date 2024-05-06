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

const int MAX = 1e5 + 11 ;

vector<int>dp;

vector<bool>res(MAX);

void f( int n ){
    dp.pb( n );
    if( n * 10 < MAX ){
        f( n * 10 );
    }
    if( (n * 10) + 1 < MAX ){
        f( (n * 10) + 1 );
    }
}   

void solve(){
    int n ;
    cin>>n;
    if(res[n]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    f(1);

    res[1] = true ;
    for( auto e : dp ){
        if(e==1) continue ;

        for(int i = 1 ; i < MAX; ++i){
            if( res[i] ){
                if( i * e < MAX ){
                    res[i*e]=true ;
                }
                else{
                    break;
                }
            }
        }

    }

    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
