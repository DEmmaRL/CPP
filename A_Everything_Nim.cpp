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

    vector<lli> v(n) ;
    set<lli>st ;
    fore(i , 0 , n){
        cin>>v[i];
        st.insert(v[i]);
    }

    lli resto = 0 ;

    int winner = 0 ;

    for(auto e : st ){

        if( e <= resto ){
            continue; 
        }
        winner = abs(winner) - 1 ;
        resto+= e - resto ;
    }

    if(winner){
        cout<<"Alice"<<endl;
    } else {
        cout<<"Bob"<<endl;
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
