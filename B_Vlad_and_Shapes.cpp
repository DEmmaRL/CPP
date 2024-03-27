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

    string v[n];

    int arr[n][n];

    int ini = -1 , fin = -1 ;

    for(int i=0; i<n; ++i)
    {
        cin>>v[i];

        for(int j=0; j< n; ++j)
        {
            arr[i][j]=v[i][j]-'0';

            if(ini == -1 && arr[i][j] == 1 )
            {
                ini = i ; 
                fin = j ;
            }
        }

    }


    int iter = ini , x = 0 , y = 0 , x1 = 0 , y1 = 0 ;
    while(iter < n && arr[iter][fin] == 1 )
    {
        iter++;
        x++;
    }
    iter = fin;
    while(iter < n && arr[ini][iter] == 1 )
    {
        iter++;
        y++;
    }
    y--;
    x--;

     //cout<< ini << " "<<x<<endl;
    if( x == y && arr[ini][fin + x] == 1 && arr[ini + x][fin] == 1 && arr[ini+ x ][fin + x] == 1  )
    {
        cout<<"SQUARE"<<endl;
    }
    else
    {

        cout<<"TRIANGLE"<<endl;
    }
    

    bool res = false;

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