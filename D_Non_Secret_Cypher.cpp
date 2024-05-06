#include <bits/stdc++.h>

using namespace std;
typedef long long int lli ;
#define pb push_back

int main(){
    
    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    lli n ,  k ;
    cin>>n>>k;

    vector<lli>v(n);

    map<lli,lli>mapa;
    lli res = 0 ;

    for(int i=0; i<n; ++i ){
        cin>>v[i];
    }

    lli l = 0 , r = 0 ;

    while( r < n ){

        mapa[v[r]]++;

        if( mapa[v[r]] >= k ){

            lli right = n - r ;

            lli left = 1 ;
            //cout<<"en "<<r<<endl;
            if(l <= r)
            {
                //cout<<"ee "<<l<<" "<<r<<endl;
            
            mapa[v[l]]--;
            l++;
            //cout<<r<<endl;
            while( mapa[v[r]] >= k && l <= r ){
                
                left++;

                mapa[v[l]]--;
                l++;
                

            }

            }
            //cout<<" sumamos "<< right*left<<endl;
            res+= left*right ;

        }

        r++;

    }

    cout<<res<<endl;

}