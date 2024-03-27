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
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

//ABREVIATURAS
#define all(a) (a).begin(),(a).end()
#define clr(x) memset(x, 0, sizeof(x))

#define CODED_BY_DEMMARL ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// g++ main.cpp -o a && ./a < in > out
const int MOD = 32768 ;

int bfs( int n ){
    if(n==0)
    {
        cout<<"0 ";
        return 0 ;
    }

    vector<int>dist(MOD+1);
    vector<bool>vis(MOD+1);

    queue<int>cola;

    cola.push(n);

    vis[n]=true;
    dist[n]=0;

    while(!cola.empty())
    {
        int frente = cola.front();
        cola.pop();
        //cout<<frente<<endl;

            if(!vis[(frente +1 ) % MOD  ] )
            {
                vis[(frente+1)%MOD] = true;
                dist[(frente+1)%MOD] = dist[frente]+1;
                cola.push((frente+1)%MOD);
                if((frente+1)%MOD == 0 )
                {
                    break;
                }
            }

            if(!vis[(frente *2 ) % MOD  ] )
            {
                vis[(frente*2)%MOD] = true;
                cola.push((frente*2)%MOD);
                dist[(frente*2)%MOD] = dist[frente]+1;
                if((frente*2 )%MOD == 0 )
                {
                    break;
                }
            }
    }

    cout<<dist[0]<<" ";

    return 0 ;
}


void solve() {

    int n;
    cin>>n;
    vector<int>v(n);

    for( int i =0; i<n; ++i )
    {
        cin>>v[i];
        bfs(v[i]) ;
        
    }

    

    
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