#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){

    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){

        lli a, b, n ,s;
        cin>>a>>b>>n>>s;

        lli cur = 0 ;

        if( s / n > a ){
            cur = s - ( a * n ) ;
        } else {
            cur = s % n ;
        }

        if( cur <= b ){
            cout<< "YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }


    }
}