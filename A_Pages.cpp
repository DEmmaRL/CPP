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
    int n, m, k;
    cin>>n>>m>>k;

    if(m-k > 1)
    {
        cout<<"<< ";
    }

    for(int i= max(m - k, 1) ; i < m; ++i )
    {
        cout<<i<<" ";
    }
    cout<<"("<<m<<") ";
    for(int i= m + 1 ; i <= min(k + m, n); ++i )
    {
        cout<<i<<" ";
    }
    if( k + m < n)
    {
        cout<<">>"<<endl;
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