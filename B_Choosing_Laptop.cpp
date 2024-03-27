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

struct pc{
    int speed, hdd, ram, price;
    bool aval = true ;

};

void solve() {
    int n;
    cin>>n;

    vector<pc>v(n);

    for(int i=0; i<n; ++i)
    {
        cin>>v[i].speed>>v[i].ram>>v[i].hdd>>v[i].price;
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if( v[i].speed < v[j].speed && v[i].ram < v[j].ram && v[i].hdd < v[j].hdd )
            {
                v[i].aval = false ;
                break;
            }            
        }
    }

    int iter = 0 , res = 1e9 ;

    for(int i=0; i<n; ++i)
    {
        if(v[i].aval && v[i].price < res)
        {
            res = v[i].price;
            iter = i + 1 ;
        }
    }

    cout<<iter<<endl;



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