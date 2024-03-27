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
    vector<int>v(n);

    int ini = 1 , fin = 1 , c = 1 ;
    cin>>v[0];
    for(int i=1; i<n; ++i)
    {
        cin>>v[i];
        if(v[i]==v[0] && c)
        {
            ini++;
        }
        else
        {
            c = 0 ;
        }
    }
    for(int i = n - 2; i>=0 ; --i )
    {
        if( v[i] == v[n-1] )
        {
            fin++;
        }
        else
        {
            break;
        }
    }

    if( v[0] == v[n-1] )
    {
        cout<< max( 0 , n - ( ini + fin ) ) <<endl;
    }
    else
    {
        cout<< n - max( ini , fin ) <<endl;
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