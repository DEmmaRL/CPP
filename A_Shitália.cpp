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
#define M_PI 3.14159265358979323846
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

double calcularTercerLado(double a, double b, double X) {
 
    double radianes = X * M_PI / 180.0;
    double c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(radianes));
    
    return c;
}
double height(double a, double h) {
 
    double b = ( h * h ) - ( a * a ) ; 

    return sqrt( b ) ;

}

void solve() {


  double n, R, r ;
  cin >> n >> R >> r ;

  double c1 = calcularTercerLado( r , r , 360 / n ) ;

  double h1 = height( c1 / 2  , r ) ;

  double res1 = ( ( h1 * ( c1 ) ) / 2 ) * n ;

  double c2 = calcularTercerLado( r , R , (360 / n ) / 2 ) ;
  double h2 = height( c1 / 2 , c2 ) ;

  double res2 = ( ( h2 * ( c1 ) ) / 2 ) * n ;

  cout<< setprecision(10) << (res2 + res1) <<endl;

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