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



void solve() {
    int cont = 0 ; 

    char grid[2][2];
    bool vis[2][2];
    int x = -1 , y = -1 ;

    for(int i =0; i<2; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            vis[i][j]=false;
            cin>>grid[i][j];
            if(grid[i][j]=='#')
            {
                x = i ; 
                y = j;
                cont++;
            }
        }
    }

    int u[4]={0,1,0,-1};
    int d[4]={1,0,-1,0};

    queue<pair<int , int > > cola;

    cola.push({x,y});
    vis[x][y]=true;
    cont--;
    bool res = false ;
    while(!cola.empty())
    {
        pair<int , int> frente = cola.front();

        cola.pop();

        for(int i=0; i<4; ++i)
        {
            if(frente.f + u[i] >= 0 && frente.f + u[i] < 2 &&
            frente.s + d[i] >= 0 && frente.s + d[i] < 2 &&
            !vis[frente.f + u[i]][frente.s + d[i]] &&
            grid[frente.f + u[i]][frente.s + d[i]] == '#' )
            {
                cont--;
                if(cont==0)
                {
                    res = true;
                    break;
                }
                vis[frente.f + u[i]][frente.s + d[i]] = true ;

                cola.push({frente.f + u[i] , frente.s + d[i] });
            }
        }
        if(res)
        break;

    }

    if(res)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
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