#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

//typedef
typedef long long int lli ;
#define fore(i, a, b) for(int i = (a); i < (b); ++i)
#define pll pair<long long, long long>
#define vll vector<long long>
#define all(a) (a).begin(),(a).end()

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

void solve() {
    lli n, k ;
    cin>>n>>k;

    vector<lli> v ( n ) ;

    fore( i , 0 , n ){
        cin>>v[i];
    }

    lli res = 0 , l = 0 , r = 0 , c = 0 ;

    while( r >= l && r < n ){

        while( r < n && c < k ){
            c += v[ r ] ;
            r++;
        }

        if( c >= k ){
         //   cout<<l<<" "<<r<<endl;

            lli cont = 1 + ( n - ( r  ) ) , tmp = 1 ;

            while( l < r && c - v[l] >= k ){
                c-=v[l];
                l++;
                tmp++;
            }
          // cout<<cont<<" "<<tmp<<endl;

            res+= cont * tmp ;

            if( l + 1 < n ){
                c -= v[ l ] ;
                l++;
            }else{
                break;
            }


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
     //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

}