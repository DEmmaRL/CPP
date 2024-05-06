#include <bits/stdc++.h>

using namespace std;
typedef long long int lli ;
#define pb push_back

const int MAX = 1e5 + 7 ;

int countingSort[MAX];

int main(){
    
    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    lli n ,  q ;
    cin>>n>>q;

    vector<int>v(n);

    for(int i=0; i < n; ++i ){

        cin>>v[i];
        if(v[i] <= n ){
            countingSort[ v[i] ]++;
        }
    }
    vector<int>tmp(n+1);

    vector<pair<int, vector<int> > > dp ;

    for(int i=1 ; i <= n; ++i ){
        if(  countingSort[ i ] >= i ){
            tmp[0]=0;

            for(int j=1; j <= n ; ++j){
                tmp[j] = tmp[j-1];
                if( v[j-1] == i ){
                    tmp[j]++;
                }
            }
            dp.push_back( { i , tmp } );
        }
    }

    while(q--){

        int l , r ;
        cin>>l>>r;
        int res = 0 ;
        
        for(auto &e: dp ){

            if( e.second[r] - e.second[l - 1 ] == e.first ){
                res++;
            }

        }

        cout<<res<<endl;
        
    }


}