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

    string s ;
    cin>>s;

    lli res = 1e8 ;

    queue<string > cola ;

    cola.push(s);

    while(  !cola.empty()  ){

        string f = cola.front();
        cola.pop();

        lli tmp = stoll(f);

        if(tmp%25==0){
            
            res = min( (lli)( s.size() - f.size() ) , res );

        } else if( f.size() > 2 ){

            if( !(f[ f.size() - 1 ] == '0' &&  ) && f[ f.size() - 2 ] != '5' && 
                    f[ f.size() - 2 ] != '7' && f[ f.size() - 2 ] != '0' ){

            }

        }

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
