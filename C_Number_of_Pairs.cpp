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
    int n , l , r ;
    cin>>n>>l>>r;

    vll v(n);

    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
    }
    sort(all(v));

    lli cont = 0 ;

    for( int i = 0 ; i < n ; ++i ){
             
        if( v[ i ] > r ) break ;
        
        int inicio , ending = r - v[ i ] ;

        if( v[ i ] >= l ){
            inicio = 0 ;
        }
        else{
            inicio = l - v[ i ] ;
        }

        int ini = lower_bound( v.begin() + i + 1 , v.end() , inicio ) - v.begin() ;

        if( ini == n ) continue ;

        int fin = upper_bound( v.begin() + i + 1 , v.end() , ending ) - v.begin() ;

        if( fin == n || v[fin] > ending ) fin--;
        
        if( fin - ini >= 0 )
        {
            
            //cout<< "para "<< v[i]<<" buscamos "<< inicio <<" y " << ending<< " encontramos "<<ini<<" y "<<fin<<endl;
            cont += (fin - ini) + 1 ;

        }
    }
    cout<<cont<<endl;

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