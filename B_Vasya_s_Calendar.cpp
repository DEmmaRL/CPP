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
    lli k;
    cin>>k;

    lli n  ;
    cin>>n;
    vector<lli>v(n);

    cin>>v[0];

    lli res = 0 ;

    for(int i=0; i<n; ++i)
    {
        cin>>v[i];
        if(i+1 < n)
        {
            res+=k - v[ i ] ;
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