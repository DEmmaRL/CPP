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

// g++ main.cpp -o a && ./a < in > out


lli n;
vector< vector<pll> > up, down ;

vector<bool>vis;
lli INF  = 1e18 ;

void shortest_path(int ini, int fin)
{
    vector<lli> dist( n+1 , INF ) ;
    vector<lli> padre( n+1 , INF ) ;
    dist[ini] = 0 ;
    priority_queue< pair<lli , pair<lli, lli> > , vector<pair<lli , pair<lli, lli> > > , greater<pair<lli, pair<lli, lli>>>> pq;

    pq.push({0,{ini, 0 }});
    pq.push({0,{ini, 1 }});

    while(!pq.empty())
    {
        pll cur = {pq.top().f , pq.top().s.f};
        lli estado = pq.top().s.s;

        pq.pop();
        if(dist[cur.s] != cur.f) continue;

        for(auto node : up[cur.s])
        {
            lli nwDist = dist[cur.s] ;

            if(estado == 0)
                nwDist++;

            if( dist[node.f] == INF or (dist[node.f] > nwDist) )
            {
                padre[node.f] = cur.s;
                dist[node.f] = nwDist;
                pq.push({nwDist , {node.f , 1 } });
            }
        }

        for(auto node : down[cur.s])
        {
            lli nwDist = dist[cur.s] ;

            if(estado == 1)
                nwDist++;

            if( dist[node.f] == INF or (dist[node.f] > nwDist) )
            {
                padre[node.f] = cur.s;
                dist[node.f] = nwDist;
                pq.push({nwDist , {node.f , 0 } });
            }
        }
    }
    if(dist[fin] != INF)
    cout<<dist[fin]<<endl;
    else
    cout<<-1<<endl;
}

void solve() {
    cin>>n;
    lli m;
    cin>>m;

    up.resize(n+1);
    down.resize(n+1);

    for(int i=0; i<m; ++i)
    {
        lli a, b;
        cin>>a>>b;
        up[a].pb({b, 0});
        down[b].pb({a, 0});
    }
    int ini, fin;
    cin>>ini>>fin;
    shortest_path(ini, fin);
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