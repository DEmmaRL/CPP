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
    string s;
    cin>>s;

    vector<int>v(n);

    v[0]=0;

    int res = 0 ; 

    for(int i=1; i<n; ++i)
    {
        bool tmp = false ;
        v[i]=0; 

        if(i-1 >= 0 && s[i-1] != '*' )
        {
            tmp = true;
            v[i]=max(v[i], v[i-1]);
        }
        if(i-2 >= 0 && s[i-2] != '*' )
        {
            tmp = true ;
            v[i]=max(v[i], v[i-2]);
        }

        if(!tmp)
            break;

        if(s[i]=='@')
            v[i]++;
        res = v[i];

    }
    cout<<res<<endl;
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