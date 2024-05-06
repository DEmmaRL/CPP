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
    lli n , a, b, c ;
    cin >> n >> b >> c ;

    map<lli , lli> mapa , mapa2;

    vector<lli> v(n * n) ;

    for(int i=0; i < n *n ; ++i){
        lli tmp ;
        cin>>tmp ;
        v[i] = tmp ;
        mapa[tmp]++;
    }
    
    sort(all(v));
    a = v[0] ;
    lli cont = 0  , tmp = a ;

    queue<lli>cola; 

    for(int i=0; i< n ; ++i){
        //cout<<tmp<<endl;
        cola.push( tmp );
        mapa2[tmp]++;
        tmp += b ; 
    }

    for(int i = 0 ; i < n - 1 ; ++i ){

        for( int j = 0 ; j < n ;++j ){
            lli r = cola.front();
            r += c ;
            cola.pop();
            mapa2[r]++;
            cola.push(r);
            //cout<<r<<endl;
        }
    }

    bool res = true ;

    for( auto e : mapa ){
        if(e.ss != mapa2[e.ff]){
            res = false;
            break ;
        }
    }
    if(res){
        cout<<"YES"<<endl;
    }else{
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
