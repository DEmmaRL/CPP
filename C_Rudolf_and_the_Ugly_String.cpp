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
    int n , total = 0 ;
    cin >> n ;
    string s ; cin >> s ;
    for(int i = 0 ; i < s.size() ; ++i ){
        
        if( s[ i ] == 'm' && i + 4 < n ){
            if( s[ i + 1 ] == 'a' && s[ i + 2 ] == 'p' && s[ i + 3 ] == 'i' && s[ i + 4 ] == 'e' ){
                total++ ;
                i = i + 3 ;
                continue;
            }
        }
        if( s[ i ] == 'm' && i + 2 < n ){
            if( s[ i + 1 ] == 'a' && s[ i + 2 ] == 'p' ){
                total++ ;
                i = i + 1 ;
            }
        }
        if( s[i]== 'p' && i + 2 < n ){
            if( s[ i + 1 ] == 'i' && s[ i + 2 ] == 'e' ){
                total++ ;
                i = i + 1 ;
            }
        }

    }
    cout << total << endl ;

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