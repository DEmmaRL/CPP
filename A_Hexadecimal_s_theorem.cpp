#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
// g++ main.cpp -o a && ./a < in > out

int main()
{
    ios_base :: sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    set<int>st;

    int lim = 1e9+7;

    vector<int>v;
    v.pb(0);
    v.pb(1);

    while( v[v.size()-1] < lim )
    {
        v.pb(v[v.size()-1] + v[v.size()-2] );
    }

    for(int i=0; i<v.size(); ++i)
    {
        st.insert(v[i]);
    }

    bool aux = false;
    vector<int>res;

    int n;
    cin>>n;

    for(int i=0; i<v.size(); ++i)
    {
        if(v[i]>n || aux)
            break;

        int total = v[i];

        for(int j=0; j<v.size(); ++j)
        {
            if( total + v[j] > n || aux )
            break;

            if( st.find( n - (total + v[j]) ) != st.end() )
            {
                aux = true ;
                res.pb( v[i] );
                res.pb( v[j] );
                res.pb( n - (total + v[j]) );                
            }
        }
    }

    if(aux)
    {
        for(int i=0; i<res.size(); ++i)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"I'm too stupid to solve this problem"<<endl;
    }


}