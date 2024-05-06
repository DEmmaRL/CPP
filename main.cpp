#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define INF 1e9
// g++ main.cpp -o a && ./a < in > out

int main()
{
    int t;
    cin>>t;
    while ( t-- )
    {
        int n;
        cin>>n;

        map<int , int> mapa ;

        for(int i=0; i < n ; ++i ){
            int tmp;
            cin>>tmp;

            mapa[tmp]++;
        }

        int cont = 0 ;

        for(auto e : mapa){
            cont+=e.second / 3 ;
        }

        cout<<cont<<endl;
    }
    
}
