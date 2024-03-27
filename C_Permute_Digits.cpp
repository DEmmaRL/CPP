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
#define rall(a) (a).rbegin(),(a).rend()

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

void solve() {
    string a, b;
    cin>>a>>b;

    if(a.size() < b.size()){
        sort(rall(a));

        cout<<a<<endl;
    } else {
       map<int , int>mapa ;

       for(int i=0; i< a.size(); ++i ){
        mapa[a[i] - '0']++ ;
       }
//98598771
       string res = "";

       bool aux = false , lim = 0 ;

       for( int i=0; i<b.size() ;++i ){
        int tmp = b[i]-'0' ;
        if( tmp == 0 ){            
            if( mapa[tmp] >= 1 ){
                res+=(char)( tmp + '0' );
                mapa[tmp]--;
            }else {
                    for(int j=res.size()-1; j >= 0 ; --j){
                        mapa[res[j]-'0']++;
                        int o = res[j]-'0' - 1;

                        while(o>=0 && !(mapa[o] >= 1 ) ){
                            o--;
                        }

                        if( o >= 0 ){
                            mapa[o ]--;
                            res[ j ] = (char)(o + '0');
                            
                            while( res.size() != j + 1 ) {
                                res.pop_back();
                            }

                            break ;
                        }

                    }
                    aux = true ;
                    break;
                }

        }
        else
        {
            if( mapa[tmp] >= 1 ){
                res+=(char)( tmp + '0' );
                mapa[tmp]--;
            }else{
                
                while( tmp >= 0 && !( mapa[ tmp ] >= 1 ) ){
                    tmp--;
                }
                if( tmp >= 0 ){
                    res+=(char)( tmp + '0' );
                    mapa[ tmp ]--;
                    aux = true ;
                    break;
                } else {
                    for(int j=res.size()-1; j >= 0 ; --j){
                        mapa[res[j]-'0']++;
                        int o = res[j]-'0' - 1;

                        while(o>=0 && !(mapa[o] >= 1 ) ){
                            o--;
                        }

                        if( o >= 0 ){
                            mapa[o ]--;
                            res[ j ] = (char)(o + '0');
                            
                            while( res.size() != j + 1 ) {
                                res.pop_back();
                            }

                            break ;
                        }

                    }
                    aux = true ;
                    break;
                }
            }
        }

       }
       string tmp = "";

       if(aux){

            

            for(auto e : mapa){
                for(int i = 0 ; i < e.s ; ++i )
                    tmp += e.f + '0' ;
            }

            sort(rall(tmp));

            

        }

        cout<<res<< tmp<<endl;
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