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

    lli n , res = 1;
    cin>>n;

    vector<lli>v( n ) ;

    for(int i=0; i<n; ++i){
        cin>>v[i];
    }
    
    sort(all(v));

    v[ ( n - 1 ) / 2 ]++;

    for(int i=  ( n - 1 ) / 2 ; i < n ; ++i ){

        if( i + 1 < n && v[i] > v[i+1] ){
            v[i+1]++;
            res++;
        }
        else{
            break;
        }

    }
    cout<<res<<endl;

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