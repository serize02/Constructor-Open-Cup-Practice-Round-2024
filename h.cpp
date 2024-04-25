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
const int MAX = 1e3+5;
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

vector<int> p;
bitset<MAX> mark;

inline void sieve(){
    for(int i = 2; i < MAX; i++){
        if(not mark[i]){
            p.push_back(i);
            for(int j = 2*i; j < MAX; j+=i){
                mark[j] = true;
            }
        }
        
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    sieve();
    test(){
        int n, x;
        cin >> n >> x;
        vector<int> ans;
        ans.push_back(x);
        for(auto i: p){
            if(i == x) continue;
            ans.push_back(i*x);
            if(ans.size() == n) break;
        }
        for(auto i: ans) cout << i << " ";
        cout << "\n";
        
    }
    return 0;
}