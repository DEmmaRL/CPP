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
    lli n, m ;
    cin>>n>>m;
    map< lli , lli > mapa ;

    vector<int>v(n) , b(m), tmp(m);
    
    for(int i=0; i<n; ++i){
        cin>>v[i];
    }
    sort(all(v));
    for(int i=0; i<m; ++i){
        cin>>b[i];
        tmp[i]=b[i];
    }

    sort(all(b));
    
    lli iter = 0 , cont = 0 ;

    for( int i = 0 ; i< m ; ++i )
    {
        while( iter < n && v[iter] <= b[i] ){
            iter++;
            cont++;
        }        
        mapa[b[i]]= cont ;
    }

    for(int i =0; i< m; ++i){
        cout<<mapa[tmp[i]]<<" ";
    }
    cout<<endl;

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