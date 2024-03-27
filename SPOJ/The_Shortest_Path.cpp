#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

//typedef
typedef long long int lli ;

//fore
#define fore(i, a, b) for(int i = (a); i <= (b); ++i)


//ESTRUCTURAS
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define mp make_pair

//ABREVIATURAS
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))

#define CODED_BY_DEMMARL ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


//FUNCIONES
lli gcd(lli a,lli b) { if (b==0) return a; return gcd(b, a%b); }
lli lcm(lli a,lli b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(lli a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }



// g++ main.cpp -o a && ./a < in > out

lli INF = 1e18 ;
lli n ;

vector<lli> shortest_path(int ini, int fin , vector<vector<pll>>g)
{
    vector<lli> dist(n+1, INF);
    dist[ini] = 0 ; 

    priority_queue< pll , vector< pll > , greater<pll> > pq ;

    pq.push({ 0 , ini });

    while(!pq.empty())
    {
        pair<lli,lli> cur = pq.top();
        pq.pop();

        if(dist[cur.s] != cur.f)
            continue;
        
        for( auto node : g[ cur.s ] )
        {
            lli nwDist = dist[cur.s] + node.s;

            if(dist[node.f] == INF || dist[ node.f ] > nwDist  ){
                dist[node.f] = nwDist;
                pq.push({ nwDist,node.f });
            }
        }
    }

    return dist;

}


void solve() {
    cin>>n;

    map<string, int> mapa;

    vector< vector < pll > > g(n+1);
    vector<lli> res[n+1];

    for(int i=0; i<n; ++i)
    {
        string s;
        cin>>s;

        mapa[s] = i + 1;

        int k;
        cin>>k;

        for(int j =0 ; j< k; ++j)
        {
            int a, b;
            cin>>a>>b;
            g[i+1].pb({a, b});
            g[a].pb({i+1, b});
        }

    }

    int q;
    cin>>q;

    while(q--)
    {
        string a, b;
        cin>>a>>b;
        int ini = mapa[a] , fin = mapa[b];

        if(res[ini].size() == 0 )
        {
            //busqueda

            res[ini] =  shortest_path(ini,fin, g);
        }
        cout<<res[ini][fin]<<endl;
        
    }
}


int main()
{
    CODED_BY_DEMMARL;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc = 1;
     cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

}