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

int gcd( int a , int b ){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a ;
}

void solve(){
    int n;

    cin>>n;
    vector<int>v , o;

    for( int i = 0 ; i < n ; ++i ){
        
        int tmp;
        cin>>tmp;

        if(tmp%2==0){
            o.pb(tmp);
        }else{
            v.pb(tmp);
        }

    }

    lli res = 0 ;

    for(int i=0; i < o.size(); ++i){
        res+= ( o.size() - ( i + 1 ) ) + v.size() ;
    }

    for(int i=0; i< v.size() ; ++i){
        for(int j=i+1; j< v.size() ; ++j){
            if(gcd(v[i] , 2 * v[j]) > 1 ){
                res++;
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
