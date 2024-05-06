#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long int lli ;


lli fac(lli n ){

    lli r = 0 ;

    for(int i=1; i <= n ; ++i){
        r+=i ;
    }

    return r ;

}


int main(){
    
    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int k ; 
    cin>>k ;
    string s ;
    cin>>s;

    vector<int> v , sum ;
    
    
    for(int i=0; i< s.size() ; ++i ){
        int cont = 1 ;
        int j = i + 1 ; 

        while(j < s.size() && s[j] == s[i] && s[i] == '0'){
            cont++;
            j++;
        }
        v.pb( s[i] - '0' );

        sum.pb( cont );
        i = j - 1 ;
    }

    if(k == 0){
        //TODO simplemente haz el factorial de todos los ceros
        
        lli res = 0 ;

        for( int i = 0 ; i < v.size(); ++i ){

            if( v[i] == 0 ){
                res+= fac(sum[i]);
            }

        }
        cout<<res<<endl;
        
        return 0 ;
    }

    lli cont = 0 , res = 0 , l = 0 ;

    for( int r = 0 ; r < v.size() ; ++r ){

        if( v[r] == 1 ){
            cont++;

            if( cont > k ){
                    while( cont > k ){
                        cont -= v[l];
                        l++;
                    }
            }
            if( cont == k ){
                lli resto = 0 , a , b ;

                if( r + 1 < v.size() && v[r+1] == 0 ){
                    b = sum[r+1] + 1 ;
                } else {
                    b = 1 ;
                }

                if( v[l] == 0 ){
                    a = sum[l] + 1 ;
                } else if( l - 1 >= 0 && v[l-1] == 0 ){
                    a = sum[l-1] + 1 ;
                } else {
                    a = 1 ;
                }

                resto = a * b ;

                res+=resto;
            }
        } 

    }

    cout<<res<<endl;

    
    
}