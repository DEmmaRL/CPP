#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(lli i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) lli(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

#define INF 1e18

struct LazySegtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, lazy;
    Node(lli s = INF, lli lazy = 0): s(s), lazy(lazy) {}
    Node operator + (const Node &n){
      return Node( min(s , n.s ) );
    }
  };
  vector<Node> st;
  LazySegtree(lli n): st(2 * n) {

  }
  void push(lli u, lli l, lli r){
    if(st[u].lazy){
      if(l < r){
        st[left(u)].lazy += st[u].lazy;
        st[right(u)].lazy += st[u].lazy;
      }
      st[u].s += st[u].lazy ;
      st[u].lazy = 0;
    }
  }
  void update(lli u, lli l, lli r, lli ll, lli rr, lli val){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
    //  cout<<u<<" es "<< st[u].s<<endl;
      //st[u].lazy += val;
      st[u].s += val;
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  void set(lli u, lli l, lli r, lli ll, lli rr, lli val){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
    //  cout<<u<<" es "<< st[u].s<<endl;
      //st[u].lazy += val;
      st[u].s += val;
      if( ll == rr ){
        st[u].s = val ;
      }
      push(u, l, r);
      return;
    }
    set(left(u), l, mid, ll, rr, val);
    set(right(u), mid + 1, r, ll, rr, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(lli u, lli l, lli r, lli ll, lli rr){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};


void solve(){
    lli n; 
    cin>>n;

    vector<lli>v(n);

    LazySegtree tree(n);

    for(lli i=0; i<n ; ++i){
        cin>>v[i];
        tree.set(0,0 , n-1 , i , i , v[i]);
    }

    lli q ;
    cin>>q ; 
    string s ;

    int cont = 1 ;
    getline(cin, s);
    while(q--){
    
      getline(cin, s);

        istringstream iss(s);
        lli l, r, val;
        iss >> l >> r >> val;

        if (iss.fail()) { 
            iss.clear(); 
            iss.seekg(0); 
            iss >> l >> r;
            val = INF;
        }
        //cout<<l<<" "<<r<<" "<< val << endl ;
        lli res = INF ;

        if (val==INF ){
            if (l > r){
            //  cout<<l<<"  a  "<< n-1 << endl ;
                res = min( res , tree.query( 0,  0, n - 1, l, n - 1 ).s  );
                //cout<<res<<endl;
                res = min(res, tree.query(0, 0, n - 1, 0, r).s  );
            } else {
              
              res = min( res , tree.query( 0,  0, n - 1, l, r ).s  );
            }
            //cout <<"#"<<cont<<" : "<< res << " " << l <<" a "<< r << endl;
            cout<<res<<endl;
            cont++;
        } else{ 
            //cout<<endl;
            if (l > r) {
              //cout<<l<<" "<< n-1 <<  " += "<< val << endl ;
              //cout<<0<<" "<< r <<  " += "<< val << endl ;
              
                tree.update( 0, 0, n - 1, l, n - 1, val );
                tree.update( 0, 0, n - 1, 0, r, val );
            } else {
              //cout<<l<<" "<< r <<  " += "<< val << endl ;
              tree.update(0, 0, n - 1, l, r, val);
            }
            /*
            cout<<endl;

            cout<< "------" << endl ;
            cout<<"Sumamos "<< val <<" a ["<< l <<" - "<< r <<"]"<<endl ; 

            for(int i=0; i< n; ++i ){
              cout<<tree.query( 0 , 0 , n-1 , i , i ).s << " " ;
            }
            cout << endl ;
            */
        }
    }
    

}

int main(){
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    IO;
    //lli t; cin>>t; while(t--)
    solve();
    return 0;
}
