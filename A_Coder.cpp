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
    int n , res = 0 ;
    cin >> n ;
    char arr[ n ][ n ] ;

    for( int i = 0 ; i < n ; ++i )
    {
        for( int j = 0 ; j < n ; ++j )
        {
            if( ( j - 1 < 0 || j - 1 >= 0 && arr[ i ][ j - 1 ] != 'C' ) &&
                ( i - 1 < 0 || i - 1 >= 0 && arr[ i - 1 ][ j ] != 'C' ) )
            {
                res++;
                arr[i][j]='C';
            }
            else
            {
                arr[i][j]='.';
            }
        }
    }
    cout<<res<<endl;
    for( int i = 0 ; i < n ; ++i )
    {
        for( int j = 0 ; j < n ; ++j )
        {
            cout<<arr[i][j];
        }    
        cout<<endl;
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