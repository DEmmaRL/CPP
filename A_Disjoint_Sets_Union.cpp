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

class DisjointSet{ 
    public:

    vector<int> parent;

    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }

    void join(int a, int b) { parent[find(b)] = find(a); }

    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b){ return find(a) == find(b); }
};

void solve() {
    int n , m ;
    cin >> n >> m ;

    DisjointSet dsu = DisjointSet( n + 1 ) ;

    while(m--)
    {
        string s;
        cin>>s;

        int a, b;
        cin>>a>>b;

        if(s == "union")
        {
            dsu.join( a , b );
        }
        else
        {
            if( dsu.find( a ) == dsu.find( b ) )
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
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