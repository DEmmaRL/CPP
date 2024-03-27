#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

//typedef
typedef long long int lli ;
#define fore(i, a, b) for(lli i = (a); i <= (b); ++i)
#define pll pair<long long, long long>
#define vll vector<long long>
#define all(a) (a).begin(),(a).end()

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// g++ main.cpp -o a && ./a < in > out

int sumaDigitos(int num) {
    int suma = 0;
    while (num != 0) {
        suma += num % 10;
        num /= 10;
    }
    return suma;
}
int sumaDigitosHastaN(int n) {
    int sumaTotal = 0;
    int potencia = 1;
    int sumaParcial = 0;

    vector<lli>v;

    while (n > 0) {
        int tmp = n % 10 , sumaParcial;

        sumaParcial = sumaDigitos(tmp ) ; 
        int extra;
        if(tmp == 0)
        {
            extra = 
        } 

        n /= 10;
        
         
        
        //cout<<sumaParcial<<endl;
        //sumaTotal += sumaParcial;
        //potencia *= 10;
    }

    return sumaTotal;
}

void solve() {
    lli n;
    cin>>n; 

    cout<<sumaDigitosHastaN(n)<<endl;
}


int main()
{
    IO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    lli t = 1;
     cin >> t;
    for (lli i = 1; i <= t; i++) {
        solve();
    }

}