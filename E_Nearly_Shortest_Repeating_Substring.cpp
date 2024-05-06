#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
string s ;

int f( string& tmp , int ini , int fin ){
    int cont = 0 , iter = 0 ;
    for(int i = ini ; i < fin ; ++i){
        if( s[i]!= tmp[ iter ] ){
            cont++;
        }
        iter++;
    }
    return cont ;

}
void solve(){
    int n;
    cin>>n ;

    int minimo = n ;
    
    cin>>s;

    vector<int>v ;

    for(int i=1 ; i * i <= n ; ++i){
        if( n % i== 0 ){
            v.pb(i);
            if(n/i != i && n/i != n ){
                v.pb(n/i);
            }
        }
    }

    sort( all(v) );

    for(auto e : v ){

        int aux = 0;

        string tmp = "" , other = "";

        for(int i=0; i < e ; ++i){
            tmp+= s[i];
        }

        lli cont = 0 ;

        for(int i = 0  ; i < s.size() ; i+= e ){

            lli c = f( tmp ,  i , i + e );
            
            cont+=c;

            if( c == 1 && other.size() == 0 ){
                for(int j=i ; j < i + e ; ++j ){
                    other+=s[j];
                }
                aux = 1 ;
            } else if( c && cont > 1 ){
                aux = c ;
                break ;
            }

        }

        if( cont <= 1 ){
            minimo = e ;
            break;
        }
        else if( other.size()!= 0 ){
            cont = 0 ;
            for(int i = 0  ; i < s.size() ; i+= e ){

                lli c = f( other ,  i , i + e );
                
                cont+=c;

                if( c && cont > 1 ){
                    aux = c ;
                    break ;
                }

            }

            if( cont <= 1 ){
                minimo = e ;
                break;
            }
        }   

    }
    cout<<minimo<<endl;

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
