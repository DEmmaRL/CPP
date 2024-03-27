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

lli f( lli a , lli b , lli x , lli y , lli n ){

    lli res = max(  a - n , x  ) ;

    if(res != a - n){
        n -= a - x ;
    } else {
        n = 0 ;
    }

    res*= max( b - n , y ) ;

    return res ;

}

void solve() {

    lli x, y, a, b , n ;
    cin >> a >> b >> x >> y >> n ;

    lli res = min( f( a , b , x , y ,  n ) , f( b , a , y , x ,  n ) ) ;
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