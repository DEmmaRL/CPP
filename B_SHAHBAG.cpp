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
const int INF = 1e9 ;
class DisjointSet {
public:
    vector<int> parent, minimo, maximo, size ;
    int cont  ;

    DisjointSet(int n) : parent(n), minimo(n), maximo(n), size(n, 1) {
        cont = 0 ;
        for (int i = 0; i < n; i++) {
            parent[i] = -1 ;
            minimo[i] = INF;
            maximo[i] = 0;
        }
    }

    void join(int a, int b) {
        int find_a = find(a), find_b = find(b);
        minimo[find_a] = min(minimo[find_a], a);
        maximo[find_a] = max(maximo[find_a], a);

        minimo[find_b] = min(minimo[find_b], b);
        maximo[find_b] = max(maximo[find_b], b);

        minimo[find_a] = min(minimo[find(a)], minimo[find(b)]);
        maximo[find_a] = max(maximo[find(a)], maximo[find(b)]);

        parent[find(b)] = find(a);
        if(find_a != find_b)
        size[find_a] += size[find_b];
    }

    int fmaximo(int a) {
        maximo[find(a)] = max(maximo[find(a)], a);
        return maximo[find(a)];
    }
    int fminimo(int a) {
        minimo[find(a)] = min(minimo[find(a)], a);
        return minimo[find(a)];
    }

    int find(int a) {
        if(parent[a]==-1)
        {
            return -1 ;
        }
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    
    }
    void insert(int a)
    {
        parent[a] = a ;
        int tmp = 0 ;
        if( a - 1 >= 1 && parent[a-1] != -1 )
        {
            join(a, a-1);
            tmp++;
        }
        if( a + 1 < parent.size() && parent[a+1] != -1 )
        {
            join(a, a+1);
            tmp++;
        }
        if(tmp == 0 )
        {
            cont++;
        }
        else if(tmp == 2)
        {
            cont--;
        }

    }

    int connectedComponents(int a) {
        return size[find(a)];
    }
};

void solve() {
    int n;
    cin>>n;
    DisjointSet dsu = DisjointSet( 2e4+7 ) ;

    
    while(n--)
    {
        int a ;
        cin >> a ;
        dsu.insert(a);
        cout<<dsu.cont<<endl;
    }
    cout<<"Justice"<<endl;
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