#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){

        string a , b;
        cin>> a >> b;

        bool tmp = true ;

        for(int i=0; i<a.size(); ++i){
            if( a[i] != b[i] ){

                if( tmp ){
                    if(a[i] < b[i])
                    swap(a[i],b[i]);
                    tmp = false ;
                } else if( a[i] > b[i] ){
                    swap(a[i],b[i]);
                } 

            }
        }
        cout<<a<<endl;
        cout<<b<<endl;



    }
}