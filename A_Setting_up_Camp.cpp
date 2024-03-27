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
    lli a, b, c , cont = 0 ;

    cin>>a>>b>>c;

    cont += a ;

    cont+= b/3;

    b%=3;

    if( b && 3 - b - c <= 0 ){
        c-= 3 - b ;
        b=0;
        cont++;
    }else if( b ){
        cout<<-1<<endl;
        return ;
    }

    cont+= c/3;

    c %= 3 ;

    if(c) cont++;

    cout<<cont<<endl;


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