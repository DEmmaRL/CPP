#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

//typedef
typedef long long int lli ;
#define fore(i, a, b) for(int i = (a); i <= (b); ++i)
#define pll pair<long long, long long>
#define vll vector<long long>
#define all(a) (a).begin(),(a).end()

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

void solve() {
    
    int n;
    cin>>n;
    
    vector<lli>v(n) , tmp ;
    
    for(int i=0; i<n; ++i){
        cin>>v[i];
    }

    bool res = true ;
    tmp.pb(v[n-1]);
    for(int i=n-2; i>=0; --i){
        if( v[i] > tmp[tmp.size()-1] ){
            
            tmp.pb( v[i]%10 );
            tmp.pb( v[i]/10 );
           
        }
        else{
            tmp.push_back(v[i]);
        }
    }


    cout << (is_sorted( tmp.rbegin() , tmp.rend() ) ? "YES" : "NO") << endl;

}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t = 1;
     cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

}