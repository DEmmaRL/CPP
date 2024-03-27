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
    int n, m;
    cin>>n>>m;

    vector<string>v(n);

    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
    }

    map <int , int> mapa;

    for(int i=0; i<m; ++i)
    {
        vector<pll> res ;
        for(int j=0; j<n; ++j)
        {
            res.pb({ v[j][i], j });
        }

        sort(all(res));

        int maximo = res[res.size()-1].f , iter = res.size()-1 ;

        while( iter>= 0 && res[iter].f == maximo )
        {
            mapa[res[iter].s]++;
            iter--;
        }
    }
    cout<<mapa.size()<<endl;
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