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

vector<int> prefixFunction(string s) {
 int n = s.length();
 vector<int> p(n);
 p[0] = 0;
 for (int i = 1; i < n; i++) {
   p[i] = 0;
   int j = p[i - 1];
   while (j > 0 && s[j] != s[i]) {
     j = p[j - 1];
   }
   if (s[j] == s[i]) {
     p[i] = j + 1;
   }
 }
 return p;
}

vector<int> findMatches(string s, string t) { // s = largest string , t = substring 
 int n = s.length(), m = t.length();
 string c = s + "$" + t;
 vector<int> p = prefixFunction(c), ans;
 for (int i = n + 1; i <= n + m; i++) {
   if (p[i] == n) {
     ans.push_back(i - 2 * n);
   }
 }
return ans;
}


void solve() {
    string s;

    string t;
    cin>>s;
    t = "fix" ;

    vector<int>v = prefixFunction( s);

    for(int i=0; i<v.size(); ++i)
    {
        cout<<v[i]<<endl;
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