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
    int n ;
    cin>>n;

    vector<string>v( ( n * 2 ) + 1 );

    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            v[i]+='0' + j ;
        }
        for(int j=i-1; j>=0; --j)
        {
            v[i]+='0' + j ;
        }
    }
    int cont = n + 1 ;
    for(int i=n-1; i>=0; --i)
    {
        for(int j=0; j<=i; ++j)
        {
            v[cont]+='0' + j ;
        }
        for(int j=i-1; j>=0; --j)
        {
            v[cont]+='0' + j ;
        }
        cont++;
    }
    int tam = (n*2) + 1  + ( n * 2 );
    cont = 0 ;
    for(auto e : v)
    {
        for(int i =0; i< (tam - e.size())/2 ; ++i)
        {
            cout<<" ";
        }
        for(int i=0; i<e.size(); ++i)
        {
            cout<<e[i];
            if( i + 1 < e.size() )
            {
                cout<<" ";
            }
        }
        cout<<endl;
        if(cont < n)
        tam-=2;
        else
        {
            tam+=2;
        }
        cont++;
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