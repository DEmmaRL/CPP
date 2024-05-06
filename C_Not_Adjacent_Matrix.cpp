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

int adjx[4]={0,1,-1,0};
int adjy[4]={1,0,0,-1}; 

void solve(){
    int n; 
    cin>>n;

    if(n == 2 ){
        cout<<-1<<endl;
        return ;
    }
    if(n == 1 ){
        cout<<1<<endl;
        return ;
    }

    vector<vector<int> > v(n);

    int cur = 1 ;
    vector<int>w, b ;
    for(int i=0; i < n; ++i ){
        for(int j=0; j < n; ++j ){
            v[i].pb(cur);

            if( (i + j + 2) % 2 ){
                b.pb(cur);
            } else {
                w.pb(cur);
            }

            cur++;
        }   
    }
    int cont = 0 , tmp = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j <n; ++j){
            if( cont < b.size() && tmp == 0 ){
                v[i][j] = b[cont]; 
            } else if(tmp == 0) {
                tmp = 1 ;
                cont = 0 ;
            }
            
            if( cont < w.size() && tmp == 1 ){
                v[i][j] = w[cont]; 
            }
            cont++;
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j <n; ++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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
