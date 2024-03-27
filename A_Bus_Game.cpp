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
    int n, m;
    cin>>n>>m;

    int res = -1 , curr = 0;
    while(res==-1)
    {
        if(curr == 0 )
        {
            int resto = 220;
            while( n>=1 && resto >20 )
            {
                n--;
                resto-=100;
            }
            if(resto)
            {
                if( m >= (resto / 10) )
                {
                    m-=(resto/ 10);
                    
                }
                else
                {
                    res = 1;
                    break;
                }
            }
        }
        else
        {
            int resto = 220;
            
            if( m >= 22 )
            {
                resto = 0 ;
                m-=22;
            }
            else if( m >= 12 && n >= 1 )
            {
                m-=12;
                n--;
            }
            else if( m >= 2 && n >=2 )
            {
                n-=2;
                m-=2;
            }
            else
            {
                res = 0 ;
                break;
            }
        }


        curr = abs(curr - 1 );
    }

    if(!res)
    {
        cout<<"Ciel"<<endl;
    }
    else
    {
        cout<<"Hanako"<<endl;
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

