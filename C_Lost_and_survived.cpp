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

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 1e9;

class DisjointSet {
public:
    vector<pair<int, pair<int, int>>> data; // (parent, (min, max))
    vector<int> size;
    map<int,int> componentSizes; // Multiconjunto de tamaños de segmentos

    // Constructor: inicializa el Disjoint Set con n elementos
    DisjointSet(int n) : data(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            data[i] = {-1, {INF, 0}}; // Cada elemento es su propio padre, el mínimo y máximo inicialmente son INF y 0 respectivamente
        }
    }

    // Función para encontrar el representante (root) del conjunto al que pertenece el elemento a
    int find(int a) {
        if (data[a].first != a) {
            data[a].first = find(data[a].first); // Compresión de ruta
        }
        return data[a].first;
    }

    // Función para unir los conjuntos que contienen a y b
    void join(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a == root_b) return; // Ya están en el mismo conjunto

        // Union by size
        if (size[root_a] < size[root_b]) {
            swap(root_a, root_b);
        }

        componentSizes[size[root_a]]--;
        componentSizes[size[root_b]]--;
        if( componentSizes[size[root_a]] == 0 )
        {
            componentSizes.erase(componentSizes.find( size[ root_a ] ) );
        }
        if( componentSizes[size[root_b]] == 0 )
        {
            componentSizes.erase(componentSizes.find( size[ root_b ] ) );
        }

        data[root_b].first = root_a; // Se hace que root_b sea hijo de root_a
        size[root_a] += size[root_b]; // Se actualiza el tamaño del conjunto de root_a

        componentSizes[size[root_a]]++;
        /*cout<<"-----------------"<<endl;
        for( auto e : componentSizes )
        {
            cout<<e.first<<" -> "<<e.second<<endl;
        }
        cout<<"-----------------END"<<endl;
        */
    }

    // Función para obtener el máximo valor en el conjunto al que pertenece a
    int fmaximo(int a) {
        int root = find(a);
        data[root].second.second = max(data[root].second.second, a); // Actualiza el máximo si es necesario
        return data[root].second.second;
    }

    // Función para obtener el mínimo valor en el conjunto al que pertenece a
    int fminimo(int a) {
        int root = find(a);
        data[root].second.first = min(data[root].second.first, a); // Actualiza el mínimo si es necesario
        return data[root].second.first;
    }

    // Función para insertar un nuevo elemento al conjunto
    void insert(int a) {
        if (data[a].first == -1) { // Si no tiene padre, se establece como su propio padre
            data[a].first = a;
            componentSizes[1]++;
        }
    }

    // Función para obtener el tamaño del conjunto al que pertenece a
    int connectedComponents(int a) {
        return size[find(a)];
    }

    // Función para obtener el tamaño del conjunto con la mayor cantidad de componentes
    int getMaxComponentSize() {
        auto maxim = componentSizes.rbegin(); // El tamaño más grande está en la parte posterior del mapa
        return maxim->first ;
    }
    

    // Función para obtener el tamaño del conjunto con la menor cantidad de componentes
    int getMinComponentSize() {
        auto minimum = componentSizes.begin(); // El tamaño más pequeño está al principio del mapa
        return minimum->first ;
        
    }
};


void solve() {
    int n, q;
    cin>>n>>q;

    DisjointSet dsu = DisjointSet(n+1);

    for(int i = 1 ; i <= n ; ++i )
    {
        dsu.insert(i);
    }

    while(q--)
    {
        if( n == 1 )
        {
            cout<<0<<endl;
        }
        else{
            int a, b;
            cin>>a>>b;
            dsu.join(a, b);
            cout<<dsu.getMaxComponentSize() -dsu.getMinComponentSize()<<endl;
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