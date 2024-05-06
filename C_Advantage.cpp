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
#define INF  1e9
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

void solve(){

    int n;
    cin>>n;
    vector<int>v(n);

    int min1 = - INF, min2 = - INF;

    for(int i=0; i < n; ++i ){
        cin>>v[i] ;

        if(v[i] > min1){
            min2 = max(min2, min1);
            min1 = v[i];
        }else{
            min2 = max( min2, v[i] ) ;
        }
    }

    for(int i=0; i<n; ++i){
        if( v[i] < min1 || min2 == -INF )
        cout<<v[i] - min1<<" ";
        else
        cout<<v[i] - min2 <<" ";
    }
    cout<<endl;


}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
