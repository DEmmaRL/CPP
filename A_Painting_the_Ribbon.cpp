#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main(){
    
    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t ; 
    cin>>t ;

    while(t--){

        int n, m , k;
        cin>>n>>m>>k;

        int extra = ( n / m ) ;
        if(n%m)
            extra++; 

        if( k + extra >= n ){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }

    }
    
}