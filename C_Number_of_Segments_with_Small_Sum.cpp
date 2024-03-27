#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

//typedef
typedef long long int lli ;
#define fore(i, a, b) for(lli i = (a); i <= (b); ++i)
#define pll pair<long long, long long>
#define vll vector<long long>
#define all(a) (a).begin(),(a).end()

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

void solve() {
    lli n  , k;
    cin>> n >> k ;
    vector<lli> v( n ) ;
  
    for(lli i = 0 ; i < n ; ++i ){ cin >> v[ i ] ; }

    lli l = 0 , r = 0 , x = 0  , res = 0 ;

    for( r = 0 ; r < n ; ++r )
    {

        x+=v[r];

        while( x > k  )
        {
            x-=v[l];
            l++;
        }
        if( x <= k )
            res+= r - l + 1 ;
    }

    cout<< res << endl ;
    
}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    lli t = 1;
     //cin >> t;
    for (lli i = 1; i <= t; i++) {
        solve();
    }

}