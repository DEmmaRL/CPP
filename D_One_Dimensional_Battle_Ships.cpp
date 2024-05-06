#include <bits/stdc++.h>
#define ss second
#define ff first
#define pb push_back
#define INF 1e9
typedef long long int lli ;

using namespace std;

bool f( lli lim , lli k , lli sz ){

    if( ( k * sz ) + k - 1 <= lim ){
    
        //cout<<k<<" barcos caben en "<< lim<<endl;
        return true ;
    } else {
        return false ;
    }
}

lli binary_search( lli space , lli sz ){

 //  cout<<space<<" a "<<sz<<endl;

    if(sz == 0) return 0 ;

    lli l = 0 , r = INF ;

    while( r - l > 2 ){
        lli mid = r+ l ;
        mid/=2;

        if( f( space, mid , sz ) ){
            l = mid ;
        } else {
            r = mid - 1 ;
        }
    }   
   // cout<<l<<" e "<< r<<endl;

    for(lli i= r ; i >= l ; --i ){
        if( f( space , i , sz ) ) {
            //cout<<i<<endl; 
            return i ;
        }
    }
    return 0 ;

}

void solve(){

    lli n; 
    cin>>n;

    set<lli>st;

    st.insert(0);
    st.insert(n + 1 );

    lli k, a ;
    cin>>k>>a;

    lli total = binary_search( n , a) ;

    lli q;
    cin>>q;
    for(lli i=1; i<=q; ++i){
        lli p ;
        cin>>p;
        if(st.find(p) == st.end() ){
            st.insert(p);

            auto iter = st.find(p);

            auto piter = *prev(iter),  niter = *next( iter ) ;
            

           // cout<< piter <<" "<< *iter <<" "<< niter <<endl;

            lli izq = (p - piter) - 1 ;
            lli der = ( niter - p ) - 1 ;

            //cout<<izq<<" "<<der<<endl;

            lli block = binary_search(( niter - piter ) - 1 , a ) ;

            if(block > 0 )
                total-= block ;

            if( izq > 0 )
                total += binary_search( izq , a ) ;
            
            if( der > 0 )
                total += binary_search( der , a ) ;
        
       //     cout<<block<<" "<< binary_search( izq , a ) << " " << binary_search( der , a ) << endl;
        }
        if(total < k){
            cout<<i<<endl;
            return ;
        }        


    }
    cout<<-1<<endl;

}


int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    while(t--){
        solve();
    }

}