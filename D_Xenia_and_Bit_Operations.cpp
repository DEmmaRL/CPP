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
#define INF 1e9
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

/*
001
110
011
101

*/

struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
        lli s, op ;
        Node(lli s = 0 , lli op = -1 ):s(s), op(op){}
        Node operator + (const Node &n){
            //cout<<"sumamos: "<< s<<" + " <<n.s<<" "<<n.op<<endl;
            if( op == -1 && n.op == -1 ){
                return Node(0, -1 );
            }
            
            if(op == -1 ){
                return Node( n.s , 0 ); ;
            }else if( n.op == -1 ){
                return Node( s , 0 ); 
            }
            if( op == 0 ){
              //  cout <<"e "<<endl;
                return Node( s | n.s , 1 );
            }
            return Node( s ^ n.s , 0 );
        } 
    };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].s = val;
      st[u].op = 0;
      return;
    }
    
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};

void solve(){

    lli n = 1 , m , q ;
    cin>>m>>q;

    for(int i=0; i<m; ++i ){
        n*=2;
    }

    Segtree tree( n ) ;

    for(int i=0; i<n; ++i){
        int k;
        cin>>k;

        tree.update(0,0,n-1, i, k);
    }

    while(q--){
        lli a, b;

        cin>>a>>b;
        a--;

        tree.update(0, 0, n-1 , a , b ) ;

        cout<<tree.query(0, 0, n-1, 0, n-1).s << endl ;
        
    }


}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
