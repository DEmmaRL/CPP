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