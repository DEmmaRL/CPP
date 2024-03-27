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

    vector<int >v(n);

    for(int i = 0 ; i < n ; ++i ){
        cin>>v[i];
    }

    bool res = true ;

    for( int i = 0 ; i < n ; ++i ){
        if( v[ i ] != 0 ){

            if( i + 2 >= n ){
                res = false ;
                break ;
            }

            if( v[ i + 1 ] - ( v[i] * 2 ) < 0 ){
                res = false ;
                break;
            }
            else{
                v[i + 1 ] -= v[ i ] * 2 ;
            }

            if( v[ i + 2 ] - ( v[i] ) < 0 ){
                res = false ;
                break;
            }
            else{
                v[i + 2 ] -= v[ i ] ;
            }

        }
    }

    if(res){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


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