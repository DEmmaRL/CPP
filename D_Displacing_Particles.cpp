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
    lli n, x, y;
    cin>>n>>x>>y;
    
    lli res = 1 ;

    for( int i = 1 ; i <= n - 1 ; ++i ){
        res *= 2 ;
    }

    lli extra = 1 ;

    for( int i = 1 ; i <= n ; ++i ){
        extra *= 2 ;
    }

    queue< pair <lli , lli > > cola ;

    cola.push( { res , 0 } );

    while( true ){

        pair< lli , lli > frente = cola.front() ;
        cola.pop();

        if( frente.f == x ){
            cout<<frente.s ;
            return ; 
        }
        else{

            cola.push( { frente.f / 2 , frente.s + 1 } );
            cola.push( { (frente.f + extra ) / 2 , frente.s + 1 } );

        }



    }   

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