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

lli n; 
vector< vector< pair<lli , lli> > > g ;

vector<bool>vis;

lli INF = 1e18;

void shortest_path()
{
    vector<lli> dist(n , INF);
    vector<lli> padre(n , INF);
    dist[0]=0;
    priority_queue<pair<lli , lli>, vector<pair<lli , lli > >, greater<pair<lli , lli >  >  > pq;

    pq.push({0,0});
    while(!pq.empty())
    {
        pair<lli , lli> cur = pq.top();
        pq.pop();
        if(dist[cur.s] != cur.f)
        continue;
        for( auto node : g[cur.s] )
        {
            lli nwDist = dist[cur.s] + node.second;


             if( dist[node.f] == INF or (dist[node.f] > nwDist) ){
                
                padre[node.f] = cur.s;

                dist[node.f] = nwDist;
                pq.push({nwDist,node.f});
             }

        }
    }

    lli curr = n - 1 , f = 0; 
    
    if(dist[n-1]==INF)
    {
        cout<<-1<<endl;
    }
    else
    {
        vector<lli>res;
        while( padre[curr] != INF )
        {
            res.pb( curr+1 ) ;
            curr = padre[ curr ] ;
        }
        res.pb(1);
        //SI QUIERES EL RECORRIDO DEL CAMINO MÁS CORTO
        for(lli i=res.size()-1; i >= 0 ; --i)
        {
            cout<<res[i]<<" ";
        }
        //SI QUIERES EL TAMAÑO DEL CAMINO MÁS CORTO
        cout<<endl;
        cout<<dist[n-1]<<endl;
        
    }
    

    /*for(lli i=0; i<n; ++i)
    {
        cout<<i+1<<" "<<dist[i] << " " << padre[ i ] +1<<endl;
    }]*/

}

void solve() {
    cin>>n;
    lli m;
    cin>>m;

    g.resize(n);

    for(lli i=0; i < m; ++i)
    {
        lli a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].pb({ b, c });
        g[b].pb({ a, c });
    }

    shortest_path();


}


int main()
{
    CODED_BY_DEMMARL;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc = 1;
     //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

}