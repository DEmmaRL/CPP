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
    lli n;
    cin>>n;

    lli dp[n];

    vector<lli>v(n);
    lli res = 0 ; 

    for(int i=0; i< n ; ++i){
        cin>>v[i];
        dp[i]=0;
    }

    for(int i =0; i< n; ++i){
        if( dp[i] == 0 ){
            
            stack<lli> st ;

            dp[i]=v[i];

            lli iter = i + v[i] , c = 0 ;

            while( iter < n ) {

                if( iter < n && dp[iter] != 0 ){
                    c = dp[iter];
                    break;
                }
                st.push( v[iter] );

                iter+= v[iter];

            }

            while( !st.empty() ){
                lli tmp = st.top();
                st.pop();
                iter-=tmp;
                c+=tmp;
                dp[iter]+=c ;
            }
            if(iter < n )
            dp[i]+=dp[iter];
            //cout<<endl;
        }
        //cout<<dp[i]<<" "<<dp[2]<<endl;
    }
    //cout<<endl;

    for(int i=0; i<n; ++i){
        res = max(res, dp[i]);
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
