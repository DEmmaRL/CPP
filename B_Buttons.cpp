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
    
    lli n, total = 0 , k = 0 ;
    cin>>n;

    if(n==1)
    {
        cout<<1<<endl;
    }
    else 
    {
        for(int i=n; i>1; --i)
        {
            
            //cout<<"ssz";
            if(i!=n)
            {
                total++;

                total += i-1 + ( ( i-1 ) * ( n - i ) ) ;
            }
            else
            {
                total+=i;
            }
            k++;
        }
        total++;
        
    cout<<total<<endl;
    }
    

}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t = 1;
     //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

}