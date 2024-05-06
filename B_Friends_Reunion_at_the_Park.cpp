#include <bits/stdc++.h>

using namespace std;

#define pb push_back

struct LCA{
    vector<int> height, euler, first, segtree;
    vector<bool>visited;

    int n ;
    LCA( vector<vector<int>> &adj , int root = 0 ){
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n,false);
        dfs(adj, root);
        int m = euler.size() ;
        segtree.resize(m*4); 
        build(1,0,m-1);
    }

    void dfs( vector<vector<int>> &adj , int node, int h = 0 ){
        visited[node] = true ;
        height[node] = h ;
        first[node] = euler.size();
        euler.push_back( node );
        for(auto to : adj[node]){
            if(!visited[to]){
                dfs( adj, to, h+1 );
                euler.push_back(node);
            }
        }
    }

    void build( int node , int b ,int e ){
        if( b == e ){
            segtree[node] = euler[b];
        } else {
            int mid = (b+e) / 2 ;
            build( node << 1 ,b , mid );
            build( node << 1 | 1 , mid + 1 , e );
            int l = segtree[node << 1], r = segtree[node << 1 | 1 ] ;

            segtree[node] = (height[l] < height[r]) ? l : r ;
        }
    }
    int query(int node, int b , int e, int L, int R){
        if(b > R || e < L)
            return -1 ;
        if( b >= L && e <=R)
            return segtree[node]; 
        int mid = (b+e) >> 1 ;

        int left = query( node << 1 , b , mid , L, R );
        int right = query( node << 1 | 1 , mid + 1 , e, L , R );
        if(left == -1 ) return right ;
        if(right == -1 ) return left ;
        return height[left] < height[right] ? left : right ;
    }

    int lca( int u, int v){
        int left = first[u] , right = first[v] ;
        if(left > right)
            swap(left, right);
        return query(1,0, euler.size() - 1 , left , right);
    }
};

int main(){
    
    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n  ;
    cin>>n;
    //cout<<n<<endl;

    vector<vector<int> > adj(n + 1 ) ;
    
    for(int i = 0 ; i < n - 1 ; ++i){
  
        int a, b ;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    int root = 0 ;

    for(int i = 1 ; i <= n; ++i ){
        if(adj[i].size() == 1 )
            {
                root = i ;
                break ;
            }
    }

    vector<int> dist(n + 1 ); 
    vector<bool> vis( n + 1 ) ;
   
    for(int i=0 ; i <= n ; ++i){
        vis[i]=false;
    }
    vis[root] = true ;
    dist[root] = 0 ;

    queue<int>cola ;
    cola.push(root);

    while(!cola.empty()){
        int frente = cola.front();
        cola.pop();
        for(auto e : adj[frente]){
            if(!vis[e]){
                vis[e] = true ;
                dist[e] = dist[frente] + 1 ;
                cola.push(e);
            }
        }
    }

    int q ;
    cin>>q;

    LCA tree( adj , root );
    
    while(q--){

        int res = 1e9 ;
        
        int a, b , c ;
        cin>>a>>b >> c ;

        int cont = 0 ;

        int tmp = tree.lca(a,b) ;

        cont = max(abs( dist[tmp] - dist[ a ] ) , abs( dist[tmp] - dist[ b ] ) )  ; 

        int other = tree.lca( tmp , c );

        int band =abs( dist[other] - dist[ tmp ]  ) + abs( dist[other] - dist[ c ]  ) ;
        
        band = ( band/ 2 ) + (band%2) ;

        cont = max(cont,  band ) ;

        res = min(res, cont) ;



        cont = 0 ;

        tmp = tree.lca(a,c) ;

        cont = max(abs( dist[tmp] - dist[ a ] ) , abs( dist[tmp] - dist[ c ] ) )  ; 

        other = tree.lca( tmp , b );

        band =abs( dist[other] - dist[ tmp ]  ) + abs( dist[other] - dist[ b ]  ) ;
        
        band = ( band/ 2 ) + (band%2) ;

        cont = max(cont,  band ) ;

        res = min(res, cont) ;


        cont = 0 ;

        tmp = tree.lca(b,c) ;

        cont = max(abs( dist[tmp] - dist[ b ] ) , abs( dist[tmp] - dist[ c ] ) )  ; 

        other = tree.lca( tmp , a );

        band =abs( dist[other] - dist[ tmp ]  ) + abs( dist[other] - dist[ a ]  ) ;
        
        band = ( band/ 2 ) + (band%2) ;

        cont = max(cont,  band ) ;

        res = min(res, cont) ;

        cout<<res<<endl;
    
    }


    
}