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

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out



void solve() {
    int n;
    cin>>n;

    vector<int>v(n+1);

    int cont = 0 ;

    for(int i=1 ; i <= n ; ++i){
        int tmp;
        cin>>tmp;
        if(tmp == i ){
            cont++;
        }
    }

    if(cont%2){
        cont++;
    }
    cout<<cont/2<<endl;
}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t = 1;
     cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

}