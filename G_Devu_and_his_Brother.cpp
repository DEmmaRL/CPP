#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

//typedef
typedef long long int lli ;
#define fore(i, a, b) for(int i = (a); i < (b); ++i)
#define pll pair<long long, long long>
#define vll vector<long long>
#define all(a) (a).begin(),(a).end()

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

lli n, m ;

vector<lli>a, b ;

lli fun( lli x){

    lli res = 0 ;

    for(int i=0; i < a.size(); ++i){
        if(a[i] < x ){
            res+=x-a[i];
        }
        else{
            break;
        }
    }

    for(int i=b.size()-1; i >= 0; --i){
        if(b[i] > x ){
            res+= b[i] - x ;
        }
        else{
            break;
        }
    }

   return res ;

}

lli ternary_search(lli l, lli r) {
    lli eps = 1e-9;           
    while (r - l >= 3 ) {
        //cout<<r<<" "<<l<<endl;
        lli m1 = l + (r - l) / 3;
        lli m2 = r - (r - l) / 3;
        lli f1 = fun(m1);      
        lli f2 = fun(m2);     
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    lli tmp = 1e18 ;

    for(int i=l + 1 ; i < r ; ++i){
        tmp= min(tmp , fun(i));
    }
    return min(fun(l) ,  min(fun(r) , tmp) );                    
}

void solve() {
    lli mx = 1e9 , mini = 0 ;
    
    cin>>n >>m;

    fore(i, 0, n){
        lli tmp;
        cin>>tmp;
        a.pb(tmp);
        mini = min(mini, tmp);
        mx = max(mx, tmp);
    }
    fore(i, 0, m){
        lli tmp;
        cin>>tmp;
        b.pb(tmp);
        mini = min(mini, tmp);
        mx = max(mx, tmp);
        
    }
    sort(all(a));
    sort(all(b));

    cout<<ternary_search( mini , mx)<<endl;

}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t = 1;
     //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

}