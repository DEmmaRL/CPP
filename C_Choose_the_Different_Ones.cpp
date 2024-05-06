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
    
    int n, m, k;
    cin>>n>>m>>k;

    set<int>a, b;

    for(int i=0; i<n; ++i){
        int tmp;
        cin>>tmp;

        a.insert( tmp ) ;
    }

    for(int i=0; i<m; ++i){
        int tmp;
        cin>>tmp;

        b.insert( tmp ) ;
    }

    int cont1 = 0 , cont2 = 0 , extra = 0 ;

    bool res = true ;

    for(int i=1; i <= k ; ++i ){

        if( a.find( i ) != a.end() && b.find( i ) != b.end() ){
            extra++;
        }
        else if( a.find( i ) != a.end() ){
            cont1++;
        }
        else if( b.find( i ) != b.end() ){
            cont2++;
        }
        else{
            res = false ;
            break;
        }
    }

    if( res && cont1 <= k/2 && cont2 <= k/2 ){
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
