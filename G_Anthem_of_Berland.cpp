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
vector<lli> kmppre(string& t){
  vector<lli> r(t.size() + 1);
  r[0] = -1; int j = -1;
  for(int i=0; i< t.size(); ++i){
    while(j >= 0 && t[i] != t[j])
      j = r[j];
    r[i+1] = ++j;
  }
  return r;
}

// Encontrar t en s
int kmp(string& s, string& t){
    int cont = 0 ;
  int j = 0; vector<lli> b = kmppre(t);
  for(int i=0; i< s.size(); ++i){
    while(j >= 0 && s[i] != t[j])
      j = b[j];
    if(++j == t.size())
      {
        cont++;
        //cout << "Match en index " << i-j+1 << endl;
      }
    j = b[j];
  }
  return cont; 
} 

void solve() {
    string s, t;
    cin>>s>>t;
    if(t.size() > s.size()){
        cout<<0<<endl;
    }
    else{
        int cont = kmp( s, t );
        cout << cont<<endl;
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