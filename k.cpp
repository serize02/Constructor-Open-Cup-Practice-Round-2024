#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define compress_id(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define lowbit(x) x&(-x)
#define pb push_back
#define f first
#define s second
#define test() int t; cin >> t; for(;t;t--)
#define sz(x) (int)x.size()
#define cyes cout << "YES\n"
#define cno cout << "NO\n" 

using namespace std;

using ull = unsigned long long;
using ld = long double;
using point = complex<double>;
const int MAX = 1e6+5;
const int INF = (1<<30);
const int mod = 1e9+7;
const double pi = acos(-1);

inline int pow_mod(int a, int n){
    int ans = 1;
    for(;n ;n >>= 1){
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
    }
    return ans;
}

int st[MAX];

inline void upd(int node, int l, int r, int x, int v){
    if(l > x or r < x) return;
    if(l == r){
        st[node] = v;
    }
    else{
        int mid = (l+r)>>1;
        upd(2*node,l,mid,x,v);
        upd(2*node+1,mid+1,r,x,v);
        st[node] = max(st[2*node], st[2*node+1]);
    }
}

inline int qry(int node, int l, int r, int x, int y, int v){
    //cout << "node: " << node << "\n";
    if(r < x or l > y){
        //cout << "out of range\n";
        return 0;  
    } 
    if(l == r){
        if(st[node] >= v) return l;
        return 0;
    } 
    else{
        int mid = (l+r)>>1;
        if(st[node] < v) return 0;
        int a = qry(2*node+1,mid+1,r,x,y,v); 
        if(a) return a;
        else return qry(2*node,l,mid,x,y,v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            upd(1,1,q,i,x);
        }
        else{
            int y, k;
            //cout << "query " << i << "\n";
            cin >> y >> k;
            int mx = q;
            vector<int> ans;
            for(int j = 0; j < k and mx; j++){
                int id = qry(1,1,q,1,mx,y);
                if(id == 0) break;
                ans.push_back(id);
                mx = id-1;
            }
            cout << ans.size() << "\n";
            for(auto j: ans) cout << j << " ";
            cout << "\n";
        }
    }
    //cout << "ok";

    return 0;
}