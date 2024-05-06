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

bool check( vector< vector<char>  >& v , int x , int y  ){
    bool aux = true ;

    if( x == 0 && y == 0 ){
        return true ;
    }

    if( x - 2 >= 0 ){
        if( v[x-2][y] =='#' ){
            return false ;
        }
        if( v[x-1][y] =='#' ){
            return false ;
        }
    }

    if( y - 1 >= 0 ){
        if( v[x][y - 1] =='#' ){
            return false ;
        }
        if( y - 2 >= 0 && v[x][y - 2 ] =='#' ){
            return false ;
        }
    }

    return aux ; 
}

void solve(){
    int n;
    cin>>n;

    vector<vector< char  > > arr(n * 2);

    for(int i=0; i < n * 2; ++i){
     for(int j=0; j < n * 2; ++j){
            arr[i].pb('.');
        }   
    }

    for(int i=0; i < n * 2; ++i){
     for(int j=0; j < n * 2; ++j){
            if( arr[i][j] == '.' && check( arr , i, j ) && i + 1 < n * 2 && j + 1 < n*2 ){
                
                arr[i][j]='#';
                arr[i+1][j]='#';
                arr[i][j+1]='#';
                arr[i+1][j+1]='#';
            }
        }   
    }

    for(int i=0; i < n * 2; ++i){
     for(int j=0; j < n * 2; ++j){
            cout<<arr[i][j];
        }   
        cout<<endl;
    }
    


}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
