#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

void solve(){
    string s;
    cin>>s;

    if( s[0] =='0' && s[1]!='0'){
        cout<<s<<" AM"<<endl;
    }else if( s[0] =='0' && s[1]=='0'){

        cout<<12;

        for(int i=2; i < s.size(); ++i ){
            cout<<s[i];
        }
        cout<<" AM"<<endl;
    }else if( s[0] =='1' && s[1]=='2'){
        cout<<s<<" PM"<<endl;
    }
    else{
        string tmp = "";
        tmp+=s[0];
        tmp+=s[1];
        int n = stoi(tmp);

        if(n < 12 ){
            cout<<s<<" AM"<<endl;
        }else{
            n-=12;
            tmp = "";
            if( n < 10 ){
                tmp += '0';
            }
            tmp+= to_string(n);
            cout<<tmp;
            for(int i=2; i < s.size(); ++i ){
                cout<<s[i];
            }
            cout<<" PM"<<endl;
        }
    }
}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
