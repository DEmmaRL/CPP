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
#define INF 1e9 

struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, mx , l , r, t ;
    Node(lli s = 0, lli mx= -INF , lli l = 0 , lli r = 0 , lli t = 0 ): s(s), mx(mx) , l(l) , r(r) , t(t) {}
    Node operator + (const Node &n){

        int tt = t + n.t  , ll = r , rr = n.l ;
        //cout<<ll<<endl ;
        int tmp = min( r , n.l ) ;

        tt += tmp ;
        ll -= tmp ;
        rr -= tmp ;
        
        rr += l ;
        ll += n.r ;

      return Node(s + n.s, max(mx, n.mx ) , ll , rr , tt );
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val , int  ll , int tt , int rr ){ // O(logN)
    if(l == r){
      st[u].s = val;
      st[u].mx = val;
      st[u].l = ll ;
      st[u].r = rr ;
      st[u].t = tt ;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val , ll , tt , rr  ) ;
    else update(right(u), mid + 1, r, kth, val , ll , tt , rr );
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};

void solve(){
    string s ;
    cin>>s;
    int n = s.size() ;

    Segtree tree( s.size() );

    for(int i=0; i < s.size(); ++i ){

        if( s[i] == ')' ){
        //    tree.update(i , { 0 , 0 , 1 } ) ;
            tree.update(0, 0, n - 1, i, 1 , 0 , 0 , 1 );

        } else {
        //    tree.update(i , { 1 , 0 , 0 } ) ;
            tree.update(0, 0, n - 1, i, 1 , 1 , 0 , 0 );
        }

    }
    int q ;
    cin>>q;
    while(q--){
        int l , r  ;
        cin>>l>>r ;
        l--;
        r--;
        cout << tree.query(0, 0, n - 1, l , r ).t * 2 << endl ;
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
