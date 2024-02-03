#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
// g++ main.cpp -o a && ./a < in > out

int main()
{
    int n, m;
    cin>>n>>m;
    
    vector<pair<int , int> >v;
    
    if(n <= m)
    {

        for( int i = 1 ; i <= m ; ++i )
        {
            v.pb(make_pair( 1, i ) );
        }
        for(int i=2; i <= n; ++i)
        {
            v.pb(make_pair( i, 1 ) );
        }   
    }
    else
    {
        for( int i = 1 ; i <= n ; ++i )
        {
            v.pb(make_pair( i, 1 ) );
        }
        for(int i=2; i <= m; ++i)
        {
            v.pb(make_pair( 1, i ) );
        }
    }
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); ++i)
    {
        cout<<v[i].f<<" "<<v[i].s<<endl;
    }
}