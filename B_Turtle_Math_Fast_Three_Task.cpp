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
    cin>>n;

    map<int , int>mapa;

    for(int i=0; i<n; ++i)
    {
        int tmp;
        cin>>tmp;
        if(tmp%3)
        {
            mapa[tmp%3]++;
            total+= ( tmp % 3 ) ;
        }
    }

    if(mapa.size() == 0 || total && total%3 == 0 )
    {
        cout<<0<<endl;
    }
    else if(n == 1 )
    {
        cout<<1<<endl;
    }
    else
    {
        total%=3;
        if( total == 1 )
        {
            if( mapa.find(1) !=mapa.end() )
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
        }
        else
        {
            cout<<1<<endl;
        }
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