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

int lim1 ,  lim2  , MOD = 100000000 ;

int mem[101][101][ 11 ][ 11 ] ;

int dp( int n1 , int n2 , int k1, int k2 ){
    //cout<< n1 << " " << n2 <<endl;
    int ans =  0 ;
    if( n1 && k1 < lim1 && n1 - 1 >= 0 && 
            mem[n1 - 1 ][n2][k1 + 1 ][ 0 ] == -1 ){
        mem[ n1 - 1 ][ n2 ][ k1 + 1 ][ 0 ] = (  dp( n1 - 1 , n2 , k1 + 1 , 0 ) ) % MOD  ;
        ans = ( mem[ n1 - 1 ][ n2 ][ k1 + 1 ][ 0 ]  + ans ) % MOD ;
    }
    else if( n1 && k1 < lim1 && n1 - 1 >= 0 && 
            mem[n1 - 1 ][n2][k1 + 1 ][ 0 ] != -1 ){
        ans = ( mem[ n1 - 1 ][ n2 ][ k1 + 1 ][ 0 ]  + ans ) % MOD ;        
    }
    if( n2 && k2 < lim2 && n2 - 1 >= 0 && 
            mem[ n1 ][ n2 - 1 ][ 0 ][ k2 + 1 ] == -1 ){
        mem[ n1 ][ n2 - 1 ][ 0 ][ k2 + 1 ] = (  dp( n1 , n2 - 1 , 0 , k2 + 1 ) ) % MOD  ;
        ans = ( mem[ n1 ][ n2 - 1 ][ 0 ][ k2 + 1 ]  + ans ) % MOD ;
    }
    else if( n2 && k2 < lim2 && n2 - 1 >= 0 && 
            mem[ n1 ][ n2 - 1 ][ 0 ][ k2 + 1 ] != -1 ){
        ans = ( mem[ n1 ][ n2 - 1 ][ 0 ][ k2 + 1 ]  + ans ) % MOD ;        
    }

    if( n1 == 0 && n2 == 0 ){
        return 1 ;
    }
    return ans ;
}

void solve() {
    memset( mem , -1 , sizeof( mem ) );
    lli n1 , n2 ; 
    cin >> n1 >> n2 >> lim1 >> lim2 ;

    cout<< dp( n1, n2, 0 , 0 ) ;
}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t = 1;
     //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

}